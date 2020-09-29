var fs = require('fs');
var http = require('http');

// => file system 모듈을 이용한 HTML 파일을 전송하는 방법
http.createServer(function(req, res){
  fs.readFile('./page.html', function(err, data){
    if(err)
      console.log('file read error');
    else{
      res.writeHead(200, {'Content-Type' : 'text/html'});
      res.end(data);
    }
  });
}).listen(4000, function(){
  console.log('server running at http://localhost:4000');
})

// => 이미지와 오디오를 웹페이지에 전송하는 방법
http.createServer(function(req, res){
  fs.readFile('./image_audio/wheel.jpg', function(err, data){
    res.writeHead(200, {'Content-Type' : 'image/jpeg'});
    res.end(data);
  });
}).listen(4001, function() { 
  console.log('server running at http://localhost:4001'); 
});

http.createServer(function(req, res){
  fs.readFile('./image_audio/applause.mp3', function(err, data){
    res.writeHead(200, {'Content-Type' : 'audio/mp3'});
    res.end(data);
  });
}).listen(4002, function() { 
  console.log('server running at http://localhost:4002'); 
});


// => 쿠키 사용
// 쿠키는 일정기간 데이터를 저장할 수 있음(ex. 일정기간 로그인유지)
// writeHead 의 두번째 매개변수에 'Set-Cookie' 를 사용하여 지정
// Set-Cookie 속성은 배열이 들어감
// Name = Value; Expires = 날짜; Domain = 도메인; Path = 경로; Secure
// 서버를 실행하고 localhost에 접속하면 처음에는 내가 추가한 쿠키가 뜨지 않음
// 두번째 요청부터 쿠키를 출력하게 됨
// 쿠키는 F12를 눌러 개발자 도구로 확인
http.createServer(function(req, res){
  var date = new Date();
  date.setDate(date.getDate() + 7);
  res.writeHead(200, {
    'Content-Type' : 'text/html',
    'Set-Cookie' : [
    // cookie breakfast 
    // Name : breakfast Value : toast Expires : 현재날짜 + 7일 
    'breakfast = toast; Expires = ' + date.toUTCString(), 
    // cookie dinner 
    // Name : dinner Value : chicken 
    'dinner = chicken'
    ]
  });
  // 현재 쿠키들을 띄움
  res.end('<h1>' + req.headers.cookie + '</h1>');
}).listen(4003, function(){
  console.log('server running at http://localhost:4003');
})


// => 페이지 강제 이동 : writeHead 에 두번째 매개변수에 Location 속성 이용
var http = require('http'); 
http.createServer(function(req, res) { 
  // localhost 에 접속하면 Location 에 입력한 URL 로 이동 
  res.writeHead(302, {'Location' : 'http://www.naver.com'}); 
  res.end(); 
}).listen(4004, function() { 
    console.log('server running at http://localhost:4004'); 
});


// => 고의로 HTTP 404 Page Not Found 창 띄우기
var http = require('http'); 
http.createServer(function(req, res) { 
  res.writeHead(404); 
  res.end(); 
}).listen(4005, function() { 
    console.log('server running at http://localhost:4005'); 
});