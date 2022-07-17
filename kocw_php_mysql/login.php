<?php
    session_start();
    ob_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>로그인 결과</title>
    <meta charset="UTF-8">
</head>
<body>

<?php
require_once('dbcon.php');

if(isset($_SESSION['id'])){
    exit('<a href="main.php">세션을 통해서 로그인 정보를 확인했습니다..</a>');
}

if(empty($_POST['email']) || empty($_POST['pass'])){
    exit('<a href="javascript:history.go(-1)">로그인 폼을 채워주세요.</a>');
}
    
$dbc = mysqli_connect($host, $user, $pass, $dbname, $port)
    or die("Error Connecting to MySQL Server.");

$email = mysqli_real_escape_string($dbc, trim($_POST['email']));
$pass = mysqli_real_escape_string($dbc, trim($_POST['pass']));

$query = "select id, email from user where email='$email' and password=SHA('$pass')";
$result = mysqli_query($dbc, $query) 
    or die ("Error Querying database.");

if(mysqli_num_rows($result) == 1){
    $row = mysqli_fetch_assoc($result);
    $userid = $row['id'];
    $_SESSION['id'] = $userid;
    setcookie('id', $row['id'], time() + (60*60*24));
    setcookie('id', $row['email'], time() + (60*60*24));

    echo "$email"."님의 로그인에 성공했습니다.<br/><br/><a href='main.php'>홈으로</a>";
}else {
    echo "로그인에 실패했습니다.<br/><br/><a href='main.php'>홈으로</a>";
}

mysqli_free_result($result);
?>
</body>
</html>
