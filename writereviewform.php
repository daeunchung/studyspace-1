<?php
    require_once("session.php");
?>
<html>
<head>
    <title>리뷰 등록</title>
    <meta charset="UTF-8">
</head>
<body>
    <?php
    if(!isset($_SESSION['id'])){
        exit ('<a href="main.php">로그인 상태가 아닙니다. 홈으로</a></body></html>');
    }
    ?>
    <h1>건담 리뷰 등록</h1>
    <form action="writereview.php" method="post" enctype="multipart/form-data">
        리뷰 메모:<br/>
        <textarea name="memo" cols="50" rows="10"></textarea>
        <br/>
        리뷰 메모:<br/>
        <input type="file" name="picture"/>
        <br/>
        <br/>
        <input type="submit" value="리뷰 등록"/>
    </form>
</body>
</html>