#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo * cabeza;
	Nodo * ultimo;
	int largo;
	bool esDoble;
	bool esCircular;
public:
	Lista(bool,bool);
	~Lista(void);

	void setCabeza(Nodo*);
	void setLargo(int);
	void setUltimo(Nodo*);
	void setesCircular(bool);
	void setesDoble(bool);
	Nodo* getCabeza();
	Nodo* getUltimo();
	int getLargo();

	void agregar(int );
	void buildhep(int);
	void maxHeapifly(int,int);
	void heapsort(int);
	void floydheapfly(int);
	char * mostrar();
};

