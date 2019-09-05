#include "OrdenesDeCompra.h"

void OrdenesDeCompra::BuscarProducto()
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
