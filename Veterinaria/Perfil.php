<?php session_start();
if(isset($_SESSION['correo'])){
    require 'Visual/VerPerfil.php';
}else{
    header('Location: index.php');
}
?>
