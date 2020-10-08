<?php
    session_start();
    ob_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>로그아웃 결과</title>
    <meta charset="UTF-8">
</head>
<body>

<?php
require_once('dbcon.php');

if(!isset($_SESSION['id'])){
    exit('<a href="main.php">로그인 상태가 아닙니다. 홈으로</a>');
}

$_SESSION = array();        // 기존 세션을 없애주는 역할

if(isset($_COOKIE[session_name()])){
    setcookie(session_name(), '', time() - (60*60));    // 현재시간보다 1시간 빠르게 == 없앤다
}
session_destroy();

setcookie('id', '', time() - (60*60)); 
setcookie('email', '', time() - (60*60));

echo '로그아웃하였습니다.<br/><a href="main.php">홈으로</a>';
?>
</body>
</html>
