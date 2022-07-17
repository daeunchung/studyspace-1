<!DOCTYPE html>
<html>
<head>
    <title>회원가입 결과</title>
    <meta charset="UTF-8">
</head>
<body>
<?php
    require_once('dbcon.php');

    if(empty($_POST['email']) || empty($_POST['pass']) || empty($_POST['passcon'])){
        exit('<a href="javascript:history.go(-1)">입력 폼을 채워주세요.</a>');
    }

    if(!isset($_FILES['userimg'])){
        exit('<a href="javascript:history.go(-1)">이미지 업로드 에러가 발생했습니다.</a>');
    }
    // echo $_FILES['userimg']['name'];
    // echo $_FILES['userimg']['tmp_name'];

    // 방법1. DB에 파일명만 저장하고 별도의 file로 실제 이미지는 File System에 이미지 저장
    // $imagepath = "./images/a.jpg";
    // $imagepath = "./images/" . uniqid("img") . "." . pathinfo($_FILES['userimg']['name'], PATHINFO_EXTENSION);
    // if(!move_uploaded_file($_FILES['userimg']['tmp_name'], $imagepath)){
    //     exit('<a href="javascript:history.go(-1)">이미지 에러가 발생했습니다.</a>');
    // }

    $dbc = mysqli_connect($host, $user, $pass, $dbname, $port)
    or die("Error Connecting to MySQL Server.");
    $email = mysqli_real_escape_string($dbc, trim($_POST['email']));
    $pass = mysqli_real_escape_string($dbc, trim($_POST['pass']));
    $passcon = mysqli_real_escape_string($dbc, trim($_POST['passcon']));
    // 방법2. BLOB 을 사용하여 실제 이미지를 DB에 저장
    $image = addslashes(file_get_contents($_FILES['userimg']['tmp_name']));

    $query = "select id from user where email='$email'";
    $result = mysqli_query($dbc, $query) or die ("Error Querying database.");

    if(mysqli_num_rows($result) != 0){
        exit('<a href="javascript:history.go(-1)">이미 등록된 e-mail입니다.</a>');
    }

    mysqli_free_result($result);
    mysqli_query($dbc, 'set names utf8');

    // $query = "insert into user values (null, '$email', SHA('$pass'), '$imagepath')";
    $query = "insert into user values (null, '$email', SHA('$pass'), '$image')";
    // echo $query;

    $result = mysqli_query($dbc, $query) or die ("Error Querying database.");

    mysqli_close($dbc);

    // 이미지를 꺼내는 php 파일을 별도로 만들어주어야 db에서 이미지를 꺼내서 출력 가능
    echo '<img src="userimage.php?email=$email" alt="User Image" style="width:80px; height:80px;"><br/>';
    echo "$email"."님의 회원 가입을 축하드립니다.<br/><br/>";
    echo '<a href="/main.html">홈으로</a>';

?>

</body>
</html>