<?php
    require_once("session.php");
?>
<html>
<head>
    <title>댓글 등록</title>
    <meta charset="UTF-8">
</head>
<body>
    <?php
    if(!isset($_SESSION['id'])){
        exit ('<a href="main.php">로그인 상태가 아닙니다. 홈으로</a></body></html>');
    }
    ?>
    <h1>건담 리뷰 댓글 등록</h1>
    <form action="writereply.php" method="post">
        댓글:<br/>
        <textarea name="memo" cols="50" rows="10" maxlength="5000"></textarea>
        <input type="hidden" name="reviewid" value="<?php echo $_GET['reviewid']; ?>"/>
        <br/>
        <br/>
        <input type="submit" value="댓글 등록"/>
    </form>
</body>
</html>