// B-Tree.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "BTree.h"
#include "Nodo.h"
#include <iostream>
#include <fstream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int opcion=0,valor=0;
	bool salir=false;
	BTree * arbol=new BTree();
	cout<<"....................................."<<"\n"<<
		   "Tecnologico de Costa Rica"<<"\n"<<
		   "Estructuras de Datos" <<"\n"<<
		   "Segundo Proyecto Programa"<<"\n<"<<
		   "Implementacion de un Arbol B"<<
		  "....................................."<<endl;
	while (!salir){
		cout<<"*******************************************"<<"\n"<<
			  "*Seleccione una de las siguientes opciones*"<<"\n"<<
			  "*1.Inserte un valor al arbol              *"<<"\n"<<
			  "*2.Buscar un valor en el arbol			 *"<<"\n"<<
			  "*3.Eliminar un valor en el arbol          *"<<"\n"<<
			  "*4.Mostrar los elementos del arbol        *"<<"\n"<<
			  "*5.Salir del programa                     *"<<"\n"<<
			  "*******************************************"<<endl;
		cin>>opcion;
		cout<<"\n";
		
			if (opcion==1){
				cout<<"Ingrese el valor que desea insertar:  ";
				cin>>valor;
				cout<<"\n";
				arbol->insertar(valor);
			}
			if (opcion==2){
				cout<<"Cual valor desea buscar: ";
				cin>>valor;
				cout<<"\n";
				Nodo * mandar=arbol->buscarNODO(arbol->getraiz(),valor);
				bool localizar=arbol->buscar(valor,mandar);
			}
			if (opcion==3){
				cout<<"En estos momentos esta opcion no se encuentra disponible,disculpe las molestias"<<endl;
				cout<<"\n";
			}
			if (opcion==4){
				arbol->show();
				cout<<"\n";
			}
			if (opcion==5){
				salir=true;
			}
	}
	cout<<"Gracias por usarnos"<<endl;
	system ("pause");
	return 0;
}






