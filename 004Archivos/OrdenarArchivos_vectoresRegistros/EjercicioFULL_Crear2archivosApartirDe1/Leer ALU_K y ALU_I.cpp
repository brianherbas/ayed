//============================================================================
// Name        : LeerALUK.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

struct Especial {
   int Leg;
   char NyA;
   int C1P;
   int C2P;
};

int main() {
   FILE * K;
   K = fopen("ALU_K.dat","rb");

   Especial raux;
   
   fread(&raux,sizeof(struct Especial), 1,K);

   cout<<" Archivo K"<<endl;
   while(!feof(K)){
      cout<< "Legajo "<< raux.Leg<<endl;
      cout<< "NyA  "<< raux.NyA<<endl;
      cout<< "Nota 1  "<< raux.C1P<<endl;
      cout<< "Nota 2  "<< raux.C2P<<endl;
      fread(&raux,sizeof(struct Especial), 1,K);
   }
   fclose(K);

   FILE * I;
   I = fopen("ALU_I.dat","rb");

   fread(&raux,sizeof(struct Especial), 1,I);
   
   cout<<" Archivo I"<<endl;
   while(!feof(I)){
      cout<< "Legajo "<< raux.Leg<<endl;
      cout<< "NyA  "<< raux.NyA<<endl;
      cout<< "Nota 1  "<< raux.C1P<<endl;
      cout<< "Nota 2  "<< raux.C2P<<endl;
      fread(&raux,sizeof(struct Especial), 1,I);
   }
   fclose(I);

	return 0;
}
