#include <iostream>
using namespace std;

#include "Examen.h"
#include "Fecha.h"

void ListarExamenes()
{
	Examen obj;
	FILE* p = fopen("examenes.dat", "rb");
	if (p == nullptr) { return; }
	while (fread(&obj, sizeof(Examen), 1, p) == 1)
	{
		cout << obj.toString() << endl;
	}
	fclose(p);
}

int BuscarMejorNota(int materia, int legajo)
{
	//TO DO
	return 0;
}

int main() {
	int opcion;
	
	do
	{
		std::cout << "MENU PRINCIPAL" << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << "1 - CARGAR EXAMEN" << std::endl;
		std::cout << "2 - LISTAR EXAMENES" << std::endl;
		std::cout << "3 - BUSCAR MEJOR NOTA" << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << "0 - SALIR" << std::endl;
		std::cin >> opcion;
		switch (opcion)
		{
			case 1:
			{
				std::cout << "CARGAR EXAMEN" << std::endl;
				std::cout << "----------------------------" << std::endl;
				//Un examen a la vez. 
				//OPCIONAL: No puede repetirse la combinación de Legajo, IDMateria y Fecha.
			}
			break;
			case 2:
			{
				std::cout << "LISTAR EXAMENES" << std::endl;
				std::cout << "----------------------------" << std::endl;
				//Listar el total de examenes
			}
			break;
			case 3:
			{
				std::cout << "BUSCAR MEJOR NOTA" << std::endl;
				std::cout << "----------------------------" << std::endl;
				//utilizar funcion BuscarMejorNota
			}
			break;
			case 0:
				return 0;
		}
	} while (opcion);


  
  return 0;
}