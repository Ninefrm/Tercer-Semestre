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
		float Precio;
		int Estado = 1;
		int Buff, Buff2, Buff3, Buff4;
	public:
		void Agregar();
		void Mostrar();
		void Modificar();
		void Eliminar();
		void Buscar();
};

