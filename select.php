<?php
$conn = mysqli_connect("localhost", "root", "mx9caj", "php_mysql","3307");

echo "<h1>single row</h1>";
$sql = "SELECT * FROM topic WHERE id = 19;";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_array($result);
echo '<h1>'.$row['title'].'</h1>';
echo $row['description'];

echo "<h1>multi row</h1>";
$sql = "SELECT * FROM topic";
$result = mysqli_query($conn, $sql);

// mysqli_fetch_array : db에 row 1개씩 배열형태로 끌어오는 함수, 더이상 가져올 행이 없으면 NULL 반환
while($row = mysqli_fetch_array($result)){
    echo '<h2>'.$row['title'].'</h2>';
    echo $row['description'];
}
