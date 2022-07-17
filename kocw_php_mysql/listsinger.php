<?php

    $dbc = mysqli_connect("localhost", "root", "mx9caj", "mysong","3307")
        or die("Error Connecting to MySQL Server.");

    mysqli_query($dbc, "set names utf8");

    $query = "select * from singer";
    $result = mysqli_query($dbc, $query) or die ("Error Querying database.");

    if(mysqli_num_rows($result)){
        echo '<?xml version = "1.0" encoding="utf-8"?>';
        echo '<list>';
        while($row = mysqli_fetch_assoc($result)){
            echo '<singer>' . $row['name'] . '</singer>';
        }
        echo '</list>';
        mysqli_free_result($result);
    }
    
    mysqli_close($dbc);
?>
