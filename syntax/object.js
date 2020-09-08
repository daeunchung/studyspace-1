// Array
var members = ['egoing', 'k8805', 'hoya'];
console.log(members[1]);
var i = 0;
while(i < members.length){
  console.log('array loop', members[i]);
  i = i + 1;
}

// Object
var roles = {
  // key(name) : value(roles[name])
  'programmer' : 'egoing',
  'designer' : 'k8805',
  'manager' : 'hoya'
}
console.log(roles.designer);
console.log(roles['designer']); // 배열처럼[], 키값을 문자열 형태로 전달

for(var n in roles){ // n 대신 name 해도되고 keynum 해도 되고 var 이름은 상관 X
  console.log('object => ', n, 'value => ', roles[n]);
}
