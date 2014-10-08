#include "stdafx.h"
#include "BTree.h"


#include <iostream>
using namespace std;




BTree::BTree(void)
{
	MAX = 4 ; //Maximo permitido
	MIN = 2 ;//minimo permitido
	raiz=NULL;//raiz inicializada en nulo
}//Good


BTree::~BTree(void)
{
}//Good
//Metodos para insertar


void BTree::insertar(int x){
	/*Si la raiz es nula la inicializa como un nuevo nodo y agrega los datos*/
	if (raiz==NULL){
		raiz=new Nodo();
		raiz->setdatos(0,x);
		raiz->disponible ++;
	}
	else{
		llenar(&raiz,x);//De no ser nula llama a llenar
	}
}
void BTree::llenar(Nodo ** vacio,int x){
	Nodo * localizar=buscarNODO(*vacio,x); //Va a localizar el nodo donde se encuentra los valores
	bool b=buscar(x,localizar); //con ese nodo localizado va a buscar el valor dentro del Nodo
	if (b==true){ //si es true quiere decir que no lo encontro
		if (localizar->disponible==4){ //revisa el disponible si es 4
		dividir(&localizar,x); //va a realizar la division del nodo
		}
		else{
			/*agrega el valor de x al nodo,aumenta el disponible y realizar un bublesort para ordenar el arreglo*/
			localizar->setdatos(localizar->disponible,x);
			localizar->disponible ++;
			int c1,c2,aux;
			for(c1=0;c1< localizar->disponible;c1++)
			{
				for(c2=0;c2<localizar->disponible;c2++)
			{
				if(localizar->getdatos(c2)>localizar->getdatos(c2+1) && localizar->getdatos(c2+1)!=-1)
				{
				aux=localizar->getdatos(c2);
				localizar->setdatos(c2,localizar->getdatos(c2+1));
				localizar->setdatos(c2+1,aux);
        }
      }

		}
	}
	}
}
Nodo * BTree::buscarNODO(Nodo * actual,int x){
	if (actual->getenlances(0)==NULL){ //si en enlance es nulo no tiene hijos por lo tanto retorna el mismo nodo
		return actual;
	}
	else{
		
		if (actual->getdatos(0)<x){ //si el valor buscand es menor que la posicion 0 ira a al enalnce 0
			buscarNODO(actual->getenlances(0),x);
		}
		if (actual->getdatos(0)>x && actual->getdatos(1)<x){ //si el valor buscand es menor que la posicion 1 y mayor a 0,ira al enlance 1
			if (actual->getdatos(1)!=-1){
				buscarNODO(actual->getenlances(1),x);
			}
			else{
				buscarNODO(actual->getenlances(1),x); 
				}
		}
		if (actual->getdatos(1)>x && actual->getdatos(2)<x){//si el valor buscado es menor que la posicion 2 y mayor que la una ira al enlance 2
			if (actual->getdatos(2)!=-1){
				buscarNODO(actual->getenlances(2),x);
			}
			else{
				buscarNODO(actual->getenlances(2),x); 
				}
		}
		if (actual->getdatos(3)>x && actual->getdatos(2)<x){//si el valor buscado es mayor a la posicion 3 y menor a las dos ira por el enlace 3
			if (actual->getdatos(3)!=-1){
				buscarNODO(actual->getenlances(3),x);
			}
			else{
				buscarNODO(actual->getenlances(3),x); 
				}
		}
	}

}
void BTree :: dividir(Nodo ** division, int x){
	Nodo * mitad=*division; //mitad es igual al valor que se divide
	if (mitad->getpadre()==NULL){ //si el padre es nulo la division es la raiz, asi que va a dividr la raiz
		dividir_raiz(x);	
	}
	else{
		dividir_nodo(&mitad,x); //de lo contrario va a dividir nodo, ya que este tiene una raiz
	}
	}
void BTree::dividir_raiz(int x){
	Nodo * derecha=new Nodo(); 
	Nodo * izquierda=new Nodo();
	//en las dos primeras posiciondes del ndo derecho van los ultimos valores y aumenta el disponible
	derecha->setdatos(0,raiz->getdatos(3)); //
	derecha->disponible++;
	derecha->setdatos(1,raiz->getdatos(4));
	derecha->disponible++;
	derecha->setpadre(raiz);//indica que el padre es la raiz
	//en las dos primeras posiciones del nodo izquierdo van los primeros valores y aumenta el disponible
	izquierda->setdatos(0,raiz->getdatos(0));
	izquierda->disponible++;
	izquierda->setdatos(1,raiz->getdatos(1));		
	izquierda->disponible++;
	izquierda->setpadre(raiz);//indica que el padre es la raiz;
	//agrega los nodos a la raiz y aumenta los enlances;
	raiz->setenlaces(0,izquierda);
	raiz->cantidad_enlaces ++;
	raiz->setenlaces(1,derecha);
	raiz->cantidad_enlaces ++;
		//cambiar valor de la posicion1 y resetear los enlances y el disponible
	raiz->setdatos(0,raiz->getdatos(2));
		for (int i=1;i<5;i++){
			raiz->setdatos(i,-1);
		}
		raiz->disponible=1;
	}
