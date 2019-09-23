#pragma once
#include <iostream>
#include "Proveedor.h"
#include "Producto.h"
#include "OrdenesDeCompra.h"

class Menus
{
	public:
		Proveedor ProveedorM;
		Producto ProductoM;
		OrdenesDeCompra OrdenDeCompra;
	
		void ProveedorMenu();
		void ProductoMenu();
		void OrdenesDeCompraMenu();
};

