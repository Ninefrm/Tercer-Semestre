<aside>
	<div class="widget">
			<a href="index.php" title="VeterinariaOnline">Inicio</a>
			<a href="Perfil.php" title="Ver tu perfil">Perfil</a>
            <a href="Mascotas.php" title="Catalogo de Mascotas">Mascotas</a>
            <a href="Tienda.php" title="Ver la tienda">Tienda</a>
            <?php if ($_SESSION['tipo'] == 'Cajero' || $_SESSION['tipo'] == 'Veterinario' || $_SESSION['tipo'] == 'Administrador'){ ?>
                <a href="AdministrarPerfiles.php" title="Administrar perfiles">Admininistrar Perfiles</a>
            <?php } ?>


	</div>
</aside>
