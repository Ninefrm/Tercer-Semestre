<!DOCTYPE html>
<html >
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=decive-width, user-scalable=no, initial-scale=1.0, maximun-scale=1.0, minimun-scale=1.0">
    <title>Iniciar sesión - Veterinaria</title>
    <link rel="stylesheet" href="CSS\Login.css">
    <link rel="icon" type="image/x-svg" href="Img\Logo.png">
</head>
<body>

<form class="login" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']) ?>" method="post" name="login">
    <h2>VETERINARIA</h2>
    <img src="Img\Login_Icon.png">
    <input type="text" name="correo"placeholder="Correo" class="bordes" autofocus/>
    <input required type="password" name="password" placeholder="Contraseña" class="bordes"/>
    <input required type="submit" value="Ingresar">

    <?php  if(!empty($errores)): ?>
        <ul>
            <?php echo $errores; ?>
        </ul>
    <?php  endif; ?>
</form>
</body>
</html>
