//============================================================================
// Name        : LeerArchivoC.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

struct Especial {
   int legajo;
   int dni;
   int nota1;
   int nota2;
};

int main() {
   FILE * archivoC;
   archivoC = fopen("c.dat","rb");

   Especial raux;
   
   fread(&raux,sizeof(struct Especial), 1,archivoC);

   cout<<"archivoC"<<endl;
   while(!feof(archivoC)){
      cout<< "Legajo "<< raux.legajo<<endl;
      cout<< "dni  "<< raux.dni<<endl;
      cout<< "Nota 1  "<< raux.nota1<<endl;
      cout<< "Nota 2  "<< raux.nota2<<endl;
      fread(&raux,sizeof(struct Especial), 1,archivoC);
   }
   fclose(archivoC);
	return 0;
}
