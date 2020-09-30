var http = require('http');
var fs = require('fs');
var ejs = require('ejs');

http.createServer(function(req, res){
    fs.readFile('page.ejs', 'utf8', function(err, data){
        res.writeHead(200, {'Content-Type' : 'text/html'});
        // 불러온 .ejs 파일을 render 메소드에 넘김, .ejs 파일을 분석하여 .html 파일로 만듬
        res.end(ejs.render(data));
    });
}).listen(4008, function(){
    console.log('server running at http://localhost:4008');
});
