<html>
<body>
<?php
$mensaje='';
try{
    $conexion = new PDO('mysql:host=localhost;dbname=ninefrmx_veterinaria','ninefrmx_root','Samuel20');
}catch(PDOException $e){
    echo "Error: ". $e->getMessage();
}

$productos = $conexion -> prepare("
	SELECT * FROM producto WHERE activo = 1");
//Cajeros
$servicios = $conexion -> prepare("
	SELECT * FROM servicio WHERE activo = 1");

//
//Administradores
$productos ->execute();
$productos = $productos ->fetchAll();
//Cajeros
$servicios ->execute();
$servicios = $servicios ->fetchAll();

?>
<?php include 'Plantilla/Header.php'; ?>
<section class="main">
    <div class="wrapp">
        <?php include 'Plantilla/Nav.php'; ?>
        <article>
            <div class="mensaje">
                <h2>Tienda</h2>

            </div>
            <?php if ($_SESSION['tipo'] == 'Administrador'){ ?>
                <a class="agregar" href="UpImage.php">Agregar Servicio</a>
                <a class="agregar" href="UpImage.php">Agregar Producto</a>
            <?php }?>
            <table class="tabla">
                <tr>
                    <th>NOMBRE</th>
                    <th>DESCRIPCIÓN</th>
                    <th>PRECIO</th>
                    <th colspan="2">ACCIONES</th>

                </tr>
                <?php foreach ($productos as $Sql): ?>
                    <tr>
                        <?php echo "<td>". $Sql['nombre'] ." </td>"; ?>
                        <?php echo "<td>". $Sql['descripcion']."</td>"; ?>
                        <?php echo "<td>". $Sql['costo']. "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='VerAdministrador.php?id=".$Sql['id_administrador']."' class='Ver'>Ver</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EditarAdministrador.php?id=".$Sql['id_administrador']."' class='editar'>Editar</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EliminarAdministrador.php?id=".$Sql['id_administrador']."' class='eliminar'>Eliminar</a>". "</td>"; ?>
                    </tr>
                <?php endforeach; ?>

                <!--                servicios-->
                <?php foreach ($servicios as $Sql): ?>
                    <tr>
                        <?php echo "<td>". $Sql['nombre'] ." </td>"; ?>
                        <?php echo "<td>". $Sql['descripcion']."</td>"; ?>
                        <?php echo "<td>". $Sql['costo']. "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='VerAdministrador.php?id=".$Sql['id_veterinario']."' class='Ver'>Ver</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EditarAdministrador.php?id=".$Sql['id_veterinario']."' class='editar'>Editar</a>". "</td>"; ?>
                        <?php echo "<td class='centrar'>"."<a href='EliminarAdministrador.php?id=".$Sql['id_veterinario']."' class='eliminar'>Eliminar</a>". "</td>"; ?>
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
