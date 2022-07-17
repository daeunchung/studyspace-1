// - 서버 실행

// http 모듈을 추출
var http = require('http');
// http 모듈의 createServer 메소드를 이용하여
// server 객체를 만듬(웹 서버 생성)
var server = http.createServer();
// localhost의 52273 port에 웹 서버를 실행
server.listen(52273);



// - 서버 종료

// 서버 생성
var server = require('http').createServer();
// localhost(127.0.0.1)의 52273 port 에 서버 실행
server.listen(52273, function() {
    console.log('server running at http://127.0.0.1:52273');
});
// 5초후 서버 종료, 그리고 프로그램 종료
setInterval(function() {
    server.close();
    console.log('server closed');
    process.exit();
}, 5000);



var http = require('http'); 
var server = http.createServer(); 

// http://localhost:52273 에 요청할 때 발생 
server.on('request', function() { 
    console.log('request on'); 
}); 
// http://localhost:52273 에 접속할 때 발생 
server.on('connection', function() { 
    console.log('connection on'); 
}); 
// 서버종료시 발생 
server.on('close', function() { 
    console.log('close on'); 
}); 

server.listen(52273); 

setInterval(function() { 
    server.close(); 
    console.log('server closed'); 
    process.exit(); 
}, 5000);


/* 코드 속의 모든 포트번호 같게 지정해놔서 실행하려면 포트 번호 변경 해줘야함 */