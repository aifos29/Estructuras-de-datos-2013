#include "stdafx.h"
#include "Vertice.h"
#include "ListaArcos.h"


Vertice::Vertice()
{
	datos=0;
	arcos=gcnew ListaArcos();
	sig=nullptr;
	ant=nullptr;
	visitado=false;
	valor=0;
}




Vertice::~Vertice(void)
{
}

void Vertice::setarcos(Arcos ^ nueva){
	arcos->agregar(nueva);
	
}
void Vertice::setdatos(int x){
	datos=x;
}
void Vertice::setsig(Vertice ^ x){
	sig= x;
}
void Vertice::setant(Vertice ^ x){
	ant=x;
}
int Vertice::getdatos(){
	return datos;
}
ListaArcos ^ Vertice::getarcos(){
	return arcos;
}
Vertice ^ Vertice::getant(){
	return ant;
}
Vertice ^ Vertice::getsig(){
	return sig;
}
bool Vertice::getvisitado(){
	return visitado;
}
void Vertice::setlistaarco(ListaArcos ^ n){
	arcos=n;
}
void Vertice::setvisitado(bool x){
	visitado=x;
}
void Vertice::setvalor(int x){
	valor=x;
}
int Vertice::getvalor(){
	return valor;
}