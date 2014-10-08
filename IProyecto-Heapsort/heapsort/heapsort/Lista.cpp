#include "stdafx.h"
#include "Lista.h"
#include <string.h>
#include <stdlib.h>


using namespace std;

Lista::Lista(bool circular,bool doble)
{
	
	cabeza=NULL;
	ultimo=NULL;
	largo=0;
	esCircular=circular;
	esDoble=doble;

	}





Lista::~Lista(void){
}

Nodo * Lista::getCabeza(){
	return cabeza;//El llamar este metodo el programa retorna la cabeza de la lista la cual es un nodo
}
	
Nodo * Lista:: getUltimo(){
		return ultimo;;//El llamar este metodo el programa retorna el ultimo elemento de la lista la cual es un nodo
	}
int Lista ::getLargo(){
		return largo;;//El llamar este metodo el programa retorna el largo de la lista la cual es un nodo
	}



//Estos metodos no retornan nada

void Lista::setCabeza(Nodo * inicio){
	cabeza=inicio; ;//El llamar este metodo el programa asigna a la cabeza al nodo con el cual se llama al metodo
}
void Lista::setLargo(int tamaño){
	largo=tamaño; //El llamar este metodo el programa aumenta el tamaño, segun el numero que se le ingrese
}
void Lista:: setUltimo(Nodo * p){
	ultimo=p; //El llamar este metodo el programa asigna como ultimo al nodo con el cual se llama al metodo
}

void Lista::setesCircular(bool circular){
	esCircular = circular;
}

void Lista::setesDoble(bool doble){
	esDoble=doble;
}

void Lista::agregar(int p){
	Nodo * nuevo=new Nodo();
	nuevo->setDato(p);
		if (cabeza==NULL)
		{
		cabeza=nuevo;
		ultimo=nuevo;
		largo ++;
		if (esCircular){
			ultimo->setSig(cabeza);
		}
		if (esDoble){
				cabeza->setAnt(ultimo);
			}
		}
		else{
			ultimo->setSig(nuevo);
			largo ++;
			if (esDoble){
				nuevo->setAnt(ultimo);
			}
			ultimo=nuevo;
			if (esCircular){
				ultimo->setSig(cabeza);
				if (esDoble){
					cabeza->setAnt(ultimo);
		
				}
			}
		}
}

	char *Lista::mostrar()
	{
	char res[1000];
	strcpy_s(res,"");
	Nodo * aux=cabeza;
	do 
	{
		char tmp[100];
		int entero= aux->getDato();
		
		_itoa_s(entero,tmp,100,10);
		strcat_s(res,tmp);
		strcat_s(res," ");
		
		aux=aux->getSig();
	}
		while ((esCircular && aux!=cabeza)  || (!esCircular && aux!=NULL));
		{
	}
		return res;
}
//Funcion para crear los monticulos
 void Lista::buildhep(int last){
	 //Mediante un ciclo for, se inicializa i con la mitad del largo, y mientras sea mayor a cero llamara a la funcion maxheapfly... 
	 for (int i=last/2;i > 0;i--){
		 maxHeapifly(i,last);	
	 
}
 }
void Lista::maxHeapifly(int parent,int last){
	//Crea los monticulos, no compara valores, solamente crea los monticulos
	
	int child=  2 * parent; //Mediate paramentros se la pasa el parent que noes otra cosa que la variable i que pasa buildheap
	while (child <= last){//Mientras el child, que es un entero sea mayor a last(largo), sea realizara lo siguiente:
		//Nodos para poder localizar el padre, el hijo, y el otro hijo...Ademas de contadores
		Nodo * padre=cabeza; 
		Nodo * hijo=cabeza;
		Nodo * hijo_1=new Nodo(); 
		int contador_padre=1;
		int contador_hijo=1;	
	
		//Ciclos while para localizar los nodos, segun los paramentros de parent y child
		while (contador_padre < parent){
		padre=padre->getSig();
		contador_padre ++;
		}

	
		while (contador_hijo < child){
			hijo=hijo->getSig();
			contador_hijo ++;
		}
		//Si chidl + 1 es mayor o igual al largo(esto es para evitar posibles caidas en el algoritmo)
		//y el valor del nodo siguiente a hijo es mayor al valor del hijo, se incrementa el valor de child
		if (child + 1 <= last && (hijo->getSig()->getDato())>(hijo->getDato())){
			child ++; //El algoritmo consultado trabaja con vectores, por ende al incrementar el valor del child, el cual
			//es la ubicacion del nodo hijo se debe mover una posicion el nodo hijo.
			hijo=hijo->getSig();
		}
			
		
		
		if ((hijo->getDato()) > (padre->getDato())){//Si el valor del hijo es mayo al valor del padre se intercambiara los valores de los nodos
			int aux= hijo->getDato();	
			hijo->setDato(padre->getDato());
			padre->setDato(aux);
		}
	parent=child; //parent pasa a tener un nuevo valor, el cual es el valor actual de child
	child= 2*parent;//child pasa a tener un nuevo valor, el cual es el valor del padre por 2
		
	}
	}
	
