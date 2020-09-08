// function a(){
//   console.log('A');
// }

// javascript에서는 함수가 값이
// 변수 a에  함수를 호출하는 행위를 넣어주므로써 , a라는 변수가 담고 있는 값인 함수를 실행 가능하다
var a = function(){
  console.log('A');
}

// 아주 느린 함수 slowfunc 가 있을때, '함수 실행 끝난 후에 그 다음 일을 하시오' 라고 명령하려면
// => 인자로 callback 받도록하고 그 받은 callback을 실행해준다
function slowfunc(callback) {
  callback();
}


// 오랜시간 걸리는 slowfunc함수 실행 끝난 이후에 callback으로 a를 호출 =>
// a는 익명 함수 function() 실행 => console.log('A'); 가 실행
slowfunc(a);
