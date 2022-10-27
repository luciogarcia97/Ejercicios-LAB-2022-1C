#pragma once
#include "Fecha.h"

class Examen
{
private:
	Fecha _fecha;
	int _legajo;
	int _codigoMateria;
	float _calificacion;
	char _tipoExamen;

public:
	Examen();

	void setFecha(Fecha fecha);
	void setLegajo(int legajo);
	void setCodigoMateria(int codigo);
	void setCalificacion(float calificacion);
	void setTipoExamen(char examen);

	Fecha getFecha();
	int getLegajo();
	int getCodigoMateria();
	float getCalificacion();
	char getTipoExamen();
	std::string toString();

	bool nuevoExamen();
	Examen cargarExamen();
	void listarExamen();

	bool guardarEnDisco();
	bool guardarEnDisco(Examen examen);
	bool leerDeDisco(int posicion);
	int getCantidad();
};

