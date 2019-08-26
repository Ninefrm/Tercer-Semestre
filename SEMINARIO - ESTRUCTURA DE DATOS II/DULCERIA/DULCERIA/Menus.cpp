#include "Menus.h"

void Menus::ProveedorMenu()
{
	int OP;
	int W = 1;
	while (W)
	{
		std::cout << "1.- Agregar Proveedor." << std::endl;
		std::cout << "2.- Imprimir Proveedores." << std::endl;
		std::cout << "3.- Buscar Proveedor." << std::endl;
		std::cout << "4.- Modificar Proveedor." << std::endl;
		std::cout << "5.- Eliminar Proveedor." << std::endl;
		std::cout << "6.- Salir" << std::endl;
		std::cout << "Elegir: ";
		std::cin >> OP;
		std::cin.ignore();
		switch (OP)
		{
		default:
			W = 0;
			break;
		case 1:
			Proveedor.AgregarProveedor();
			break;
		case 2:
			Proveedor.ImprimirProveedores();
			break;
		case 3:
			Proveedor.BuscarProveedores();
			break;
		case 4:
			Proveedor.ModificarProveedores();
			break;
		case 5:
			Proveedor.EliminarProveedor();
			break;
		}
	}
}

void Menus::ProductoMenu()
{
	int OP;
	int W = 1;
	while (W)
	{
		std::cout << "1.- Agregar Producto." << std::endl;
		std::cout << "2.- Imprimir Productos." << std::endl;
		std::cout << "3.- Modificar Producto." << std::endl;
		std::cout << "4.- Eliminar Producto." << std::endl;
		std::cout << "5.- Buscar Producto." << std::endl;
		std::cout << "6.- Salir" << std::endl;
		std::cout << "Elegir: ";
		std::cin >> OP;
		std::cin.ignore();
		switch (OP)
		{
		default:
			W = 0;
			break;
		case 1:
			Producto.Agregar();
			break;
		case 2:
			Producto.Mostrar();
			break;
		case 3:
			Producto.Modificar();
			break;
		case 4:
			Producto.Eliminar();
			break;
		case 5:
			Producto.Buscar();
			break;
		}
	}
}
