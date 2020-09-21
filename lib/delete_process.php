<?php
unlink('../data/'.$_POST['id']);
header('Location: /lib/index.php');
?>