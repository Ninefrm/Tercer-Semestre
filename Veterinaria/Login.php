<?php session_start();

if (isset($_SESSION['correo'])){
    header('Location: index.php');
}

if($_SERVER['REQUEST_METHOD']=='POST'){
    $correo = $_POST['correo'];
    $password = $_POST['password'];
    $password = md5($password);
    // $contraseña = hash('sha512', $contraseña);
    $errores ='';
    try{
        $conexion = new PDO('mysql:host=localhost;dbname=ninefrmx_veterinaria','ninefrmx_root','Samuel20');
    }catch(PDOException $e){
        echo "Error: ". $e->getMessage();
    }
    //Administrador
    $sql = "SELECT * FROM administrador WHERE correo = :correo AND password= :password AND activo= '1'";
    $sql_veterinario = "SELECT * FROM veterinario WHERE correo = :correo AND password= :password AND activo= '1'";
    $sql_cajero = "SELECT * FROM cajero WHERE correo = :correo AND password= :password AND activo= '1'";
    $sql_cliente = "SELECT * FROM cliente WHERE correo = :correo AND password= :password AND activo= '1'";

    $statement = $conexion -> prepare($sql);
    $statement ->execute(array(':correo'=> $correo,':password'=> $password));
    $resultado = $statement->fetch();

    $statement_veterinario = $conexion -> prepare($sql_veterinario);
    $statement_veterinario ->execute(array(':correo'=> $correo,':password'=> $password));
    $resultado_veterinario = $statement_veterinario->fetch();

    $statement_cajero = $conexion -> prepare($sql_cajero);
    $statement_cajero ->execute(array(':correo'=> $correo,':password'=> $password));
    $resultado_cajero = $statement_cajero->fetch();

    $statement_cliente = $conexion -> prepare($sql_cliente);
    $statement_cliente ->execute(array(':correo'=> $correo,':password'=> $password));
    $resultado_cliente = $statement_cliente->fetch();

    if($resultado){
        $all = $conexion->prepare("SELECT nombre FROM administrador WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $nombre = $all->fetchColumn();
        $all = $conexion->prepare("SELECT tipo FROM administrador WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $tipo = $all->fetchColumn();
        $_SESSION['correo'] = $correo;
        $_SESSION['password'] = $password;
        $_SESSION['nombre'] = $nombre;
        $_SESSION['tipo'] = $tipo;
        header('Location: index.php');
    }
    elseif($resultado_veterinario){
        $all = $conexion->prepare("SELECT nombre FROM veterinario WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $nombre = $all->fetchColumn();
        $all = $conexion->prepare("SELECT tipo FROM veterinario WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $tipo = $all->fetchColumn();
        $_SESSION['correo'] = $correo;
        $_SESSION['password'] = $password;
        $_SESSION['nombre'] = $nombre;
        $_SESSION['tipo'] = $tipo;
        header('Location: index.php');
    }
    elseif ($resultado_cajero){
        $all = $conexion->prepare("SELECT nombre FROM cajero WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $nombre = $all->fetchColumn();
        $all = $conexion->prepare("SELECT tipo FROM cajero WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $tipo = $all->fetchColumn();
        $_SESSION['correo'] = $correo;
        $_SESSION['password'] = $password;
        $_SESSION['nombre'] = $nombre;
        $_SESSION['tipo'] = $tipo;
        header('Location: index.php');
    }
    elseif ($resultado_cliente){
        $all = $conexion->prepare("SELECT nombre FROM cliente WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $nombre = $all->fetchColumn();
        $all = $conexion->prepare("SELECT tipo FROM cliente WHERE correo =:correo");
        $all ->execute(array(':correo'=>$correo));
        $tipo = $all->fetchColumn();
        $_SESSION['correo'] = $correo;
        $_SESSION['password'] = $password;
        $_SESSION['nombre'] = $nombre;
        $_SESSION['tipo'] = $tipo;
        header('Location: index.php');
    }




//    if($resultado !==false) {
//        $_SESSION['correo'] = $correo;
//        $_SESSION['password'] = $password;
//        $_SESSION['nombre'] = $nombre;
//        $_SESSION['tipo'] = $tipo;
//        header('Location: index.php');
//    }

    else {
        echo $correo;
        echo $password;
        $errores .= 'Datos invalidos';
    }
}
require 'Visual/Login.php';
?>
