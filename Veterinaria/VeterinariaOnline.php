<?php session_start();
if(isset($_SESSION['correo'])){
    require 'Visual/Inicial.php';
}else{
    header('Location: Login.php');
}
?>
