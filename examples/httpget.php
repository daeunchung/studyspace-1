<html>
    <head>
        <title>HTTP GET 방식 예제</title>
        <meta charset="utf-8"/>
    </head>
    <body>
        <?php
            echo 'key = ' . $_GET['key'] . '<br/>';     //PHP string 연결 : . (concatenate)
            echo 'value = ', $_GET['value'], '<br/>';
        ?>
    </body>
</html>