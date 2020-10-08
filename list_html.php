<html>
<head>
    <title>건담모델 보기</title>
    <meta charset="utf-8"/>
</head>
<body>
<?php
    require_once('dbcon.php');

    $dbc = mysqli_connect($host, $user, $pass, $dbname, $port)
        or die("Error Connecting to MySQL Server.");
    mysqli_query($dbc, "set names utf8");

    $query = "select * from unit";
    $result = mysqli_query($dbc, $query) 
        or die ("Error Querying database.");

    echo '<table border="1">';
    echo '<tr><th>ID</th><th>기체명</th><th>모델명</th></tr>';

    while ($row = mysqli_fetch_assoc($result)){
        echo '<tr>';
        echo '<td>'.$row['id'].'</td><td>'.$row['name'].'</td><td>'.$row['movie'].'</td>';
        echo '</tr>';
    }
    echo '</table>';

    mysqli_free_result($result);
    mysqli_close($dbc);
?>
</body>
</html>

