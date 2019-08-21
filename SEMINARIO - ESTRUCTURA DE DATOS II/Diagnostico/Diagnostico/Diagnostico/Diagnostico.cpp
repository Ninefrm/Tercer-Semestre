// Diagnostico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <list>

struct Dato
{
	int A;
	Dato *B;
}*A;

void insertar(int Entero);
void imprimir(Dato W);

int main()
{
	int op, N;
	std::cout << "1.- Agregar." << std::endl;
	std::cout << "2.- Imprimir." << std::endl;
	std::cin >> op;
	if (1) {
		std::cout << "Número: ";
		std::cin >> N;
		insertar(N);
	}
	if (2) {
		imprimir(*A);
	}
}

void insertar(int Entero) {
	if (!A) {
		A = new(Dato);
		A->B = NULL;
		A->A = Entero;
			return;
	}
	A->B->A = Entero;
	A->B->B = NULL;
	return;
}

void imprimir(Dato W) {
	if (W->A) {
		std::cout << W->A;
	}
	else(imprimir(W - B));
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
