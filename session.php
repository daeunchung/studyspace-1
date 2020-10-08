<?php
    session_start();
    ob_start();
    // 서버에서는 브라우저를 종료하게 되면 세션이 끝난다

    // 만약에 세션이 없으면 클라이언트측에 쿠키가 있는지 체크 => 쿠키 있으면 세션에 넣어주도록
    if(!isset($_SESSION['id'])){
        if(isset($_COOKIE['id']) && ($_COOKIE['email'])){
            $userid = $_COOKIE['id'];
            $_SESSION['id'] = $userid;
        }
    }
?>