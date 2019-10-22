<?php session_start();
if(isset($_SESSION['correo'])){
    require 'Visual/VerTienda.php';
}else{
    header('Location: Login.php');
}
?>