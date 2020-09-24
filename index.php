<?php
$conn = mysqli_connect("localhost", "root", "mx9caj", "php_mysql", "3307");

// <li><a href="index.php?id=2">Mysql</a></li>로 만들기

// 글 목록 출력
$sql = "SELECT * FROM topic";
$result = mysqli_query($conn, $sql);
$list = '';
while($row = mysqli_fetch_array($result)){
    $escaped_title = htmlspecialchars($row['title']);
    $list = $list."<li><a href=\"index.php?id={$row['id']}\">{$escaped_title}</a></li>";
}

$article = array(   // index값이 숫자가 아니고 문자인 배열 : 연관배열
    'title'=>'Welcome',
    'description'=>'Hello, web'
);

// 글 제목, 본문 출력
if(isset($_GET['id'])){
    // mysqli_real_escape_string : SQL Injection 막는 함수
    $filtered_id = mysqli_real_escape_string($conn, $_GET['id']);
    $sql = "SELECT * FROM topic WHERE id={$filtered_id}";
    $result = mysqli_query($conn, $sql);
    $row = mysqli_fetch_array($result);
    $article['title'] = htmlspecialchars($row['title']);
    $article['description'] = htmlspecialchars($row['description']);
}
// print_r($article);

?>
<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <title>WEB</title>
  </head>
  <body>
    <h1><a href="index.php">WEB</a></h1>
    <ol>
        <?=$list?>
    </ol>
    <a href="create.php">create</a>
    <h2><?=$article['title']?></h2>
    <?=$article['description']?>
  </body>
</html>