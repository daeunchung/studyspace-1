var http = require('http');
var fs = require('fs');
var url = require('url');
// const { runInNewContext } = require('vm');

// (1) url 속성
http.createServer(function(req, res){
    // 사용자가 요청한 url을 읽어 url 속성을 이용해 pathname 추출
    var pathname = url.parse(req.url).pathname;

    if(pathname == '/'){
        // http://localhost:4006/ 접속 시 수행
        fs.readFile('index.html', function(err, data){
            res.writeHead(200, {'Content-Type' : 'text/html'});
            res.end(data);
        });
    }
    else if(pathname == '/otherpage'){
        // http://localhost:4006/otherpage 접속 시 수행
        fs.readFile('other.html', function(err, data){
            res.writeHead(200, {'Content-Type' : 'text/html'});
            res.end(data);
        });
    }
}).listen(4006, function(){
    console.log('server running at http://localhost:4006');
})



// (2) method 속성
http.createServer(function(req, res){
    // url.parse 의 두번째 매개변수는 parseQueryString 으로 boolean type 
    // true : parse 의 반환 값이 querystring 
    // false : string 으로 변환하지 않음 defalt 값으로 false임
    var pathname = url.parse(req.url).pathname;
    var query = url.parse(req.url, true).query;

    if(pathname == "/ex1"){
        res.writeHead(200, {'Content-Type' : 'SStext/html'});
        res.end('<h1>' + JSON.stringify(query) + '</h1>');
    }else if(pathname == '/ex2'){
        if(req.method == 'GET'){
        // 접속 시 GET 요청이므로 .html 파일을 읽어와 뿌림
            fs.readFile('page.html', function(err, data){
                res.writeHead(200, {'Content-Type' : 'text/html'});
                res.end(data);
            });
        }else if(req.method == 'POST'){
            // 위 .html 파일 중 submit type 의 버튼이 있음 
            // 그 버튼을 클릭 시 req 에 data 라는 이벤트를 등록
            req.on('data', function(data){
                // POST 가 발생했을 때 그 쿼리문이 data에 전송됨
                res.writeHead(200, {'Content-Type' : 'text/html'});
                res.end('<h1>' + data + '</h1>'); 
            });
        }
    }
}).listen(4007, function(req, res){
    console.log('server running at http://localhost:4007');
});
