//============================================================================
// Name        : LeerArchivoMultas.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

struct infoAuto {
   int dominio;
   int tipoMulta;
   int importe;
};

int main() {
   FILE * archivoMultas;
   archivoMultas = fopen("multas.dat","rb");

   infoAuto raux;
   
   fread(&raux,sizeof(struct infoAuto), 1,archivoMultas);

   cout<<"archivoMultas"<<endl;
   while(!feof(archivoMultas)){
      cout<< "dominio: "<< raux.dominio<<endl;
      cout<< "tipoMulta:  "<< raux.tipoMulta<<endl;
      cout<< "importe:  "<< raux.importe<<endl;
      fread(&raux,sizeof(struct infoAuto), 1,archivoMultas);
   }
   fclose(archivoMultas);
	return 0;
}
