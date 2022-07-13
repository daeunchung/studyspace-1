var testFolder = './data/';
var fs = require('fs');

// fs.readdir(testFolder, (err, files) => {
//   files.forEach(file => {
//     console.log(file);
//   });
// });

fs.readdir(testFolder, function(error, filelist) {
  console.log(filelist);
  // 배열 형태로 출력되는 것을 확인할 수 있다
  // [ 'CSS', 'HTML', 'JavaScript' ]
})
