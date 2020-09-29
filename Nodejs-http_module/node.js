var fs = require('fs');
var http = require('http');

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
// => 서버를 실행하고 localhost에 접속하면 처음에는 내가 추가한 쿠키가 뜨지 않음
// 두번째 요청부터 쿠키를 출력하게 됨
// 쿠키는 F12를 눌러 개발자 도구로 확인


var http = require('http'); 
http.createServer(function(req, res) { 
  // localhost 에 접속하면 Location 에 입력한 URL 로 이동 
  res.writeHead(302, {'Location' : 'http://www.naver.com'}); 
  res.end(); 
}).listen(4004, function() { 
    console.log('server running at http://localhost:4004'); 
});
// => 페이지 강제 이동 : writeHead 에 두번째 매개변수에 Location 속성 이용


var http = require('http'); 
http.createServer(function(req, res) { 
  res.writeHead(404); 
  res.end(); 
}).listen(4005, function() { 
    console.log('server running at http://localhost:4005'); 
});
// => 고의로 HTTP 404 Page Not Found 창 띄우기