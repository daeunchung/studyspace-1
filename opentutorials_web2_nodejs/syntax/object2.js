// array, object
// javascript 에서는 함수는 statement 이면서 '값' 이기도 하다


// js에서 함수 statement는 값이 될 수 있다
// 1. 처리방법을 담은 구문   2. 그 자체로 값
var f = function() {
  console.log(1+1);
  console.log(1+2);
}

var a = [f];  // 배열의 원소로 함수 존재 가능
a[0]();

var o = {     // 객체의 원소로 함수 존재 가능
  func:f      // property:value
}
o.func();

// var i = if(true){console.log(1)}; => js에서 조건문은 값 X => 에러 발생
// var w = while(true){console.log(1)}; => js에서 반복문은 값 X => 에러 발생
