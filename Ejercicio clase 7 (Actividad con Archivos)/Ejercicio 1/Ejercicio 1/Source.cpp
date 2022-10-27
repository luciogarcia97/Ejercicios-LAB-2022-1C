#include <iostream>
using namespace std;

#include "rlutil.h"
#include "Examen.h"
#include "Fecha.h"

int buscarLegajo(int legajo)
{
	Examen obj;
	int cantidad = obj.getCantidad();
	for (int i = 0; i < cantidad; i++)
	{
		obj.leerDeDisco(i);
		if (obj.getLegajo() == legajo)
		{
			return i;
		}
	}
	return -1;
}

void BuscarMejorNota(int legajo, int materia)
{
	Examen obj;
	bool flag = false;
	int posicionMaxima = 0, cont = 0;
	float calificacionMaxima = 0;
	int cantidad = obj.getCantidad();

	for (int i = 0; i < cantidad; i++)
	{
		obj.leerDeDisco(i);
		if (obj.getLegajo() == legajo)
		{
			cont++;
			if (obj.getCodigoMateria() == materia)
			{
				if (!flag)
				{
					posicionMaxima = i;
					calificacionMaxima = obj.getCalificacion();
					flag = true;
				}
				else if(obj.getCalificacion() > calificacionMaxima)
				{
					posicionMaxima = i;
					calificacionMaxima = obj.getCalificacion();
				}
			}
		}
	}

	if (cont > 0)
	{
		cout << "La calificacion maxima fue de " << calificacionMaxima << endl;
	}
	else
	{
		cout << "No existe el registro" << endl;
	}
}

int main() {
	int opcion;
	
	do
	{
		rlutil::cls();
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
				Examen obj;
				std::cout << "CARGAR EXAMEN" << std::endl;
				std::cout << "----------------------------" << std::endl;
				if (obj.nuevoExamen())
				{
					std::cout << "Guardo correctamente" << std::endl;
				}
				else
				{
					std::cout << "No se guardo correctamente" << std::endl;
				}
				std::cout << "Presionar una tecla para volver al menu principal" << endl;
				rlutil::anykey();
				//OPCIONAL: No puede repetirse la combinación de Legajo, IDMateria y Fecha.
			}
			break;
			case 2:
			{
				rlutil::cls();
				Examen obj;
				obj.listarExamen();
				std::cout << "Presionar una tecla para volver al menu principal" << endl;
				rlutil::anykey();
			}
			break;
			case 3:
			{
				std::cout << "BUSCAR MEJOR NOTA" << std::endl;
				std::cout << "----------------------------" << std::endl;
				//utilizar funcion BuscarMejorNota
				int legajo, codigo;
				cout << "Ingrese el legajo: ";
				cin >> legajo;
				cout << "Ingrese el codigo de materia: ";
				cin >> codigo;
				BuscarMejorNota(legajo, codigo);
				std::cout << "Presionar una tecla para volver al menu principal" << endl;
				rlutil::anykey();
			}
			break;
			case 0:
				rlutil::cls();
				cout << "Confirmar Salir? (S/N)";

				return 0;
		}
	} while (opcion);


  
  return 0;
}