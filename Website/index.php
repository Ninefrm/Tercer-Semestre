<?php session_start();
if (isset($_SESSION['Correo'])){
    header('Location: VeterinariaOnline.php');
}else{
    header('Location: Login.php');
}
?>
