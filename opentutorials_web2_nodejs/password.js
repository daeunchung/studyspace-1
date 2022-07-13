module.exports = {
  id:'egoing',
  password:'11111111'
}


/*
< 생활코딩 Node.js-46.App제작-입력정보에 대한 보안 >
외부의 데이터를 받아올때 (writeFile, unlink...) 보안처리

수정시에
var filteredId = path.parse(queryData.id).base;
fs.readFile(`data/${filteredId}`, 'utf8', function(err, description) {}

삭제시에
var filteredId = path.parse(id).base;
fs.unlink(`data/${filteredId}`, function(error){}

와 같이 path.parse를 거친 후에 ${}로 받아줘야 사용자가 웹브라우저에서 함부로 접속해서
내 컴퓨터 속의 내용을 출력하는 것을 막을 수 있다.

e.g.) web2-nodejs\password.js 와 같이 파일이 존재하고, password.js 에는 id, pw가 저장되어 있다.
      현재 위치 : web2-nodejs\data 폴더 안

      fs.readdir('./data', function(error, filelist){
        fs.readFile(`data/${queryData.id}`, 'utf8', function(err, description){
                        ...
                        ...
                        ...
        })
      })
     다음과 같은 상태의 코드에서 웹브라우저 url 로  http://localhost:3000/?id=../password.js 접속하면
     웹화면 본문에 password.js 속의 내용이 전부 출력된다 => 보 안 꽝

따라서 path.parse() 함수 처리를 거친 var filteredId를 받아서 `data/${filteredId}`와 같이 받아줘야 한다
경로를 탐색해 나갈 수 있는 정보를 세탁 가능
path.parse() 함수는 객체를 반환, path.parse().base 하면 파일명.확장자 (예시: password.js) 반환
*/


/*
< 생활코딩 Node.js-47.App제작-출력정보에 대한 보안 >
사용자가 <script></script> 태그를 사용해 그 안에 정보를 입력할 경우에는
웹 브라우저는 작성된 javascript 내용을 실행하여서 사용자가 마음대로 적은대로 실행할 수 있다.
e.g.) 악성코드 심어놓기, 이상한 페이지로 Redirect 등등

따라서 사용자가 입력한 정보에 <script></script> 태그가 있는지 확인하고 있으면 비활성화 시킨다
목적 1) 보안 : 사용자가 입력한 정보를 외부로 출력할 때 오염된 정보 있다면 => 살균, 소독 (sanitize)
  방법 1-1) 찾아서 싹 지워준다
  방법 1-2) html entities 를 적용해주어 웹브라우저에서 javascript로 동작하지 못하게끔 입력된 내용을 수정
  < 기호를 &lt; 또는	&#60; 로 직접 바꾸어 준다
  > 기호를 &gt; 또는 &#62; 로 직접 바꾸어 준다

방법 1-2 예시)
<script>
location.href = 'https://opentutorials.org/course/1';
</script>
                          를
&lt;script&gt;
location.href = 'https://opentutorials.org/course/1';
&lt;/script&gt;
                          로 수정


 목적 2) npm을 통해서 내가 아닌 다른 사람이 만든 모듈을 사용해서 application 빠르게 만드는 법
 cmd 창에서 npm init
 npm install -S sanitize-html   ( -S : static : 이 폴더 안에서만 지역적으로, -g : global : 내 컴퓨터 전체에)

 var sanitizeHtml = require('sanitize-html'); => 미리 약속된 대로 node_modules\sanitize-html에서 파일 탐색
 이름 붙여진 모튤(sanitizeHtml)을 ${} js로 받으면 사용자가 해놓은 설정에 따라서
 sanitize 할 태그 + 내용 , 태그만 sanitize하고 내용은 유지할 태그 , 태그도 내용도 놔둘 태그 .... 등 설정 가능

 방법 2 예시)   sanitizeHtml(dirtyHtml, allowedTags and Attributes로 이루어진 {객.체.})
 // Allow only a super restricted set of tags and attributes
clean = sanitizeHtml(dirty, {
  allowedTags: [ 'b', 'i', 'em', 'strong', 'a' ],
  allowedAttributes: {
    'a': [ 'href' ]
  },
  allowedIframeHostnames: ['www.youtube.com']
});
*/
