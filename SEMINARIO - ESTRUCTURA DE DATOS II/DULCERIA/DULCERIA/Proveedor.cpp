#include "Proveedor.h"

void Proveedor::AgregarProveedor()
{
	std::ofstream Write("Proveedor.txt", std::ios::app);
	std::cout << "Nombre empresa:" << std::endl;
	std::cin.getline(NombreEmpresa, 20);
	std::cout << "Teléfono:" << std::endl;
	std::cin.getline(Telefono, 15);
	std::cout << "Dirección:" << std::endl;
	std::cin.getline(Direccion, 30);
	std::cout << "Apellido representante:" << std::endl;
	std::cin.getline(Apellidos, 30);
	std::cout << "Nombre representante:" << std::endl;
	std::cin.getline(Nombre, 30);
	
	Write << NombreEmpresa << "#" << Telefono << "#" << Direccion << "#" << Apellidos << "#" << Nombre << "#" << Estado << '\n';

}

void Proveedor::ImprimirProveedores()
{
	std::string Tmp;
	
	std::ifstream Read("Proveedor.txt");
	if (!Read.good()) std::cout << "Error";
	else
		std::cout << "Nombre Proveedor		" << "Telefono		" << "Dirección		" << "Apellidos		" << "Nombre	" << std::endl;
	while (!Read.eof()) {
		getline(Read, Tmp, '#');
		strcpy_s(NombreEmpresa, 20, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Telefono, 15, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Direccion, 30, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Apellidos, 30, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Nombre, 30, Tmp.c_str());
		getline(Read, Tmp, '\n');
		std::stringstream Status(Tmp);
		Status >> Estado;
		if (Read.eof())break;
		if (Estado) {
			std::cout << NombreEmpresa << "		" << Telefono << "		" << Direccion << "		" << Apellidos << "		" << Nombre << std::endl;
		}
	}Read.close();
}

void Proveedor::BuscarProveedores()
{
	std::string Tmp;
	char wNombre[30];
	std::cout << "Proveedor a buscar: ";
	std::cin.getline(wNombre, 20);

	std::ifstream Read("Proveedor.txt");
	if (!Read.good()) std::cout << "Error";
	else
		std::cout << "Nombre Proveedor	" << "Telefono	" << "Dirección	" << "Nombre	" << "Apellido	" << std::endl;
	while (!Read.eof()) {
		getline(Read, Tmp, '#');
		strcpy_s(NombreEmpresa, 20, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Telefono, 15, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Direccion, 30, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Apellidos, 30, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Nombre, 30, Tmp.c_str());
		getline(Read, Tmp, '\n');
		std::stringstream Status(Tmp);
		Status >> Estado;
		if (Read.eof())break;
		/*std::cout << wNombre;
		std::cout << NombreEmpresa;
		std::cout << strcmp(NombreEmpresa, wNombre);*/
		if ((Estado) && !strcmp(NombreEmpresa,wNombre)){
			std::cout << NombreEmpresa << "		" << Telefono << "		" << Direccion << "		" << Apellidos << "		" << Nombre << std::endl;
		}
	}Read.close();

}

void Proveedor::ModificarProveedores()
{
	std::string Tmp;
	char wNombre[30];
	std::cout << "Proveedor a editar: ";
	std::cin.getline(wNombre, 20);
	int T = 1;
	int OP = 0;
	std::ifstream Read("Proveedor.txt");
	std::ofstream File("tmp.txt", std::ios::app);
	if (!Read.good()) std::cout << "Error";
	else
		
	while (!Read.eof()) {
		getline(Read, Tmp, '#');
		strcpy_s(NombreEmpresa, 20, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Telefono, 15, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Direccion, 30, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Apellidos, 30, Tmp.c_str());
		getline(Read, Tmp, '#');
		strcpy_s(Nombre, 30, Tmp.c_str());
		getline(Read, Tmp, '\n');
		std::stringstream Status(Tmp);
		Status >> Estado;
		if (Read.eof())break;
		/*std::cout << wNombre;
		std::cout << NombreEmpresa;
		std::cout << strcmp(NombreEmpresa, wNombre);*/
		if ((Estado) && !strcmp(NombreEmpresa, wNombre)) {
			while (T) {
				std::cout << "Editador:" << std::endl;
				std::cout << "1.- Nombre Empresa." << std::endl;
				std::cout << "2.- Telefono." << std::endl;
				std::cout << "3.- Direccion." << std::endl;
				std::cout << "4.- Apellidos.:" << std::endl;
				std::cout << "5.- Nombre.:" << std::endl;
				std::cout << "6.- Salir" << std::endl;

				std::cin >> OP;
				std::cin.ignore();
				switch (OP)
				{
				default:
					T = 0;
				break;
				case 1:
					std::cin.getline(NombreEmpresa, 20);
				break;
				case 2:
					std::cin.getline(Telefono, 15);
				break;
				case 3:
					std::cin.getline(Direccion, 30);
				break;
				case 4:
					std::cin.getline(Apellidos, 30);
				break;
				case 5:
					std::cin.getline(Nombre, 30);
				break;

				}
			}
		}
		File << NombreEmpresa << "#" << Telefono << "#" << Direccion << "#" << Apellidos << "#" << Nombre << "#" << Estado << '\n';
	}Read.close(); File.close();
	remove("Proveedor.txt");
	rename("tmp.txt", "Proveedor.txt");
}

