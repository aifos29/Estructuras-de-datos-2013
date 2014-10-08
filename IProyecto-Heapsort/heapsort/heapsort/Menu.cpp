// heapsort.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> //tiene la definicion de la funcion RAND (random)
#include "Lista.h"
using std::cout;
using std::endl;
using std::cin;

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
Lista * lalista=new Lista(false,true);
 int cantidad=0;
 int opcion=0;
 cout<<"Tecnologico de Costa Rica"<<"\n"<<"Ingenieria en Computacion"<<"\n"<<"Algoritmo de ordenamiento Heapsort"<<"\n"<<endl;
 cout<<"1.Generar listas de numeros aleatoriamente"<<"\n"
	<<"2.Ingresar numeros de manera manualmente"<<endl;
 cin>>opcion;

 if (opcion==1){
	  cout << "Cuantos numeros quiere generar?" << endl;
 cin >> cantidad;
  for (int contador =1 ; contador <= cantidad ; contador++)
    {
    int numero=(  (1 + rand() % 100)); 
	lalista->agregar(numero); //mostramos por pantalla los numeros generados del 1 al 20
       //salto de linea para separlos
    }
 cout<<"Esta es la lista original"<<endl;
char resp_listaorignal[1000];
strcpy_s(resp_listaorignal,lalista->mostrar());
 cout<<resp_listaorignal<<endl;	
 cout<<"Esta es la lista ordenada"<<endl;
lalista->heapsort(cantidad);
char resp [1000]; //creara una variable llama resp que es de tipo char
strcpy_s (resp, lalista -> mostrar());//realizara una copia de el retorno tipo char de la funcion imprimir y la almacenara en resp
cout<< resp;//mostara la variable local resp al usuario
cout<<endl;
system("pause");

return 0;

}
 if (opcion==2){
int numero=0;
cout<<"Cuantos numeros desea agregar a a lista"<<"\n"<<endl;
cout<<">>"; 
cin>>numero;
int contador=0;
while (contador< numero){
	int n=0; 
	cout<<"Ingrese el numero que desea agregar"<<endl;
	cout<<">>"; cin>>n;
	lalista->agregar(n);
	contador ++;
}
 cout<<"Esta es la lista que usted digito"<<endl;
char resp_listaorignal[1000];
strcpy_s(resp_listaorignal,lalista->mostrar());
 cout<<resp_listaorignal<<endl;	
 cout<<"Esta es la lista ordenada"<<endl;
 lalista->heapsort(numero);
char resp [1000]; //creara una variable llama resp que es de tipo char
strcpy_s (resp, lalista -> mostrar());//realizara una copia de el retorno tipo char de la funcion imprimir y la almacenara en resp
cout<< resp;//mostara la variable local resp al usuario
cout<<endl;
system("pause");

return 0;

}

 }









		


