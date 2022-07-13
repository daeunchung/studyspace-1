var Links = {
  setColor:function(color){
    // 이 웹페이지에 있는 모든 a tag를 jquery로 제어하겠다 -> $
    $('a').css('color', color);

    // var alist = document.querySelectorAll('a');
    // var i = 0;
    // while(i < alist.length){
    //   alist[i].style.color = color;
    //   i++;
    // }
  }
}
// 객제의 프로퍼티, 메서드 끼리 구분하기위해 콤마(,) 필수
var Body = {
  setColor:function (color) {
    // document.querySelector('body').style.color = color;
    $('body').css('color', color);
  },
  setBackgroundColor:function(color) {
    // document.querySelector('body').style.backgroundColor = color;
    $('body').css('backgroundColor', color);
  }
}

function nightDayHandler(self){
  var target = document.querySelector('body');
  if(self.value === 'night'){
    Body.setBackgroundColor('black');
    Body.setColor('white');
    self.value = 'day';
    Links.setColor('powderblue');
  }else{
    Body.setBackgroundColor('white');
    Body.setColor('black');
    self.value = 'night';
    Links.setColor('blue');
}
}
