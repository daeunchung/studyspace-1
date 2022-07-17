<nav>
    <ul>
        <?php
            if(!isset($_SESSION['id']))
                echo '<li><a href="loginform.html">로그인</a></li>';
            else
                echo '<li><a href="logout.php">로그아웃</a></li>';
        ?>
        <li><a href="signup.html">회원 가입</a></li>
        <li><a href="main.php">사진 게시판</a></li>
        <li><a href="grade.php">등급 설명</a></li>
    </ul>
</nav>