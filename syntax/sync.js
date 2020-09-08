var fs = require('fs');

// readFileSync : 동기식 : return 값을 result 로 반환                               ( 결과 : A b C )
// console.log('A');
// var result = fs.readFileSync('syntax/sample.txt', 'utf8');
// console.log(result);
// console.log('C');

// readFile : 비동기식 : return 값 X, callback함수를 3번째 인자로 받는다              ( 결과 : A C b )
// => nodejs가 주어진 파일을 읽는 작업이 끝나면, 세번째 인자로 준 함수를 실행시키면서
//    에러가 있다면 err로, 없으면 파일의 내용을 인자 result로 공급

console.log('A');
fs.readFile('syntax/sample.txt', 'utf8', function(err, result) {

});
console.log(result);
console.log('C');
