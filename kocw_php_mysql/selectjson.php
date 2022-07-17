<?php

    $dbc = mysqli_connect("localhost", "root", "mx9caj", "mysong","3307")
        or die("Error Connecting to MySQL Server.");

    mysqli_query($dbc, "set names utf8"); // 한글로 출력해야 하니까

    $query = "select * from singer";
    $result = mysqli_query($dbc, $query) or die ("Error Querying database.");

    $json = array(); // 배열 생성
    if(mysqli_num_rows($result)){
        while ($row = mysqli_fetch_assoc($result)){
            $json['list'][] = $row;  // 배열에 추가
        }
        mysqli_free_result($result);
    }    
    echo json_encode($json);

    mysqli_close($dbc);
?>

