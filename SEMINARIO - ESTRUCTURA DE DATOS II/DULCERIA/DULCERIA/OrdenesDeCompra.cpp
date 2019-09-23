#include "OrdenesDeCompra.h"

void OrdenesDeCompra::Agregar()
{
	OrdenesDeCompra OrdenDeCompra;
	BuscarProveedor();
	std::cin.ignore();
	BuscarProducto();
	std::cin >> Cantidad;
	std::cin.getline(Fecha, 10);
	std::cin.getline(Pago, 7);
	std::cin.getline(Entrega, 30);
	std::cin.getline(Firma, 9);
	//char PrecioT[20];
	//Producto.ReturnPrecio(PrecioT);
	Total = Cantidad;
	std::ofstream Archivo("OrdenDeCompra.txt", std::ios::app);
	Archivo.write((char*)&OrdenDeCompra, sizeof(OrdenDeCompra));
	Archivo.close();
}

void OrdenesDeCompra::Mostrar()
{
}

void OrdenesDeCompra::Modificar()
{
}

void OrdenesDeCompra::Eliminar()
{
}

void OrdenesDeCompra::Buscar()
{
}

void OrdenesDeCompra::BuscarProducto()
{
	char Codigo[10];
	char Descripcion[30];
	char Precio[20];
	int Estado = 1;
	int Buff, Buff2, Buff3, Buff4;
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
			//std::cout << "DESCRIPCION: " << Descripcion << std::endl;
			Descripcion[Buff2] = '\0';
			Archivo.read((char*)& Buff3, sizeof(int));
			Archivo.read((char*)& Precio, Buff3);
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
				Producto.AgregarCodigo(Codigo);
				Producto.AgregarDescripcion(Descripcion);
				Producto.AgregarPrecio(Precio);
			}
		}Archivo.close();
}

void OrdenesDeCompra::BuscarProveedor()
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
			Archivo.read((char*)& Producto.ReturnBuff, sizeof(int));
			Archivo.read((char*)& Producto.Codigo, Producto.ReturnBuff);
			Producto.ReturnCodigo[Producto.ReturnBuff] = '\0';
			Archivo.read((char*)& Producto.Buff2, sizeof(int));
			Archivo.read((char*)& Producto.Descripcion, Producto.Buff2);
			Producto.Descripcion[Producto.Buff2] = '\0';
			Archivo.read((char*)& Producto.Buff3, sizeof(int));
			Archivo.read((char*)& Producto.Precio, Producto.Buff3);
			//std::cout << "We are here 2" << std::endl;
			Archivo.read((char*)& Producto.Buff4, sizeof(int));
			Archivo.read((char*)& Producto.Estado, Producto.Buff4);
			//std::cout << "We are here 3" << std::endl;
			//if (Archivo.eof())break;
			/*std::cout << wNombre;
			std::cout << Codigo;
			std::cout << strcmp(Codigo, wNombre);*/
			if ((Producto.Estado) && !strcmp(Producto.Codigo, wNombre)) {
				std::cout << "CODIGO" << "		DESCRIPCION" << "		PRECIO" << std::endl;
				std::cout << Producto.Codigo << "		" << Producto.Descripcion << "		" << Producto.Precio << "." << std::endl;
			}
		}Archivo.close();
}
