var fs = require('fs');
fs.readFile('sample.txt', 'utf8', function(err, data){
  console.log(data);
})
// 최신 js 코드
// fs.readFile('/etc/passwd', (err, data) => {
//   if (err) throw err;
//   console.log(data);
// });
