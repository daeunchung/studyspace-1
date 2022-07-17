<html>
<head>
    <title>노래 보기</title>
    <meta charset="UTF-8">
</head>
<body>
    <?php
    $dbc = mysqli_connect("localhost", "root", "mx9caj", "mysong","3307")
        or die("Error Connecting to MySQL Server.");
    mysqli_query($dbc, "set names utf8");

    $query = "select * from song";
    $result = mysqli_query($dbc, $query) 
    or die ("Error Querying database.");
    echo '노래 제목   가수   노래방 번호   선호도 <br/>';
    while ($row = mysqli_fetch_assoc($result)){
        echo $row['name'] . ' ' . $row['sid'] . ' ' . $row['number'] . ' ' . $row['favorite'] . '</br>';
    }
    mysqli_free_result($result);
    mysqli_close($dbc);
    ?>
</body>
</html>

