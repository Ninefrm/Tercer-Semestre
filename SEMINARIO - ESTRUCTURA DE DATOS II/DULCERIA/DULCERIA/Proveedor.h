#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <sstream>

class Proveedor
{
	private:
		char NombreEmpresa[20];
		char Telefono[15];
		char Direccion[30];
		char Apellidos[30];
		char Nombre[30];
		int Estado = 1;
	public:	
		void AgregarProveedor();
		void ImprimirProveedores();
		void BuscarProveedores();
		void ModificarProveedores();
		void EliminarProveedor();
};

