#pragma once
class Nodo
{
	
	int datos[5];//Arreglo para los datos...Contiene 5 valores ya que se comenzara a llenar de la posicion uno.
	//para poder mostrar mas facilmente y ademas de hacer mas facil la division del NODO.
	Nodo * enlances[5]; //Arreglo para los nodos hijos.
	Nodo * padre;//Variable para tener un mejor acceso a al nodo anterior a la hora de hacer la division.

	
	


public:

	Nodo();
	//Metodos....
	void setdatos(int,int);
	void setenlaces(int, Nodo *);
	int getdatos(int);
	Nodo *getenlances(int);
	int disponible;
	int cantidad_enlaces;
	void setpadre(Nodo *);
	Nodo * getpadre();
	~Nodo(void);
};


