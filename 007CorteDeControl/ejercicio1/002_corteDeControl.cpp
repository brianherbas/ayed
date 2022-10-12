//============================================================================
// Name        : CorteDeControl2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

struct multa{
   int dominio;
   int tipoMulta;
   int importe;
};

int main() {
	FILE * Multas;

	Multas = fopen ("multas.dat","rb");

	multa rAux;
	int anterior;
	int sumaMulta;

	fread (&rAux, sizeof(struct multa),1,Multas);

	while(!feof(Multas)){
	   anterior = rAux.dominio;
	   sumaMulta=0;

	   while (!feof(Multas)&&(anterior == rAux.dominio)){
	      sumaMulta= sumaMulta + rAux.importe;
	      fread (&rAux, sizeof(struct multa),1,Multas);
	   }
	   cout<<"Dominio " << anterior <<" tiene un total de multas de: "<<sumaMulta<<endl;
	}

	fclose (Multas);
	return 0;
}
