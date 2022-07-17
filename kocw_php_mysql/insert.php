<!DOCTYPE html>
<html>
<head>
    <title>노래 입력 결과</title>
    <meta charset="UTF-8" />
</head>
<body>
<?php
    require_once('dbmysong.php');

    if(empty($_POST['name']) || empty($_POST['singer']) || empty($_POST['number']) || empty($_POST['favorite'])){
        exit('<a href="javascript:history.go(-1)">입력 폼을 채워주세요.</a>');
    }

    $dbc = mysqli_connect($host, $user, $pass, $dbname, $port)
        or die("Error Connecting to MySQL Server.");

    $name = mysqli_real_escape_string($dbc, trim($_POST['name']));
    $singer = mysqli_real_escape_string($dbc, trim($_POST['singer']));
    $number = mysqli_real_escape_string($dbc, trim($_POST['number']));
    $favorite = mysqli_real_escape_string($dbc, trim($_POST['favorite']));

    mysqli_query($dbc, 'set names utf8');
    $query = "insert into song (name, singer, number, favorite) values ('$name', '$singer', $number, $favorite)";
    $result = mysqli_query($dbc, $query) 
        or die ("Error Querying database.");

    mysqli_close($dbc);
    echo "$singer" . "의 $name" . ((jongsung($name) == 0)?"를" : "을") . " 추가했습니다.";    

    function jongsung($str){
        $uni = mb_convert_encoding($str, 'UCS-2LE', 'UTF-8');
        $kr1 = ord(substr($uni, -2));
        $kr2 = ord(substr($uni, -1));
        return (($kr2 * 256 + $kr1) - 44032) % 28;
    }
?>
</body>
</html>