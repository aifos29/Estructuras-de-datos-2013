#include "stdafx.h"
#include "ListaVertices.h"
#include "Vertice.h"
#include <iostream>
#include "libxl.h"
#include "Arcos.h"
#include <iostream>
#include <fstream>


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


using namespace std;
using namespace libxl;
ListaVertices::ListaVertices()
{
	cabeza=nullptr;
	ultimo=nullptr;
	largo=0;
	esCircular=false;
	esDoble=true;
	k = gcnew array<Vertice ^>(20); 
	p=0;
	
}


ListaVertices::~ListaVertices(void)
{
}


Vertice ^ ListaVertices::getCabeza(){
	return cabeza;//El llamar este metodo el programa retorna la cabeza de la lista la cual es un nodo
}	
Vertice ^ ListaVertices:: getUltimo(){
		return ultimo;;//El llamar este metodo el programa retorna el ultimo elemento de la lista la cual es un nodo
	}
int ListaVertices ::getLargo(){
	return largo;;//El llamar este metodo el programa retorna el largo de la lista la cual es un nodo
}
//Estos metodos no retornan nada

void ListaVertices::setCabeza(Vertice ^ inicio){
	cabeza=inicio; ;//El llamar este metodo el programa asigna a la cabeza al nodo con el cual se llama al metodo
}
void ListaVertices::setLargo(int tamaño){
	largo=tamaño; //El llamar este metodo el programa aumenta el tamaño, segun el numero que se le ingrese
}
void ListaVertices:: setUltimo(Vertice ^ p){
	ultimo=p; //El llamar este metodo el programa asigna como ultimo al nodo con el cual se llama al metodo
}
void ListaVertices::setesCircular(bool circular){
	esCircular = circular;
}
void ListaVertices::setesDoble(bool doble){
	esDoble=doble;
}

void ListaVertices::agregar(Vertice ^ p){
	Vertice ^ nuevo=p;

		if (cabeza==nullptr)
		{
		cabeza=nuevo;
		ultimo=nuevo;
		largo ++;
		if (esCircular){
			ultimo->setsig(cabeza);
		}
		if (esDoble){
				cabeza->setant(ultimo);
			}
		}
		else{
			ultimo->setsig(nuevo);
			largo ++;
			if (esDoble){
				nuevo->setant(ultimo);
			}
			ultimo=nuevo;
			if (esCircular){
				ultimo->setsig(cabeza);
				if (esDoble){
					cabeza->setant(ultimo);
		
				}
			}
		}
}
//Metodo para agregar los vertice
void ListaVertices::agregararcos(int n_hoja){
	Vertice ^ nuevo=cabeza;	
	Book * book =xlCreateBook();
	if (book->load(L"Prueba.xls")){
		Sheet * sheet=book->getSheet(n_hoja);
	if (sheet){
		int contador=1;
		int fila=2;
		
		int cantidad=sheet->readNum(0,1);
		while (contador<=cantidad){ 
			int hasta=sheet->readNum(fila,1);
			int desde=sheet->readNum(fila,0);
			int peso=sheet->readNum(fila,2);
			if (nuevo->getdatos()==desde){
				Arcos ^ p= gcnew Arcos();
				p->setdireccion(hasta);
				p->setpeso(peso);
				nuevo->setarcos(p);
				fila ++;
			}
			else{
				nuevo=nuevo->getsig();
				contador ++;
				
			}
			}
		}
	}
	}
//Intento de calculo de ruta
void ListaVertices::disktraj(int salida,int llegada,int x){
	if (salida==llegada){
		iteraciones();
		cout<<"Se necesita de tanto "<< x <<"para llegar a "<<" "<<llegada<<endl;
		mostrarruta();
	}
	else{
		int total=x;
		Vertice ^ nuevo=revisar(salida,cabeza);
		nuevo->setvisitado(true);
		k[p]=nuevo;
		p++;
		relajacion(nuevo,total,llegada);
	}
}
void ListaVertices::relajacion(Vertice ^ actual,int x,int llegada){
	int total=x;
	ListaArcos ^ arcos=actual->getarcos();
	Arcos ^ nuevo=arcos->getCabeza();
	int contador=0;
	int menor=0;
	while (contador <arcos->getLargo()){
			bool b=buscar(nuevo->getdireccion());
				if (b==1){
					contador ++;
				if (nuevo->getsig()!=nullptr){
					nuevo=nuevo->getsig();

				}
			}
		else{
			if (menor==0){
				menor=nuevo->getpeso();
				nuevo->acumulado=nuevo->getpeso()+total;
				if (nuevo->getsig()==nullptr){
					contador ++;
				}
				else{
					nuevo=nuevo->getsig();
					contador ++;
				}
				
			}
			else{
				if (nuevo->getpeso()<menor){
					menor=nuevo->getpeso();
					nuevo->acumulado=nuevo->getpeso()+total;
					if (nuevo->getsig()!=nullptr){
						nuevo=nuevo->getsig();
					}
					contador ++;
				}
				else{
					nuevo->acumulado=nuevo->getpeso()+total;
					if (nuevo->getsig()!=nullptr){
						nuevo=nuevo->getsig();
						}
					contador ++;
				}

				}
		}
	}
	contador=0;
	nuevo=arcos->getCabeza();
	while (contador < arcos->getLargo()){
		if (nuevo->getpeso()==menor){
			contador=arcos->getLargo();
		}
		else{
			if (nuevo->getsig()!=nullptr){
				nuevo=nuevo->getsig();
			}
			contador ++;
			}
	}
	nuevo->setvisitado(true);
	total=menor+total;
	actual->setvalor(total);
	int u=nuevo->getdireccion();
	disktraj(u,llegada,total);

}
Vertice ^ ListaVertices::revisar(int x,Vertice ^ aux){
	
	for (int i=0 ; i<largo;i ++){
	
		int p=aux->getdatos();
		
		if (p==x){
			i=largo;
			//Vertice ^ nuevo=aux;
			return aux;		
		}
		else{
			if (aux->getsig()!=nullptr){
				aux=aux->getsig();
			}
		}
	}

}

