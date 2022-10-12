//============================================================================
// Name        : LeerArchivo-AyB.cpp
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
   FILE * archivoA;
   archivoA = fopen("a.dat","rb");

   Especial raux;
   
   fread(&raux,sizeof(struct Especial), 1,archivoA);

   cout<<"archivoA"<<endl;
   while(!feof(archivoA)){
      cout<< "Legajo "<< raux.legajo<<endl;
      cout<< "dni  "<< raux.dni<<endl;
      cout<< "Nota 1  "<< raux.nota1<<endl;
      cout<< "Nota 2  "<< raux.nota2<<endl;
      fread(&raux,sizeof(struct Especial), 1,archivoA);
   }
   fclose(archivoA);
   cout<<"------------------------------"<<endl;

   FILE * archivoB;
   archivoB = fopen("b.dat","rb");

   fread(&raux,sizeof(struct Especial), 1,archivoB);
   cout<<"archivoB"<<endl;
   while(!feof(archivoB)){
      cout<< "Legajo "<< raux.legajo<<endl;
      cout<< "dni  "<< raux.dni<<endl;
      cout<< "Nota 1  "<< raux.nota1<<endl;
      cout<< "Nota 2  "<< raux.nota2<<endl;
      fread(&raux,sizeof(struct Especial), 1,archivoB);
   }
   fclose(archivoB);

	return 0;
}
