#include "Producto.h"

void Producto::Agregar()
{
	std::cout << "CODIGO DEL PRODUCTO:" << std::endl;
	std::cin.getline(Codigo, 10);
	std::cout << "DESCRIPCIÓN DEL PRODUCTO:" << std::endl;
	std::cin.getline(Descripcion, 30);
	std::cout << "ESCRIBIR PRECIOS:" << std::endl;
	std::cin.getline(Precio, 20);
	std::ofstream Archivo("Productos.txt", std::ios::app);
	Buff = strlen(Codigo);
	Buff2 = strlen(Descripcion);
	Buff3 = strlen(Precio);
	Buff4 = Estado;

	Archivo.write((char*) &Buff, sizeof(int));
	Archivo.write((char*) &Codigo, Buff);
	Archivo.write((char*)& Buff2, sizeof(int));
	Archivo.write((char*)& Descripcion, Buff2);
	Archivo.write((char*)& Buff3, sizeof(int));
	Archivo.write((char*)& Precio, Buff3);
	Archivo.write((char*)& Buff4, sizeof(int));
	Archivo.write((char*)& Estado, Buff4);

	Archivo.close();
}

void Producto::Mostrar()
{
	std::ifstream Archivo("Productos.txt");
	if (!Archivo.good()) {
		std::cout << "No existe el archivo." << std::endl;
	}
	else {
		std::cout << "CODIGO" << "		DESCRIPCION" << "		PRECIO" << std::endl;
		while (!Archivo.eof()) {
			Archivo.read((char*)& Buff, sizeof(int));
			Archivo.read((char*)& Codigo, Buff);
			Codigo[Buff] = '\0';
			Archivo.read((char*)& Buff2, sizeof(int));
			Archivo.read((char*)& Descripcion, Buff2);
			Descripcion[Buff2] = '\0';
			Archivo.read((char*)& Buff3, sizeof(int));
			Archivo.read((char*)& Precio, Buff3);
			Precio[Buff3] = '\0';
			Archivo.read((char*)& Buff4, sizeof(int));
			Archivo.read((char*)& Estado, Buff4);
			if (Archivo.eof())break;
			std::cout << Codigo << "		" << Descripcion << "		" << Precio << "." << std::endl;
		}
	}
	Archivo.close();
}

void Producto::Modificar()
{
	int T = 1;
	int OP;
	std::string Tmp;
	char wNombre[30];
	std::cout << "Producto a buscar: ";
	std::cin.getline(wNombre, 10);
	//std::cout << wNombre;
	std::ifstream Archivo("Productos.txt");
	std::ofstream File("tmp.txt", std::ios::app);
	if (!Archivo.good()) std::cout << "Error";
	else

		while (!Archivo.eof()) {
			//std::cout << "We are here" << std::endl;
			Archivo.read((char*)& Buff, sizeof(int));
			Archivo.read((char*)& Codigo, Buff);
			Codigo[Buff] = '\0';
			Archivo.read((char*)& Buff2, sizeof(int));
			Archivo.read((char*)& Descripcion, Buff2);
			Descripcion[Buff2] = '\0';
			Archivo.read((char*)& Buff3, sizeof(int));
			Archivo.read((char*)& Precio, Buff3);
			//std::cout << "We are here 2" << std::endl;
			Archivo.read((char*)& Buff4, sizeof(int));
			Archivo.read((char*)& Estado, Buff4);
			//std::cout << "We are here 3" << std::endl;
			//if (Archivo.eof())break;
			/*std::cout << wNombre;
			std::cout << Codigo;
			std::cout << strcmp(Codigo, wNombre);*/
			if ((Estado) && !strcmp(Codigo, wNombre)) {
				while (T) {
					std::cout << "Editador:" << std::endl;
					std::cout << "1.- Codigo." << std::endl;
					std::cout << "2.- Descripcion." << std::endl;
					std::cout << "3.- Precio." << std::endl;
					//std::cout << "4.- Estado.:" << std::endl;
					std::cout << "5.- Salir" << std::endl;

					std::cin >> OP;
					std::cin.ignore();
					switch (OP)
					{
					default:
						T = 0;
						break;
					case 1:
						std::cin.getline(Codigo, 10);
						break;
					case 2:
						std::cin.getline(Descripcion, 35);
						break;
					case 3:
						std::cin >> Precio;
						break;
					}
				}
			}
			
			Buff = strlen(Codigo);
			Buff2 = strlen(Descripcion);
			Buff3 = strlen(Precio);
			Buff4 = Estado;
			File.write((char*)& Buff, sizeof(int));
			File.write((char*)& Codigo, Buff);
			File.write((char*)& Buff2, sizeof(int));
			File.write((char*)& Descripcion, Buff2);
			File.write((char*)& Buff3, sizeof(int));
			File.write((char*)& Precio, Buff3);
			File.write((char*)& Buff4, sizeof(int));
			File.write((char*)& Estado, Buff4);

		}Archivo.close(); File.close();
		remove("Productos.txt");
		rename("tmp.txt", "Productos.txt");
}

