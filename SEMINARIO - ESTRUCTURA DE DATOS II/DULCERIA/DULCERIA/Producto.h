#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <sstream>

class Producto
{
	private:
		char Codigo[10];
		char Descripcion[30];
		char Precio[20];
		int Estado = 1;
		int Buff, Buff2, Buff3, Buff4;
	public:
		void Agregar();
		void Mostrar();
		void Modificar();
		void Eliminar();
		void Buscar();
		void AgregarCodigo(char Dato[10]);
		void AgregarDescripcion(char Dato[30]);
		void AgregarPrecio(char Dato[20]);
		void ReturnCodigo(char* outStr);
		void ReturnDescripcion(char* outStr);
		void ReturnPrecio(char* outStr);
		int ReturnBuff();
		int ReturnBuff2();
		int ReturnBuff3();
		int ReturnBuff4();
		int ReturnEstado();

		void AgregarBuff(int A);
		void AgregarBuff2(int A);
		void AgregarBuff3(int A);
		void AgregarBuff4(int A);
		void AgregarEstado(int A);
};

