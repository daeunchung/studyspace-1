/********** 동적인 웹페이지 만들기 ***********/

var http = require('http');     // 프로토콜
var fs = require('fs');         // file system
var url = require('url');
var qs = require('querystring');

// REFACTORING
var template = {
  HTML:function(title, list, body, control){
    return `
    <!doctype html>
    <html>
    <head>
      <title>WEB1 - ${title}</title>
      <meta charset="utf-8">
    </head>
    <body>
      <h1><a href="/">WEB</a></h1>
      ${list}
      ${control}
      ${body}
    </body>
    </html>
    `;
  },
  list:function(filelist) {
    var list = '<ul>';
    var i = 0;
    while(i < filelist.length){
      list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li>`;
      i++;
    }
    list = list + '</ul>';
    return list;
  }
}

// query string 값에 따라서 본문이 변경되는 웹 애플리케이션 만들기  => query string에 따라 다르게 동작하는 nodejs application 만들기

// nodejs로 웹브라우저가 접속이 들어올 때마다 nodejs가 createServer에 콜백함수를 호출
var app = http.createServer(function(request,response){
    // func(r,r)는 createServer 전달된 callback 함수이며 request는 웹브라우저가 요청 보낸 정보, response는 웹브라우저에게 응답할때 주는 정보
    var _url = request.url;      // domain name:port/ 여기부터 뒷부분을 가져온다
    var queryData = url.parse(_url, true).query;
    var pathname = url.parse(_url, true).pathname;

    if(pathname === '/'){
        if(queryData.id === undefined){         // localhost:3000/ 인 경우
          fs.readdir('./data', function(error, filelist) {
            var title = 'Welcome';
            var description = 'Hello, Node.js';
            var list = template.list(filelist);
            var html = template.HTML(title, list,
              `<h2>${title}</h2><p>${description}</p>`,
              `<a href="/create">create</a>`
            );
            response.writeHead(200);
            response.end(html);
          });
        }else{                                  // localhost:3000/?id=SOMETHING 인 경우
          fs.readdir('./data', function(error, filelist) {
            fs.readFile(`data/${queryData.id}`, 'utf8', function(err, description) {  // 원래는 function(err, data)받는데 어짜피 받은 data 본문에 넣어줄꺼라서 미리 description(본문)으로 받은 것
            var title = queryData.id;
            var list = template.list(filelist);
            var html = template.HTML(title, list,
              `<h2>${title}</h2><p>${description}</p>`,
              `<a href="/create">create</a>
               <a href="/update?id=${title}">update</a>
               <form action="delete_process" method="post">
                  <input type="hidden" name="id" value="${title}">
                  <input type="submit" value="delete">
                </form>
               `
            );
              response.writeHead(200);
              response.end(html);
            });
          });
        }
    }
    else if(pathname === '/create'){
      fs.readdir('./data', function(error, filelist) {
        var title = 'Web - create';
        var list = template.list(filelist);
        var html = template.HTML(title, list, `
          <form action="/create_process" method="post">
            <p><input type="text" name="title" placeholder="title"></p>
            <p>
              <textarea name="description" placeholder="description"></textarea>
            </p>
            <p>
              <input type="submit">
            </p>
          </form>
          `, '');
        response.writeHead(200);
        response.end(html);
      })
    }else if(pathname === '/create_process'){
      // request로 보내는 데이터가 너무 클 경우, 컴퓨터 다운 or 무리가 가기에 request내용을 끊어 끊어 body로 보내준다
      // 서버 쪽에서 조각조각씩 수신할 때마다 서버는 콜백함수 호출 & data인자를 통해서 내용을 전달
      //if (body.length > 1e6)
      //   request.connection.destroy();   와 같은 보안 장치를 걸어주기도 한다 ( 규모가 큰 프로그램 에서 )
      // body로 조각 조각 수신하면 마지막으로 end 를 받아준다
      // data, end (이벤트 라고 통칭)를 이용해서 querystring을 parse함수를 사용해 var post와 같이 '객체화' 할 수 있다
      var body = '';
      request.on('data', function(data) {
        body += data;
      });
      request.on('end', function() {
        var post = qs.parse(body);
        var title = post.title;
        var description = post.description;
        // 받아온 post 를 data directory 안에 저장해주기
        fs.writeFile(`data/${title}`, description, 'utf8', function(err) {
          response.writeHead(302, {Location: `/?id=${title}`});
          response.end();
        });
      });
    }
    else if(pathname ==='/update'){
      fs.readdir('./data', function(error, filelist) {
        fs.readFile(`data/${queryData.id}`, 'utf8', function(err, description) {  // 원래는 function(err, data)받는데 어짜피 받은 data 본문에 넣어줄꺼라서 미리 description(본문)으로 받은 것
        var title = queryData.id;
        var list = template.list(filelist);
        var html = template.HTML(title, list,
          `
          <form action="/update_process" method="post">
          <input type="hidden" name="id" value="${title}">
          <p><input type="text" name="title" placeholder="title" value="${title}"></p>
          <p>
          <textarea name="description" placeholder="description">${description}</textarea>
          </p>
          <p>
          <input type="submit">
          </p>
          </form>
          `,
          `<a href="/create">create</a> <a href="/update?/id=${title}">update</a>`
        );
          response.writeHead(200);
          response.end(html);
        });
      });
    }
    else if(pathname ==='/update_process'){
      var body = '';
      request.on('data', function(data) {
        body += data;
      });
      request.on('end', function() {
        var post = qs.parse(body);
        var id = post.id;             // update(수정)과정이므로 바뀌기 이전의 제목을 식별할 수 있도록 id 에 넣어주었다
        var title = post.title;
        var description = post.description;
        fs.rename(`data/${id}`, `data/${title}`, function(error){   // fs.rename(oldPath, newPath, callback){}
          // 받아온 post 를 data directory 안에 저장해주기
          fs.writeFile(`data/${title}`, description, 'utf8', function(err) {
            response.writeHead(302, {Location: `/?id=${title}`});
            response.end();
          });
        })
      });
    }
    else if(pathname ==='/delete_process'){
      var body = '';
      request.on('data', function(data) {
        body += data;
      });
      request.on('end', function() {
        var post = qs.parse(body);
        var id = post.id;
        fs.unlink(`data/${id}`, function(error){
          response.writeHead(302, {Location: `/`});
          response.end();
        })
      });
    }
    else{
      response.writeHead(404);
      response.end('Not found');    // e.g.) /favicon.ico
    }
});
app.listen(3000); // 3000번 포트


/*
여기서 response.writeHead(200); 이란?

웹브라우저가 웹서버에 접속했을 때 기계to기계 사이의 통신 상태를 알리기 위한 약속 필요
서버가 브라우저에게 주는 숫자가
200일때, 파일을 성공적으로 전송했음
301일때, 새로운 location 을 해당 페이지로 영원히 바꿔주기
302일때, 새로운 location 을 해당 페이지로 일시적으로 Redirect
404일때, 파일을 찾을 수 없는 경우
*/

// console.log(_url);          // query string 콘솔에 출력
// console.log(queryData);     // url중에서 parse해서 query객체 추출한것
// console.log(queryData.id);  // 추출한 query객체에서 id키의 값
// console.log(url.parse(_url, true));   // url 구조별로 쭉 부분이름: 배열 형태로 내용 출력

// if(url == '/'){
  //   title = 'Welcome';
  // }
  // if(_url == '/favicon.ico'){
    //   return response.writeHead(404);
    // }
    // console.log(__dirname + url);
    // response.end('egoing : ' + url));
    // response.end(fs.readFileSync(__dirname + url));   //  사용자가 접속한 url에 따라서 dir의 파일 읽어주기
