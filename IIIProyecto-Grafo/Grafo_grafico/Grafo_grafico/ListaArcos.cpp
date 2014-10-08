#include "stdafx.h"
#include "ListaArcos.h"
#include "Arcos.h"
#include <iostream>
#include "libxl.h"
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

using namespace std;
using namespace libxl;
ListaArcos::ListaArcos()
{
	cabeza=nullptr;
	ultimo=nullptr;
	largo=0;
	esCircular=0;
	esDoble=0;
}


ListaArcos::~ListaArcos(void)
{
}
Arcos ^ ListaArcos::getCabeza(){
	return cabeza;//El llamar este metodo el programa retorna la cabeza de la lista la cual es un nodo
}	
Arcos ^ ListaArcos:: getUltimo(){
		return ultimo;;//El llamar este metodo el programa retorna el ultimo elemento de la lista la cual es un nodo
	}
int ListaArcos ::getLargo(){
	return largo;;//El llamar este metodo el programa retorna el largo de la lista la cual es un nodo
}
//Estos metodos no retornan nada

void ListaArcos::setCabeza(Arcos ^ inicio){
	cabeza=inicio; ;//El llamar este metodo el programa asigna a la cabeza al nodo con el cual se llama al metodo
}
void ListaArcos::setLargo(int tamaño){
	largo=tamaño; //El llamar este metodo el programa aumenta el tamaño, segun el numero que se le ingrese
}
void ListaArcos:: setUltimo(Arcos ^ p){
	ultimo=p; //El llamar este metodo el programa asigna como ultimo al nodo con el cual se llama al metodo
}
void ListaArcos::setesCircular(bool circular){
	esCircular = circular;
}
void ListaArcos::setesDoble(bool doble){
	esDoble=doble;
}

void ListaArcos::agregar(Arcos ^ p){
	Arcos ^ nuevo=p;

		if (cabeza==nullptr)
		{
		cabeza=nuevo;
		ultimo=nuevo;
		largo ++;
		if (esCircular){
			ultimo->setsig(cabeza);
		}
		}
		else{
	
			ultimo->setsig(nuevo);
			largo ++;
			
			ultimo=nuevo;
			if (esCircular){
				ultimo->setsig(cabeza);
				
		
				}
			}
		}

//Metodo para agregar al inicio

void ListaArcos::mostrararcos(){
	int contador=0;
	Arcos ^ nuevo=cabeza;
	System::IO::StreamWriter  ^ sw = gcnew 
	System::IO::StreamWriter ("Test.txt",true);
	while (contador < largo){
		String ^ datos= "La direccion es " + nuevo->getdireccion()+" " +"con un peso de "+" "+ nuevo->getpeso() ;
		String ^ guardar = datos;
		sw->WriteLine(guardar);
		nuevo=nuevo->getsig();
		contador ++;
		}
	sw->Close();


}
void ListaArcos::falseall(){
	Arcos ^ nuevo=cabeza;
	bool terminar=false;
	for (int i=0;i<largo;i++){
		nuevo->setvisitado(false);
		nuevo->acumulado=0;
		if(nuevo->getsig()!=nullptr){
			nuevo=nuevo->getsig();
		}
}
}
void ListaArcos::mostrararcosvisitados(){
	int contador=0;
	Arcos ^ nuevo=cabeza;
	while (contador < largo){
		if (nuevo->getvisitado()==true){
			System::IO::StreamWriter  ^ sw = gcnew 
			System::IO::StreamWriter ("Ruta.txt",true);
			String ^ datos= "Debe ir por el vertice " +" "+nuevo->getdireccion()+" "+ "con un peso de "+" "+nuevo->getpeso();
			String ^ guardar = datos;
			sw->WriteLine(guardar);
			sw->Close();
			nuevo=nuevo->getsig();
			contador ++;
		}
		else{
			nuevo=nuevo->getsig();
			contador ++;
		}
	}

}

