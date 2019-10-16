// CodeVita1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <math.h>

/*
1 <= T <= 1000

-10^7 <= a, b <= 10^7

0 <= n1, n2 <= 10^7
*/

int main()
{
	int n1, n2;
	int a, b;
	int unsigned x;
	while (n1 && n2 < 0 || n1 && n2 > pow(10, 7)) {
		std::cin >> n1;
		std::cin >> n2;
	}
	x = (n1 * a) + (n2 * b);


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
