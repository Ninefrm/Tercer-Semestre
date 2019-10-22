<?php session_start();
if(isset($_SESSION['correo'])){
    require 'Visual/AdministrarPerfiles.php';
}else{
    header('Location: index.php');
}
?>
