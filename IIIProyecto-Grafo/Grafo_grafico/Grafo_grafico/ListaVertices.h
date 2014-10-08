#pragma once
#include "Vertice.h"
ref class ListaVertices
{	
	Vertice ^ cabeza;	
	Vertice ^ ultimo;
	int largo;
	bool esDoble;
	bool esCircular;
	int p;
	array  <Vertice ^> ^ k;
	
public:
	ListaVertices();
	~ListaVertices(void);


	void setCabeza(Vertice^);
	void setLargo(int);
	void setUltimo(Vertice^);
	void setesCircular(bool);
	void setesDoble(bool);
	Vertice^ getCabeza();
	Vertice^ getUltimo();
	int getLargo();

	void agregar(Vertice ^);
	void agregararcos(int);
	void disktraj(int,int,int);
	void relajacion(Vertice ^,int,int );
	void mostrar();
	Vertice ^ revisar(int,Vertice ^);
	bool buscar(int);
	void mostrarruta();
	void iteraciones();
	void reseteo();
	
};
