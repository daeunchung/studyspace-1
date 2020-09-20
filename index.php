<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <h1><a href="index.php">WEB</h1>
        <!-- <ol>
            <li><a href="index.php?id=HTML">HTML</a></li>
            <li><a href="index.php?id=CSS">CSS</a></li>
            <li><a href="index.php?id=JavaScript">JavaScript</a></li>
        </ol> 
        data 디렉토리에 있는 파일의 목록을 가져오세요. PHP님
        파일의 목록 하나 하나를 li와 a 태그를 이용해서 글목록을 만드세요.
        -->
        <ol>
            <?php
            $list = scandir('./data');
            // var_dump($list);
            $i = 0;
            while($i < count($list)){
                if($list[$i] != '.' && $list[$i] != '..'){
                    echo "<li><a href=\"index.php?id=$list[$i]\">$list[$i]<a></li>\n";
                }
                $i = $i + 1;
            }
            ?>
        </ol>
        
        
        
        <!-- 반복문을 이용한 목차 출력 -->
        <!--?php
            $i = 0;
            while($i < count($list)){
                if($list[$i] != '.'){
                    if($list[$i] != '..'){
                        ?-->
                        <!-- <li><a href="index.php?id=<?=$list[$i]?>"><?=$list[$i]?></a></li> -->
                        <!--?php
                    }
                }
                $i = $i + 1;
            }
        ?-->
        
        <h2>
            <?php
            if(isset($_GET['id'])){
                echo $_GET['id'];
            }else{
                echo "Welcome";
            }
            ?>
        </h2>
        <?php
        if(isset($_GET['id'])){
            echo file_get_contents("data/".$_GET['id']);
        }else{
            echo "Hello, PHP";
        }
        ?>
    </body>
</html>