#include "StdAfx.h"
#include "Nodo.h"


Nodo::Nodo(void)
{
	// constructor calcula el espacio total de memoria - por default
	dato = 0;
	sig = NULL;
	ant=NULL;
}


Nodo::~Nodo(void)
{
}

void Nodo::setDato(int n){
	dato=n;  
	// this es para indicar que se refiere al atributo del objeto
}

void Nodo::setSig(Nodo* siguiente){
	sig = siguiente;

}
void Nodo::setAnt(Nodo* ant){
	this->ant=ant;
}

int Nodo::getDato(){
	return dato;
}

Nodo* Nodo::getSig(){
	return sig;
}
Nodo* Nodo::getAnt(){
	return ant;
}