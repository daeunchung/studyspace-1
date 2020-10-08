<html>
    <title>PHP 예제</title>
    <body>
        <?php
            function jongsung($str){
                $uni = mb_convert_encoding($str, 'UCS-2LE', 'UTF-8');
                $kr1 = ord(substr($uni, -2));
                $kr2 = ord(substr($uni, -1));
                return (($kr2 * 256 + $kr1) - 44032) % 28;
            }
            $name = '홍길동';

            if(jongsung($name) == 0)
                echo '<h1>', $name, '는 주인공입니다.</h1>';
            else
                echo '<h1>', $name, '은 주인공입니다.</h1>';
            echo '<br/>';
            if(jongsung($name) == 0)
                echo $name.'가 주인공입니다.</h1>';
            else
                echo $name.'이 주인공입니다.</h1>';
            echo '<br/>';

            echo '만나서 반갑습니다.<br/>';
            echo date('Y년 m월 d일 H시 i분');
        ?>
    </body>
</html>