void ListaVertices::mostrar(){
	Vertice ^ nuevo=cabeza;
	System::IO::StreamWriter  ^ sw = gcnew 
	System::IO::StreamWriter ("Test.txt");
	sw->Write(" ");
	sw->Close();
	for (int i=0;i<largo;i++){
		System::IO::StreamWriter  ^ sw = gcnew 
		System::IO::StreamWriter ("Test.txt",true);
		String ^ datos= "El vertice" +" "+ nuevo->getdatos()+" "+ "tiene los siguiente arcos";
		String ^ guardar = datos;
		sw->WriteLine(guardar);
		sw->Close();
		nuevo->getarcos()->mostrararcos();
		nuevo=nuevo->getsig();
		
		}

}

void ListaVertices::mostrarruta(){
	System::IO::StreamWriter  ^ sw = gcnew 
	System::IO::StreamWriter ("Ruta.txt");
	sw->Write(" ");
	sw->Close();
		for(int i=0;i<p;i++){
			System::IO::StreamWriter  ^ sw = gcnew 
			System::IO::StreamWriter ("Ruta.txt",true);
			Vertice ^ n=k[i];
			String ^ datos= "Partiendo de " +" "+ n->getdatos()+" "+ "debe tomar el siguiene camino"+" ";
			String ^ guardar = datos;
			sw->WriteLine(guardar);
			sw->Close();
			n->getarcos()->mostrararcosvisitados();
}
}



bool ListaVertices::buscar(int x){
	Vertice ^ nuevo=cabeza;
	for (int i=0;i<largo;i++){
		int comparar=nuevo->getdatos();
		if(comparar==x){
			if (nuevo->getvisitado()){
			return 1;
			}
		}
		else{
			if (nuevo->getsig()!=nullptr){
				nuevo=nuevo->getsig();
			}
		}


	}
}

void ListaVertices::iteraciones(){
	String ^ datos= "Partida" ;
	System::IO::StreamWriter  ^ sw = gcnew 
	System::IO::StreamWriter ("Iteracion.txt",true);
	for (int i=1;i<=largo;i++){
		datos= datos + " "+ " " +  " "+" " +i;
	}
	sw->WriteLine(datos);
	for (int i=0;i<p;i++){
		int contador=0;
		Vertice ^ x= k[i];
		Vertice ^ nuevo=cabeza;
		while (contador < largo){
			if (x->getdatos()==nuevo->getdatos()){
				contador=largo;
			}
			else{
				if (nuevo->getsig()!=nullptr){
					nuevo=nuevo->getsig();
				}
				contador ++;
				}

			}
	

		String ^ vertices=" ";
		vertices= "Tomar "+"" + nuevo->getdatos() + " ";
		ListaArcos ^ ar=nuevo->getarcos();
		Arcos ^ n=ar->getCabeza();
		for (int j=1;j <= largo;j ++){
			
			if (n->getdireccion()==j){
				vertices= vertices + " "+ " " + "("+ n->acumulado +")";
				if (n->getsig()!=nullptr){		
						n=n->getsig();
					}
				}
			else{
				vertices= vertices + " "+" "+ " "+ " x";
			
			}
		
	}
		
		sw->WriteLine(vertices);
	}

	sw->Close();
}
void ListaVertices::reseteo(){
	p=0;
	k = gcnew array<Vertice ^>(20); 
	Vertice ^ nuevo=cabeza;
	for(int i=0;i<largo;i++){
		nuevo->setvisitado(false);
		nuevo->setvalor(0);
		nuevo->getarcos()->falseall();
		if(nuevo->getsig()!=nullptr){
			nuevo=nuevo->getsig();
		}
	}
	

}




			
		