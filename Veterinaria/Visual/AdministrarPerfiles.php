<html>
<body>
<?php
$mensaje='';
try{
    $conexion = new PDO('mysql:host=localhost;dbname=ninefrmx_veterinaria','ninefrmx_root','Samuel20');
}catch(PDOException $e){
    echo "Error: ". $e->getMessage();
}

$administradores = $conexion -> prepare("
	SELECT * FROM administrador WHERE activo = 1");
//Cajeros
$cajeros = $conexion -> prepare("
	SELECT * FROM cajero WHERE activo = 1");
//Veterinarios
$veterinarios = $conexion -> prepare("
	SELECT * FROM veterinario WHERE activo = 1");
//Cliente
$clientes = $conexion -> prepare("
	SELECT * FROM cliente WHERE activo = 1");
//
//Administradores
$administradores ->execute();
$administradores = $administradores ->fetchAll();
//Cajeros
$cajeros ->execute();
$cajeros = $cajeros ->fetchAll();
//Veterinarios
$veterinarios ->execute();
$veterinarios = $veterinarios ->fetchAll();
//Clientes
$clientes ->execute();
$clientes = $clientes ->fetchAll();


?>
<?php include 'Plantilla/Header.php'; ?>
<section class="main">
    <div class="wrapp">
        <?php include 'Plantilla/Nav.php'; ?>
        <article>
            <div class="mensaje">
                <h2>USUARIOS REGISTRADOS: <p>
                        <?php if ($_SESSION['tipo'] == 'Administrador') {
                            echo count($administradores)  + count($cajeros) + count($veterinarios) + count($clientes);
                        } elseif($_SESSION['tipo'] == 'Cajero' || $_SESSION['tipo'] == 'Veterinario'){
                            echo count($clientes);
                        } ?>
                    </p></h2>

            </div>
            <?php if ($_SESSION['tipo'] == 'Administrador'){ ?>
                    <a class="agregar" href="UpImage.php">Agregar Administrador</a>
                    <a class="agregar" href="UpImage.php">Agregar Veterinario</a>
                    <a class="agregar" href="UpImage.php">Agregar Cajero</a>
                    <a class="agregar" href="UpImage.php">Agregar Cliente</a>
            <?php }elseif($_SESSION['tipo'] == 'Cajero' || $_SESSION['tipo'] == 'Veterinario' || $_SESSION['tipo'] == 'Administrador'){ ?>
                    <a class="agregar" href="UpImage.php">Agregar Cliente</a>
             <?php   } ?>
            <table class="tabla">
                <tr>
                    <th>NOMBRE</th>
                    <th>TIPO</th>
                    <th>CORREO</th>
                    <th colspan="3">ACCIONES</th>

                </tr>
                    <?php if ($_SESSION['tipo'] == 'Administrador') foreach ($administradores as $Sql): ?>
                    <tr>
                    <?php echo "<td>". $Sql['nombre'] ." ".  $Sql['apellido_p']. " ".  $Sql['apellido_m']. "</td>"; ?>
                    <?php echo "<td>". $Sql['tipo']."</td>"; ?>
                    <?php echo "<td>". $Sql['correo']. "</td>"; ?>
                    <?php echo "<td class='centrar'>"."<a href='VerAdministrador.php?id=".$Sql['id_administrador']."' class='Ver'>Ver</a>". "</td>"; ?>
                    <?php echo "<td class='centrar'>"."<a href='EditarAdministrador.php?id=".$Sql['id_administrador']."' class='editar'>Editar</a>". "</td>"; ?>
                    <?php echo "<td class='centrar'>"."<a href='EliminarAdministrador.php?id=".$Sql['id_administrador']."' class='eliminar'>Eliminar</a>". "</td>"; ?>
                    </tr>
                    <?php endforeach; ?>

<!--                Veterinarios-->
                <?php if ($_SESSION['tipo'] == 'Administrador') foreach ($veterinarios as $Sql): ?>
                    <tr>
                        <?php echo "<td>". $Sql['nombre'] ." ".  $Sql['apellido_p']. " ".  $Sql['apellido_m']. "</td>"; ?>
                        <?php echo "<td>". $Sql['tipo']."</td>"; ?>
                        <?php echo "<td>". $Sql['correo']. "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='VerAdministrador.php?id=".$Sql['id_veterinario']."' class='Ver'>Ver</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EditarAdministrador.php?id=".$Sql['id_veterinario']."' class='editar'>Editar</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EliminarAdministrador.php?id=".$Sql['id_veterinario']."' class='eliminar'>Eliminar</a>". "</td>"; ?>
                    </tr>
                <?php endforeach; ?>
<!--                Cajeros-->
                <?php if ($_SESSION['tipo'] == 'Administrador') foreach ($cajeros as $Sql): ?>
                    <tr>
                        <?php echo "<td>". $Sql['nombre'] ." ".  $Sql['apellido_p']. " ".  $Sql['apellido_m']. "</td>"; ?>
                        <?php echo "<td>". $Sql['tipo']."</td>"; ?>
                        <?php echo "<td>". $Sql['correo']. "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='VerAdministrador.php?id=".$Sql['id_cajero']."' class='Ver'>Ver</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EditarAdministrador.php?id=".$Sql['id_cajero']."' class='editar'>Editar</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EliminarAdministrador.php?id=".$Sql['id_cajero']."' class='eliminar'>Eliminar</a>". "</td>"; ?>
                    </tr>
                <?php endforeach; ?>
<!--                Clientes-->
                <?php if ($_SESSION['tipo'] == 'Administrador' || $_SESSION['tipo'] == 'Veterinario' || $_SESSION['tipo'] == 'Cajero') foreach ($clientes as $Sql): ?>
                    <tr>
                        <?php echo "<td>". $Sql['nombre'] ." ".  $Sql['apellido_p']. " ".  $Sql['apellido_m']. "</td>"; ?>
                        <?php echo "<td>". $Sql['tipo']."</td>"; ?>
                        <?php echo "<td>". $Sql['correo']. "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='VerAdministrador.php?id=".$Sql['id_cliente']."' class='Ver'>Ver</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EditarAdministrador.php?id=".$Sql['id_cliente']."' class='editar'>Editar</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EliminarAdministrador.php?id=".$Sql['id_cliente']."' class='eliminar'>Eliminar</a>". "</td>"; ?>
                    </tr>
                <?php endforeach; ?>
            </table>
            <?php  if(!empty($mensaje)): ?>
                <ul>
                    <?php echo $mensaje; ?>
                </ul>
            <?php  endif; ?>
            <a class="btn-regresar" onclick="goBack()">Regresar</a>
            <script>
                function goBack() {
                    window.history.back();
                }
            </script>
        </article>
    </div>
</section>
<?php include 'Plantilla/PieDePagina.php'; ?>
</body>
</html>
