<html>
<body>
<?php
$mensaje='';
try{
    $conexion = new PDO('mysql:host=localhost;dbname=ninefrmx_veterinaria','ninefrmx_root','Samuel20');
}catch(PDOException $e){
    echo "Error: ". $e->getMessage();
}

if($_SESSION['tipo'] == 'Administrador'){
    $consulta = $conexion -> prepare( "
SELECT * FROM administrador WHERE correo = '" . $_SESSION['correo'] . "'");
    $consulta ->execute();
    $consulta = $consulta ->fetchAll();

    if(!$consulta){
        $mensaje .= 'Usuario inexistente';
    }
}

elseif ($_SESSION['tipo'] == 'Veterinario'){
    $consulta = $conexion -> prepare( "
SELECT * FROM veterinario WHERE correo = '" . $_SESSION['correo'] . "'");
    $consulta ->execute();
    $consulta = $consulta ->fetchAll();

    if(!$consulta){
        $mensaje .= 'Usuario inexistente';
    }
}
elseif ($_SESSION['tipo'] == 'Cajero'){
    $consulta = $conexion -> prepare( "
SELECT * FROM cajero WHERE correo = '" . $_SESSION['correo'] . "'");
    $consulta ->execute();
    $consulta = $consulta ->fetchAll();

    if(!$consulta){
        $mensaje .= 'Usuario inexistente';
    }
}

elseif ($_SESSION['tipo'] == 'Cliente'){
    $consulta = $conexion -> prepare( "
        SELECT * FROM cliente WHERE correo = '" . $_SESSION['correo'] . "'");
    $consulta ->execute();
    $consulta = $consulta ->fetchAll();

    if(!$consulta){
        $mensaje .= 'Usuario inexistente';
    }
}


?>
<?php include 'Plantilla/Header.php'; ?>
<section class="main">
    <div class="wrapp">
        <?php include 'Plantilla/Nav.php'; ?>

        <article>
            <div class="Mensaje">
                <h2>Perfil</h2>

            </div>
            <p><img src="Img\CompanyImage.png">
            </p><br/><br/>
            <br/><br/>

            <h2 class="mayusculas"> Bienvenido, <?php print_r($_SESSION['nombre']) ?> - <?php print_r($_SESSION['tipo']) ?>.</h2>
            <p></p>
            <?php foreach ($consulta as $Sql): ?>
                <tr>
                    <p>Nombre: <?php echo "<td>". $Sql['nombre']. "</td>"; ?>
                        <?php echo "<td>". $Sql['apellido_p']. "</td>"; ?>
                        <?php echo "<td>". $Sql['apellido_m']. "</td>"; ?></p>

                    <p>Fecha Nacimiento: <?php echo "<td> ". date("d-m-Y", strtotime($Sql['fecha_nac'])). "</td>"; ?>
                    </p>
                    <p>Correo Electronico: <?php echo "<td>". $Sql['correo']. "</td>"; ?>
                    </p>
                    <p>Teléfono: <?php echo "<td>". $Sql['telefono']. "</td>"; ?>
                    </p>
                    <p> Domicilio: <?php echo "<td>". $Sql['calle']. "</td>"; ?>
                        <?php echo "<td>". $Sql['numero_domicilio']. "</td>"; ?>
                        <?php echo "<td>". $Sql['colonia']. "</td>"; ?>
                        <?php echo "<td>". $Sql['codigo_postal']. "</td>"; ?></p>

                </tr>
            <?php endforeach; ?>
        </article>

    </div>
</section>
<?php include 'Plantilla/PieDePagina.php'; ?>
</body>
</html>
