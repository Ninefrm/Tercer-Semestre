<?php session_start();

if (isset($_SESSION['Correo'])){
    header('Location: index.php');
}

if($_SERVER['REQUEST_METHOD']=='POST'){
    $Correo = $_POST['Correo'];
    $password = $_POST['password'];
    $password = md5($password);
    // $password = hash('sha512', $password);
    $errores ='';
    try{
        $conexion = new PDO('mysql:host=198.91.81.7;dbname=ninefrmx_veterinaria','ninefrmx_root','Samuel20');
    }catch(PDOException $e){
        echo "Error: ". $e->getMessage();
    }

    $sql = "SELECT * FROM administradores WHERE correo = :correo AND pass= :password AND activo= '1' AND eliminado= '0'";

    $statement = $conexion -> prepare($sql);
    $statement ->execute(array(':correo'=> $Correo,':password'=> $password));
    $resultado = $statement->fetch();

    $all = $conexion->prepare("SELECT nombre FROM administradores WHERE correo =:correo");
    $all ->execute(array(':correo'=>$Correo));
    $Nombre = $all->fetchColumn();

    if($resultado !==false){
        $_SESSION['Correo'] = $Correo;
        $_SESSION['password'] = $password;
        $_SESSION['Nombre'] = $Nombre;
        header('Location: index.php');
    }else{
        $errores .= 'Datos invalidos';
    }
}
require 'Visual/Login.php';
?>

