#pragma once
ref class Arcos
{
	int direccion;   
	int peso;
	bool visitado;
	Arcos ^ sig;

 
	
public:
	Arcos();
	~Arcos(void);
//variable global
	int acumulado; 
//Metodos set
	void setdireccion(int);
	void setpeso(int);
	void setvisitado(bool);
	void setsig(Arcos ^);
//metodos get
	int getdireccion();
	int getpeso();
	bool getvisitado();
	
	Arcos ^ getsig();

};