void BTree::dividir_nodo(Nodo ** n,int x){
	Nodo * nuevo=*n; //nodo nuevo que hace referencia al nodo que se va a dividir;
	Nodo *padre=nuevo->getpadre(); //variable para tener acceso directo al padre
	//Crear dos nodos nuevos para guardar los valores de la division
	Nodo * derecha=new Nodo(); 
	Nodo * izquierda=new Nodo();
	derecha->setdatos(0,nuevo->getdatos(3)); //
	derecha->disponible++;
	derecha->setdatos(1,nuevo->getdatos(4));
	derecha->disponible++;
	derecha->setpadre(padre);//indica que el padre es la nuevo;
		//en las dos primeras posiciones del nodo izquierdo van los primeros valores y aumenta el disponible
	izquierda->setdatos(0,nuevo->getdatos(0));
	izquierda->disponible++;
	izquierda->setdatos(1,nuevo->getdatos(1));
	izquierda->disponible++;
	izquierda->setpadre(nuevo);//indica que el padre es el nuevo;
		//Averiguar en cual enlance va!!!
	/*Si el valor de los enlances es 0 quieres decir que no tiene nada, por lo tanto va a agregar los enlances y aumentar el contador */
	if (padre->cantidad_enlaces==0){    
		padre->setenlaces(0,izquierda);
		padre->cantidad_enlaces ++;
		padre->setenlaces(1,derecha);
		padre->cantidad_enlaces ++;
		}
	else{
/*Si el valor del contador de los enlances es dos, entonces redefine el valor del nodo izquierdo y agrega el nodo derecho, aumenta el contador solo una vez*/
		if (padre->cantidad_enlaces==2){
			padre->setenlaces(1,izquierda);
			padre->cantidad_enlaces ++;
			padre->setenlaces(2,derecha);
				}
		else{
/*Si el valor del contador de los enlances es tres, entonces redefine el valor del nodo izquierdo y agrega el nodo derecho, aumenta el contador solo una vez*/
			if (padre->cantidad_enlaces==3){
				padre->setenlaces(3,izquierda);
				padre->setenlaces(4,derecha);
				padre->cantidad_enlaces ++;

			}
		else{
/*Si el valor del contador de los enlances es dos, entonces redefine el valor del nodo izquierdo y agrega el nodo derecho, aumenta el contador solo una vez*/				
			if (padre->cantidad_enlaces==4){
				padre->setenlaces(3,izquierda);
				padre->setenlaces(4,derecha);
				padre->cantidad_enlaces ++;
				}
				}
				}
		}
	llenar(&padre,x);//Con la funcion llenar agrega el valor nuevo al padre, si este esta lleno, regresara a dividir
	}
bool  BTree::buscar(int x,Nodo * nuevo){
	Nodo * localizando=nuevo; //cambio de nombre a la variable
	for (int i=0;i<localizando->disponible;i++){ //recorre el nodo esta encontrar el valor
		if (localizando->getdatos(i)==x){
			cout<<"El valor ya se encuentra insertado"<<endl; //si lo encuentra tira insertado
			return false;//retorna falso para las funciones que depende de el
			}
	}
	cout<<"el valor no se encuentra"<<endl;//mensaje al usuario
	return true;//funcion que depende de el
}
Nodo * BTree::ordenar(Nodo ** n){
	//Algoritomo de ordenamiento Buble Sort
	Nodo * nuevo=*n	;
	int c1,c2,aux;
	for(c1=0;c1< 5;c1++)
			{
				for(c2=0;c2<5;c2++)
			{
				if(nuevo->getdatos(c2)>nuevo->getdatos(c2+1) && nuevo->getdatos(c2+1)!=-1)
				{
				aux=nuevo->getdatos(c2);
				nuevo->setdatos(c2,nuevo->getdatos(c2+1));
				nuevo->setdatos(c2+1,aux);
        }
      }

		}
	return nuevo;
}
//Metodo para mostrar			
void BTree :: show( )  {  	//Inicializa el metodo display en la raiz;
	display ( raiz ) ;  
} 
void BTree :: display ( Nodo *root ) {  	
if ( root != NULL ) {  		//Mientras el nodo que se mande no se nulo
	for ( int i = 0 ; i<root->disponible ; i++ )  		{  			
		display ( root -> getenlances(i) ) ;  			//Empezara por los valores de los enlances
		cout << root -> getdatos(i) << "\t" ; //Mostrara la los valores de la raiz, el i+1 es para comenzar en la posicion 1;ya que la primera sera para realizar un mejor acomodo en el nodo a la hora de dividir
		display ( root -> getenlances(i));
		}
}
}

	



Nodo * BTree::getraiz(){
	return raiz;
}
	


