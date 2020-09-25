<?php
// var_dump($_POST);    1.접속 2.db선택 3.mysqli_query
$conn = mysqli_connect("localhost", "root", "mx9caj", "php_mysql", "3307");

settype($_POST['id'], 'integer');
$filtered = array(
    'id'=>mysqli_real_escape_string($conn, $_POST['id']),
    'name'=>mysqli_real_escape_string($conn, $_POST['name']),
    'profile'=>mysqli_real_escape_string($conn, $_POST['profile'])
);

$sql = "
    UPDATE author SET 
        name = '{$filtered['name']}',
        profile = '{$filtered['profile']}'
    WHERE
        id = {$filtered['id']}
";
$result = mysqli_query($conn, $sql);
if($result === false){
    echo '수정하는 과정에서 문제가 생겼습니다. 관리자에게 문의해주세요';   
    error_log(mysqli_error($conn));
}else{
    header('Location: author.php?id='.$filtered['id']);
}
?>
