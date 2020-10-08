<?php
    header('Content-Type: text/xml; charset=UTF-8');
    echo '<?xml version="1.0" encoding="UTF-8"?>';
?>
<list>
<?php
    require_once('dbcon.php');

    $dbc = mysqli_connect($host, $user, $pass, $dbname, $port)
        or die("Error Connecting to MySQL Server.");
    mysqli_query($dbc, "set names utf8");

    $query = "select * from unit";
    $result = mysqli_query($dbc, $query) 
        or die ("Error Querying database.");

    while ($row = mysqli_fetch_assoc($result)){
        print ('<gundam>');
        printf('<id>%d</id>', $row['id']);
        printf('<name>%s</name>', $row['name']);
        printf('<model>%s</model>', $row['model']);
        print ('</gundam>');
    }
    mysqli_free_result($result);
    mysqli_close($dbc);
?>
</list>

