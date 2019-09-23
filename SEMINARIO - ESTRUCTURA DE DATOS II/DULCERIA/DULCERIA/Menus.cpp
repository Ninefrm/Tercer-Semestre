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
			ProveedorM.AgregarProveedor();
			break;
		case 2:
			ProveedorM.ImprimirProveedores();
			break;
		case 3:
			ProveedorM.BuscarProveedores();
			break;
		case 4:
			ProveedorM.ModificarProveedores();
			break;
		case 5:
			ProveedorM.EliminarProveedor();
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
			ProductoM.Agregar();
			break;
		case 2:
			ProductoM.Mostrar();
			break;
		case 3:
			ProductoM.Modificar();
			break;
		case 4:
			ProductoM.Eliminar();
			break;
		case 5:
			ProductoM.Buscar();
			break;
		}
	}
}

void Menus::OrdenesDeCompraMenu()
{
	int OP;
	int W = 1;
	while (W)
	{
		std::cout << "1.- Agregar Orden de compra." << std::endl;
		std::cout << "2.- Imprimir Ordenes de compra." << std::endl;
		std::cout << "3.- Modificar Ordenes de compra." << std::endl;
		std::cout << "4.- Eliminar Orden de compra." << std::endl;
		std::cout << "5.- Buscar Orden de compra." << std::endl;
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
			OrdenDeCompra.Agregar();
			break;
		case 2:
			OrdenDeCompra.Mostrar();
			break;
		case 3:
			OrdenDeCompra.Modificar();
			break;
		case 4:
			OrdenDeCompra.Eliminar();
			break;
		case 5:
			OrdenDeCompra.Buscar();
			break;
		}
	}
}
