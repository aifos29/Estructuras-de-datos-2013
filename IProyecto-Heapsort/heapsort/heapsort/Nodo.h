#pragma once

class Nodo
{
private: 
	int dato;
	Nodo* sig;
	Nodo*ant;
public:
	Nodo(void);
	~Nodo(void);

	void setDato(int);
	void setSig(Nodo* );
	void setAnt(Nodo*);
	
	int getDato();
	Nodo* getSig();
	Nodo*getAnt();
	
};
