// DULCERIA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Proveedor.h"

int main()
{
	Proveedor A;
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
			A.AgregarProveedor();
		break;
		case 2:
			A.ImprimirProveedores();
		break;
		case 3:
			A.BuscarProveedores();
		break;
		case 4:
			A.ModificarProveedores();
		break;
		case 5:
			A.EliminarProveedor();
		break;
		}
	}
	

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
