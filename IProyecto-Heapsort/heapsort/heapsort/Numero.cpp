#include "stdafx.h"
#include "Numero.h"


Numero::Numero(void)
{int numero=0;
}


Numero::~Numero(void)
{
}

void Numero::setnumero(int n){
	numero=n;
}

int Numero::getnumero(){
	return numero;
}