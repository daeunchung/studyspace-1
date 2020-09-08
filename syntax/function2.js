// Js가 내장하고 있는 객체 Math (비슷한 분야의 함수들을 묶어서 관리하는 directory 로 보면된다), 그 속의 반올림 함수 round

console.log(Math.round(1.6));   // 2
console.log(Math.round(1.4));   // 1

// function sum(first, second){  // parameter 매개변수
//   console.log(first + second);
// }
//
// sum(2,4);                     // argument 인자

function sum(first, second){
    return first + second;
    // return
    // -> 1. 값 출력  2. 그 곳에서 함수를 즉시 종료
}

console.log(sum(2,4));
