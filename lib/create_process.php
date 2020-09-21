<?php
file_put_contents('../data/'.$_POST['title'],$_POST['description']);
header('Location: /lib/index.php?id='.$_POST['title']);
?>