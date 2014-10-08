#pragma once
#include "ListaArcos.h"
ref class Vertice
{

	int datos;
	ListaArcos ^ arcos;
	Vertice ^ sig;
	Vertice ^ ant;
	bool visitado;
	int valor;


public:
	Vertice();
	~Vertice(void);
	void setdatos(int);
	void setarcos(Arcos^);
	void setsig(Vertice ^);
	void setant(Vertice ^);
	int getdatos();
	bool getvisitado();
	void setvisitado(bool);
	ListaArcos ^ getarcos();
	Vertice ^ getsig();
	Vertice ^ getant();
	void setvalor(int);
	int getvalor();
	void setlistaarco(ListaArcos ^);
};


