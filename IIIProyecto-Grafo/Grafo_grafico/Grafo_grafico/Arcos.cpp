#include "stdafx.h"
#include "Arcos.h"


Arcos::Arcos(void)
{
	direccion=0;
	peso=0;
	visitado=false;
	acumulado=0;
}


Arcos::~Arcos(void)
{
}
//metodos get

int Arcos::getdireccion(){
	return direccion;
}
int Arcos::getpeso(){
	return peso;
}
bool Arcos::getvisitado(){
	return visitado;
}
Arcos ^ Arcos::getsig(){
	return sig;
}
//metodos set
void Arcos::setpeso(int x){
	peso=x;
}
void Arcos::setdireccion(int x){
	direccion=x;
}
void Arcos::setvisitado(bool x){
	visitado=x;
}
void Arcos::setsig(Arcos ^ x){
	sig=x;
}

