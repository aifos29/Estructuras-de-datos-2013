#include "stdafx.h"
#include "Nodo.h"

Nodo::Nodo()

{
	//Inicializa los datos en -1 y los enlances en Nulo,la variable disponible en cero
	for (int i=0;i<5;i++){
		datos[i]=-1;
	}
	for(int i=0;i<5;i++){
		enlances[i]=NULL;
	}
	disponible=0;
	cantidad_enlaces=0;
}


Nodo::~Nodo(void)
{
}

void Nodo :: setdatos(int posicion,int dato){
	datos[posicion]=dato;

}
void Nodo :: setenlaces(int posicion,Nodo * pos){
	enlances[posicion]=pos;
}
void Nodo ::setpadre(Nodo * p){
	padre=p;
}
int Nodo :: getdatos(int n){
	return datos[n];
}
Nodo * Nodo::getenlances(int posicion){
	return enlances[posicion];
}
Nodo * Nodo::getpadre(){
	return padre;
}