void Producto::Eliminar()
{
	int T = 1;
	int OP;
	std::string Tmp;
	char wNombre[30];
	std::cout << "Producto a buscar: ";
	std::cin.getline(wNombre, 10);
	//std::cout << wNombre;
	std::ifstream Archivo("Productos.txt");
	std::ofstream File("tmp.txt", std::ios::app);
	if (!Archivo.good()) std::cout << "Error";
	else

		while (!Archivo.eof()) {
			//std::cout << "We are here" << std::endl;
			Archivo.read((char*)& Buff, sizeof(int));
			Archivo.read((char*)& Codigo, Buff);
			Codigo[Buff] = '\0';
			Archivo.read((char*)& Buff2, sizeof(int));
			Archivo.read((char*)& Descripcion, Buff2);
			Descripcion[Buff2] = '\0';
			Archivo.read((char*)& Buff3, sizeof(int));
			Archivo.read((char*)& Precio, Buff3);
			//std::cout << "We are here 2" << std::endl;
			Archivo.read((char*)& Buff4, sizeof(int));
			Archivo.read((char*)& Estado, Buff4);
			//std::cout << "We are here 3" << std::endl;
			//if (Archivo.eof())break;
			/*std::cout << wNombre;
			std::cout << Codigo;
			std::cout << strcmp(Codigo, wNombre);*/
			if (strcmp(Codigo, wNombre)) {
				Buff = strlen(Codigo);
				Buff2 = strlen(Descripcion);
				Buff3 = strlen(Precio);
				Buff4 = Estado;
				File.write((char*)& Buff, sizeof(int));
				File.write((char*)& Codigo, Buff);
				File.write((char*)& Buff2, sizeof(int));
				File.write((char*)& Descripcion, Buff2);
				File.write((char*)& Buff3, sizeof(int));
				File.write((char*)& Precio, Buff3);
				File.write((char*)& Buff4, sizeof(int));
				File.write((char*)& Estado, Buff4);
			}
			if (!strcmp(Codigo, wNombre) && (!Estado)) {
				Buff = strlen(Codigo);
				Buff2 = strlen(Descripcion);
				Buff3 = strlen(Precio);
				Buff4 = Estado;
				File.write((char*)& Buff, sizeof(int));
				File.write((char*)& Codigo, Buff);
				File.write((char*)& Buff2, sizeof(int));
				File.write((char*)& Descripcion, Buff2);
				File.write((char*)& Buff3, sizeof(int));
				File.write((char*)& Precio, Buff3);
				File.write((char*)& Buff4, sizeof(int));
				File.write((char*)& Estado, Buff4);
			}

		}Archivo.close(); File.close();
		remove("Productos.txt");
		rename("tmp.txt", "Productos.txt");

}

void Producto::Buscar()
{
	std::string Tmp;
	char wNombre[30];
	std::cout << "Producto a buscar: ";
	std::cin.getline(wNombre, 10);
	//std::cout << wNombre;
	std::ifstream Archivo("Productos.txt");
	if (!Archivo.good()) std::cout << "Error";
	else
		
	while (!Archivo.eof()) {
		//std::cout << "We are here" << std::endl;
		Archivo.read((char*)& Buff, sizeof(int));
		Archivo.read((char*)& Codigo, Buff);
		Codigo[Buff] = '\0';
		Archivo.read((char*)& Buff2, sizeof(int));
		Archivo.read((char*)& Descripcion, Buff2);
		Descripcion[Buff2] = '\0';
		Archivo.read((char*)& Buff3, sizeof(int));
		Archivo.read((char*)& Precio, Buff3);
		//std::cout << "We are here 2" << std::endl;
		Archivo.read((char*)& Buff4, sizeof(int));
		Archivo.read((char*)& Estado, Buff4);
		//std::cout << "We are here 3" << std::endl;
		//if (Archivo.eof())break;
		/*std::cout << wNombre;
		std::cout << Codigo;
		std::cout << strcmp(Codigo, wNombre);*/
		if ((Estado) && !strcmp(Codigo, wNombre)) {
			std::cout << "CODIGO" << "		DESCRIPCION" << "		PRECIO" << std::endl;
			std::cout << Codigo << "		" << Descripcion << "		" << Precio << "." << std::endl;
		}
	}Archivo.close();
}

void Producto::AgregarCodigo(char Dato[10])
{
	strcpy_s(Codigo, 10, Dato);
}

void Producto::AgregarDescripcion(char Dato[30])
{
	strcpy_s(Descripcion, 30, Dato);
}

void Producto::AgregarPrecio(char Dato[20])
{
	strcpy_s(Precio, 20, Dato);
}

void Producto::ReturnCodigo(char* outStr)
{
	for (int i = 0; i < sizeof(Codigo); ++i) {
		outStr[i] = Codigo[i];
	}
}

void Producto::ReturnDescripcion(char* outStr)
{
	for (int i = 0; i < sizeof(Descripcion); ++i) {
		outStr[i] = Descripcion[i];
	}
}

void Producto::ReturnPrecio(char* outStr)
{
	for (int i = 0; i < 20; ++i) {
		outStr[i] = Precio[i];
	}
}

int Producto::ReturnBuff()
{
	return Buff;
}

int Producto::ReturnBuff2()
{
	return Buff2;
}

int Producto::ReturnBuff3()
{
	return Buff3;
}

int Producto::ReturnBuff4()
{
	return Buff4;
}

int Producto::ReturnEstado()
{
	return Estado;
}

void Producto::AgregarBuff(int A)
{
	Buff = A;
}

void Producto::AgregarBuff2(int A)
{
	Buff2 = A;
}

void Producto::AgregarBuff3(int A)
{
	Buff3 = A;
}

void Producto::AgregarBuff4(int A)
{
	Buff4 = A;
}

void Producto::AgregarEstado(int A)
{
	Estado = A;
}
