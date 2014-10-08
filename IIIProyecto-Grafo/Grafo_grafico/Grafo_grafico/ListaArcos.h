#pragma once
#include "Arcos.h"
ref class ListaArcos
{
	Arcos ^ cabeza;	
	Arcos ^ ultimo;
	int largo;
	bool esDoble;
	bool esCircular;
	
public:
	ListaArcos();
	~ListaArcos(void);
	void setCabeza(Arcos^);
	void setLargo(int);
	void setUltimo(Arcos^);
	void setesCircular(bool);
	void setesDoble(bool);
	Arcos^ getCabeza();
	Arcos^ getUltimo();
	int getLargo();

	void agregar(Arcos ^);
	void mostrararcos();
	void mostrararcosvisitados();
	void falseall();

	

};

