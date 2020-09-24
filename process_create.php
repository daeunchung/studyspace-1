<?php
// var_dump($_POST);    1.접속 2.db선택 3.mysqli_query
$conn = mysqli_connect("localhost", "root", "mx9caj", "php_mysql", "3307");

$filtered = array(
    'title'=>mysqli_real_escape_string($conn, $_POST['title']),
    'description'=>mysqli_real_escape_string($conn, $_POST['description'])
);

$sql = "
INSERT INTO topic 
    ( title, description, created ) 
        VALUES( 
            '{$filtered['title']}', 
            '{$filtered['description']}', 
            NOW() 
        )";
$result = mysqli_query($conn, $sql);
if($result === false){
    echo '저장하는 과정에서 문제가 생겼습니다. 관리자에게 문의해주세요';   
    error_log(mysqli_error($conn));
}else{
    echo '성공했습니다. <a href="index.php">돌아가기</a>';
}
// echo '<br>'.$sql;
?>
