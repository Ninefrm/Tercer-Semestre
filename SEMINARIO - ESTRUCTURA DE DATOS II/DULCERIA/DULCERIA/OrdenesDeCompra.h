#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include "Proveedor.h"
#include "Producto.h"

class OrdenesDeCompra
{
public:
	Proveedor Proveedor;
	Producto Producto;
	char Fecha[10], Pago[7], Entrega[30], Firma[9];
	int Cantidad = 0;
	float Total = 0.0;
	void Agregar();
	void Mostrar();
	void Modificar();
	void Eliminar();
	void Buscar();
	void BuscarProducto();
	void BuscarProveedor();
};

