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

		void AgregarNombreEmpresa(char Dato[20]);
		void AgregarTelefono(char Dato[15]);
		void AgregarDireccion(char Dato[30]);
		void AgregarApellido(char Dato[30]);
		void AgregarNombre(char Dato[30]);
		void ReturnNombreEmpresa(char* outStr);
		void ReturnTelefono(char* outStr);
		void ReturnDireccion(char* outStr);
		void ReturnApellidos(char* outStr);
		void ReturnNombre(char* outStr);
};