//El algoritmo de heapsor en todo su esplendor
void Lista::heapsort(int last){ //Se recibe el largo de elementos
	buildhep(last);//Se llama a la funcion builheap para contruir los monticulos
	//Creacion de nodos 
	Nodo * aux1= cabeza;
	Nodo * aux2=ultimo;
	//El algoritmo consultado la variable last consiste en la ubicacion del vector.Por lo tanto
	
	while (last > 1){
		//El nodo aux1, no se mueve de su ubicacion, por ende se guardan los datos en una variable tmp
		int tmp= aux1->getDato();
		//Se intercambian los valores de aux1,aux2... Con esto se moviliza el padre principal del monticulo
		aux1->setDato(aux2->getDato());
		aux2->setDato(tmp);
		last --;
		//Se resta el last y se llama a otra funcion con ese valor
		floydheapfly(last);
		aux2= aux2->getAnt();//El nodo aux debe cambiar, ya que cuando retorne la funcion, este debe estar en una posicion
		//menor que la inicial
		
	}
		
}

void Lista::floydheapfly(int  last){//Acomoda la lista
	//Crea dos enteros, donde padre sera la primera posicion y child la segunda posicion
	int parent=1;
	int child=2;
	//Creacion de nodos, para ubicar el parent y el child en nuestra lista	
	Nodo * hijo=cabeza;
	Nodo * padre=cabeza;
while (child <= last){ //mientras el child sea menor o igual a last, que es la variable que se modifica con la funcion anterior en cada llamada
		
	//Creacion y iniciacion de un contador, para ubicar los nodos en la posicion correcta
		int contador=1;
		while (contador < child){
			hijo=hijo->getSig();
			contador ++;
		}
		contador=1;
		while (contador < parent){
			padre=padre->getSig();
			contador ++;
		}
	
		//Si el child + 1 es mayor al last y el dato del nodo hijo es menor al siguiente nodo
		if ((child + 1 <= last) && ((hijo->getDato()) < (hijo->getSig()->getDato()))){
			child ++;//Se aumenta el child y por ende se desplaza el valor del hijo
			hijo=hijo->getSig();
			}
		//se lleva a cabo el intercambio de datos entre padre e hijo
		int aux= padre->getDato();
		padre->setDato(hijo->getDato());
		hijo->setDato(aux);
		//Se redefinen los valores de parent y de child. Y los nodos padra e hijo se inicialian de nuevo para poder
		//volverlo a ubicar en la lista.
		parent=child;
		child= 2 * parent;
		hijo=cabeza;
		padre=cabeza;
	}
	//Por ultimo se intercambian los valores de los padres de cada monticulo
	int aux_parent= parent /2; //Se crea un variable la cual la mitad del parent, esto para poder determinar el valor del nodo padre superior
	//Variables de ubicacion y ciclos para ubicar el nodo padre, y un nodo auxiliar, que sera el padre superior
	int contador=1;
	Nodo * aux_padre=cabeza;
	padre=cabeza;
	
	while (contador < parent){
		padre=padre->getSig();
		contador++;
	}
	contador=1;
	while (contador < aux_parent){
		aux_padre=aux_padre->getSig();
		contador ++;
	}
	//Mientras el valor de parent sea mayor a uno, se llevara a cabo la comprobacion de los nodos padre, si el nodo que se encuentra
	//en un nivel inferior es mayor al nodo de un superior, se invierten los valores
	while ((parent >1) &&(padre->getDato() > aux_padre->getDato())){
		contador=1;
		int tmp = padre->getDato();
		padre->setDato(aux_padre->getDato());
		aux_padre->setDato(tmp);
		parent=parent/2;
		aux_parent=parent/2;
		//Se reinician los valores de padre y aux_padre, ya que las se debe de llevar a cabo el moviento por los niveles del "arbol"
		aux_padre=cabeza;
		padre=cabeza;
	
		while (contador < parent){
			padre=padre->getSig();
			contador++;
		}
		contador=1;
	while (contador < aux_parent){
		aux_padre=aux_padre->getSig();
		contador ++;
	}
	}
	}
	




