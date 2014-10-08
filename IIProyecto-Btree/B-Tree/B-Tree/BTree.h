#pragma once
#include "Nodo.h"




class BTree
{
	Nodo * raiz;//el inicio del arbol
	int MAX  ; //valor maximo que sera permitido
	int MIN  ;//valor minimo permitido por nodos

public:
	BTree(void);
	~BTree(void);
	Nodo * getraiz();
	//metodos para insertar
	void insertar(int);
	bool  buscar(int,Nodo *);
	Nodo * ordenar(Nodo ** );
	void llenar(Nodo **,int);
	//metodo de division
	void dividir(Nodo **,int);
	void dividir_raiz(int);
	void dividir_nodo(Nodo **,int);
	Nodo * buscarNODO(Nodo *,int); //Nodo para iniciar, valor que manda el usuario y una posicion

	//Metodos para mostrar
	void show();
	void display(Nodo *);
};




