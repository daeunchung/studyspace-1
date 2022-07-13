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

$update_link = '';
$delete_link = '';
$author = '';
// 글 제목, 본문 출력
if(isset($_GET['id'])){
    // mysqli_real_escape_string : SQL Injection 막는 함수
    $filtered_id = mysqli_real_escape_string($conn, $_GET['id']);
    $sql = "SELECT * FROM topic LEFT JOIN author ON topic.author_id = author.id WHERE topic.id={$filtered_id}";
    $result = mysqli_query($conn, $sql);
    $row = mysqli_fetch_array($result);
    // print_r($row);

    $article['title'] = htmlspecialchars($row['title']);
    $article['description'] = htmlspecialchars($row['description']);
    $article['name'] = htmlspecialchars($row['name']);

    $update_link = '<a href ="update.php?id='.$_GET['id'].'">update</a>';
    $delete_link = '
    <form action="process_delete.php" method="post">
      <input type="hidden" name="id" value="'.$_GET['id'].'">
      <input type="submit" value="delete">
    </form>
    ';
    $author = "<p>by {$article['name']}</p>";
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
    <a href="author.php">author</a>
    <ol>
        <?=$list?>
    </ol>
    <p><a href="create.php">create</a></p>
    <?=$update_link?>
    <?=$delete_link?>
    <h2><?=$article['title']?></h2>
    <?=$article['description']?>
    <?=$author?>
    
  </body>
</html>