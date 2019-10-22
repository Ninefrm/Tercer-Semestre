<html>
<body>

<?php include 'Plantilla/Header.php'; ?>
<section class="main">
    <div class="wrapp">
        <?php include 'Plantilla/Nav.php'; ?>

        <article>
            <div class="Mensaje">
                <h2>Veterinaria Online</h2>

            </div>
            <p><img src="Img\CompanyImage.png">
            </p><br/><br/>
            <br/><br/>

            <h2 class="mayusculas"> Bienvenido, <?php print_r($_SESSION['nombre']) ?> - <?php print_r($_SESSION['tipo']) ?>.</h2>
            <p></p>
            <h3> Estas son nuestras funciones para: <h3>
                    <h4> &nbsp;&nbsp;&nbsp;&nbsp;CLIENTES</h4>
                    <p>	 &nbsp;&nbsp;&nbsp; - PERFIL <br/>
                        &nbsp;&nbsp;&nbsp;&nbsp;- CATALOGO DE TUS MASCOTAS <br/>
                        &nbsp;&nbsp;&nbsp;&nbsp;- VENTA DE PRODUCTOS Y SERVICIOS <br/>
                    <br/>
                    <br/>

                    </p>
        </article>

    </div>
</section>
<?php include 'Plantilla/PieDePagina.php'; ?>
</body>
</html>
