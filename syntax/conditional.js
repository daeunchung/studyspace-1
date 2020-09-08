var args = process.argv;
console.log(args[2]);
// 출력해보면 결국 형식이 배열구조
// [nodejs runtime이 있는 위치, 실행시킨 파일의 경로, 입력한 입력값]
// => nodejs 는 사용자로 부터 들어오는 입력값을 배열의 3번째
// 즉 배열[index 2]부터 넣어주도록 약속되어있음

console.log('A');
console.log('B');
if(args[2] === '1'){
  console.log('C1');
}else{
  console.log('C2');
}
console.log('D');