void Proveedor::EliminarProveedor()
{
	std::string Tmp;
	char wNombre[30];
	std::cout << "Proveedor a eliminar: ";
	std::cin.getline(wNombre, 20);
	int T = 1;
	int OP = 0;
	std::ifstream Read("Proveedor.txt");
	std::ofstream File("tmp.txt", std::ios::app);
	if (!Read.good()) std::cout << "Error";
	else

		while (!Read.eof()) {
			getline(Read, Tmp, '#');
			strcpy_s(NombreEmpresa, 20, Tmp.c_str());
			getline(Read, Tmp, '#');
			strcpy_s(Telefono, 15, Tmp.c_str());
			getline(Read, Tmp, '#');
			strcpy_s(Direccion, 30, Tmp.c_str());
			getline(Read, Tmp, '#');
			strcpy_s(Apellidos, 30, Tmp.c_str());
			getline(Read, Tmp, '#');
			strcpy_s(Nombre, 30, Tmp.c_str());
			getline(Read, Tmp, '\n');
			std::stringstream Status(Tmp);
			Status >> Estado;
			if (Read.eof())break;
			/*std::cout << wNombre;
			std::cout << NombreEmpresa;
			std::cout << strcmp(NombreEmpresa, wNombre);*/
			if (strcmp(NombreEmpresa, wNombre)) {
				File << NombreEmpresa << "#" << Telefono << "#" << Direccion << "#" << Apellidos << "#" << Nombre << "#" << Estado << '\n';
			}
			if (!strcmp(NombreEmpresa, wNombre) && (!Estado) ){
				File << NombreEmpresa << "#" << Telefono << "#" << Direccion << "#" << Apellidos << "#" << Nombre << "#" << Estado << '\n';
			}
		}
			Read.close(); File.close();
		remove("Proveedor.txt");
		rename("tmp.txt", "Proveedor.txt");
}

void Proveedor::AgregarNombreEmpresa(char Dato[20])
{
	strcpy_s(NombreEmpresa, 20, Dato);
}

void Proveedor::AgregarTelefono(char Dato[15])
{
	strcpy_s(Telefono, 15, Dato);
}

void Proveedor::AgregarDireccion(char Dato[30])
{
	strcpy_s(Direccion, 30, Dato);
}

void Proveedor::AgregarApellido(char Dato[30])
{
	strcpy_s(Apellidos, 30, Dato);
}

void Proveedor::AgregarNombre(char Dato[30])
{
	strcpy_s(Nombre, 30, Dato);
}

void Proveedor::ReturnNombreEmpresa(char* outStr)
{
	for (int i = 0; i < sizeof(NombreEmpresa); ++i) {
		outStr[i] = NombreEmpresa[i];
	}
}

void Proveedor::ReturnTelefono(char* outStr)
{
	for (int i = 0; i < sizeof(Telefono); ++i) {
		outStr[i] = Telefono[i];
	}
}

void Proveedor::ReturnDireccion(char* outStr)
{
	for (int i = 0; i < sizeof(Direccion); ++i) {
		outStr[i] = Direccion[i];
	}
}

void Proveedor::ReturnApellidos(char* outStr)
{
	for (int i = 0; i < sizeof(Apellidos); ++i) {
		outStr[i] = Apellidos[i];
	}
}

void Proveedor::ReturnNombre(char* outStr)
{
	for (int i = 0; i < sizeof(Nombre); ++i) {
		outStr[i] = Nombre[i];
	}
}
