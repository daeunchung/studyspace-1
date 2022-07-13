// 많은 객체, 많은 함수를 정리정돈하는 tool => module (가장 큰 도구임)
// 모듈을 이용하면 여러 객체를 파일로 쪼개서 웹으로 독립시킬수 있음

// var M = {
//   v:'v',
//   f:function(){
//     console.log(this.v);
//   }
// }

var part = require('./mpart.js');
part.f();
