//============================================================================
// Name        : CreoAlug.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno{
   int Leg;
   char NyA;
   char esp;
   int C1P;
   int C2P;
};

int main() {
   FILE * G;

   G = fopen ("ALU_G.dat","wb");

   int Leg;
   Alumno rcarga;

   cout<<"Ingrese un legajo y 0 para terminar"<<endl;
   cin>>Leg;

   while (Leg!=0){
      rcarga.Leg=Leg;
      cout<<"Ingrese el NyA (Solo se admite 1 carácter)"<<endl;
      cin>>rcarga.NyA;
      cout<<"Ingrese la esp (Solo se admite 1 carácter)"<<endl;
      cin>>rcarga.esp;
      cout<<"Ingrese la Nota1"<<endl;
      cin>>rcarga.C1P;
      cout<<"Ingrese la Nota2"<<endl;
      cin>>rcarga.C2P;

      fwrite(&rcarga,sizeof(struct Alumno),1,G);

      cout<<"Ingrese un legajo y 0 para terminar"<<endl;
      cin>>Leg;
   }

   fclose(G);

	return 0;
}
