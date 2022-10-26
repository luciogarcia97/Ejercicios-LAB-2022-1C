#include <iostream>
#include "Examen.h"

Examen::Examen()
{
	_legajo = 0;
	_codigoMateria = 0;
	_calificacion = 0;
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
	std::cin.ignore();
}

void Examen::setTipoExamen(char examen)
{
	_tipoExamen = examen;
}

Fecha Examen::getFecha()
{
	return Fecha();
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

std::string Examen::toString()
{
	Fecha obj;
	std::string cadena;
	cadena = "Materia: " + std::to_string(_codigoMateria) + "," + " Legajo: " +
		std::to_string(_legajo) + "," + " Fecha: " + obj.toString() + "," + " Calificacion: " +
		std::to_string(_calificacion) + "," + " Tipo de Examen: " + getTipoExamen();
	return cadena;
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

int Examen::getCantidad()
{
	FILE* p = fopen("examenes.dat", "rb");
	if (p == NULL) { return 0; }
	fseek(p, 0, SEEK_END);
	int cant = ftell(p) / sizeof(Examen);
	fclose(p);
	return cant;
}
