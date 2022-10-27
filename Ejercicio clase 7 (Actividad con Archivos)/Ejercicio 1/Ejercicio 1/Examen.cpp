#include <iostream>
#include "Examen.h"

Examen::Examen()
{
	_legajo = 0;
	_codigoMateria = 0;
	_calificacion = 0;
	_tipoExamen = ' ';
}

void Examen::setFecha(Fecha fecha)
{
	_fecha = fecha;
}

void Examen::setLegajo(int legajo)
{
	_legajo = legajo;
}

void Examen::setCodigoMateria(int codigo)
{
	_codigoMateria = codigo;
}

void Examen::setCalificacion(float calificacion)
{
	while(calificacion < 0 || calificacion > 10)
	{
		std::cout << "Calificacion erronea, ingrese nuevamente: ";
		std::cin >> calificacion;
	}
	
	_calificacion = calificacion;
}

void Examen::setTipoExamen(char examen)
{
	//while(tolower(examen) != 'p' || tolower(examen) != 'f')
	//{
	//	std::cout << "Tipo incorrecto de examen incorrecto, ingresar nuevamente: ";
	//	std::cin >> examen;
	//}
	_tipoExamen = examen;
}

Fecha Examen::getFecha()
{
	return _fecha;
}

int Examen::getLegajo()
{
	return _legajo;
}

int Examen::getCodigoMateria()
{
	return _codigoMateria;
}

float Examen::getCalificacion()
{
	return _calificacion;
}

char Examen::getTipoExamen()
{
	return _tipoExamen;
}

//std::string Examen::toString()
//{
//	Fecha obj;
//	std::string cadena;
//	cadena = "Materia: " + std::to_string(_codigoMateria) + "," + " Legajo: " +
//		std::to_string(_legajo) + "," + " Fecha: " + obj.toString() + "," + " Calificacion: " +
//		std::to_string(_calificacion) + "," + " Tipo de Examen: " + getTipoExamen();
//	return cadena;
//}
std::string Examen::toString()
{
	std::string cadena;
	cadena = std::to_string(_legajo) + " \t " + std::to_string(_codigoMateria) + "\t" + "\t" + _fecha.toString() + " \t " + getTipoExamen() + " \t " + std::to_string(_calificacion) + "\n";
	return cadena;
}

bool Examen::nuevoExamen()
{
	Examen obj;
	obj = cargarExamen();
	bool guardo = guardarEnDisco(obj);
	return guardo;
}

Examen Examen::cargarExamen()
{
	int legajo;
	int codigoMateria;
	float calificacion;
	char tipoExamen;
	int dia, mes, anio;
	Examen obj;

	std::cout << "Ingrese numero de legajo: ";
	std::cin >> legajo;
	obj.setLegajo(legajo);
	std::cout << "Ingrese el codigo de materia: ";
	std::cin >> codigoMateria;
	obj.setCodigoMateria(codigoMateria);
	std::cout << "Ingrese calificacion: ";
	std::cin >> calificacion;
	obj.setCalificacion(calificacion);
	std::cin.ignore();
	std::cout << "Ingrese el tipo de examen: (P-Parcial o F-Final) ";
	std::cin >> tipoExamen;
	obj.setTipoExamen(tipoExamen);
	std::cin.ignore();

	std::cout << "Ingrese dia: ";
	std::cin >> dia;
	std::cout << "Ingrese mes: ";
	std::cin >> mes;
	std::cout << "Ingrese anio: ";
	std::cin >> anio;
	Fecha fecha(dia, mes, anio);
	obj.setFecha(fecha);
	
	return obj;
}

void Examen::listarExamen()
{
	std::cout << "LISTAR EXAMENES" << std::endl;
	std::cout << "----------------------------" << std::endl << std::endl;
	std::cout << "LEGAJO\tIDMATERIA \t FECHA\t\tTIPO\tCALIFICACION" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	//Listar el total de examenes
	Examen obj;
	int cantidad = obj.getCantidad();
	for (int i = 0; i < cantidad; i++)
	{
		obj.leerDeDisco(i);
		std::cout << obj.toString() << std::endl;
	}
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "Hay un total de " << obj.getCantidad() << " registros" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
}

bool Examen::guardarEnDisco()
{
	FILE* p;
	p = fopen("examenes.dat", "ab");
	if (p == nullptr) { return false; }
	bool guardo = fwrite(this, sizeof(Examen), 1, p);
	fclose(p);
	return guardo;
}
bool Examen::guardarEnDisco(Examen examen)
{
	FILE* p;
	p = fopen("examenes.dat", "ab");
	if (p == nullptr) { return false; }
	bool guardo = fwrite(&examen, sizeof(Examen), 1, p);
	fclose(p);
	return guardo;
}

bool Examen::leerDeDisco(int posicion)
{
	FILE* p;
	p = fopen("examenes.dat", "rb");
	if (p == nullptr) { return false; }
	fseek(p, posicion * sizeof(Examen), SEEK_SET);
	bool leyo = fread(this, sizeof(Examen), 1, p);
	fclose(p);
	return leyo;
}

int Examen::getCantidad()
{
	FILE* p = fopen("examenes.dat", "rb");
	if (p == NULL) { return 0; }
	fseek(p, 0, SEEK_END);
	int cant = ftell(p) / sizeof(Examen);
	fclose(p);
	return cant;
}
