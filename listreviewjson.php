<?php
    header('Content-Type: application/json; charset=UTF-8');
    require_once('dbcon.php');

    // $reviewmax = 30;
    // if(isset($_POST['reviewsince']))
    //     $reviewsince = $_POST['reviewsince'] * $reviewmax;
    // else
    //     $reviewsince = 0;

    // $replymax = 30;
    // if(isset($_POST['replysince']))
    //     $replysince = $_POST['replysince'] * $replymax;
    // else
    //     $replysince = 0;

    $dbc = mysqli_connect($host, $user, $pass, $dbname, $port)
        or die("Error Connecting to MySQL Server.");

    mysqli_query($dbc, "set names utf8");
    $query = "select reviewid, userid, email, memo, time from review, user
                where userid=user.id order by time desc limit 0, 30";
    $result = mysqli_query($dbc, $query) or die ("Error Querying database.");

    $json = array(); // 배열 생성
    while ($row = mysqli_fetch_assoc($result)){
        $replyquery = "select replyid, userid, email, memo, time from reply, user
                        where reviewid=$row[reviewid] and user.id=reply.userid 
                        order by time desc limit 0, 30";
        $replyresult = mysqli_query($dbc, $replyquery) or die ("Error Querying database.");
        
        $replyjson = array();
        while ($replyrow = mysqli_fetch_assoc($replyresult)){
            $replyjson['reply'][] = $replyrow;
        }
        $json['review'][] = $row + $replyjson;

        mysqli_free_result($replyresult);
    }    
    mysqli_free_result($result);
    mysqli_close($dbc);

    echo json_encode($json);
?>

