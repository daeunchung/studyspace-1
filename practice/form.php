<?php
file_put_contents('../data/'.$_POST['title'], $_POST['description']);
echo "<p>title : ".$_POST['title']."</p>";
echo "<p>description : ".$_POST['description']."</p>";

// method="get" : bookmark용도로 적합
// method="post" : 정보 생성, 수정, 삭제
?>