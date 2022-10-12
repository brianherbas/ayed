//============================================================================
// Name        : Archivos2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
   // el promedio de notas que tengo en mi archivo de enteros
   int raux;

   int sumatoria = 0;
   int cont = 0;

   //Paso 1
   FILE * Notas;

   //Paso 2
   Notas = fopen ("notas2021.dat","rb");

   //Paso 3
   fread (&raux, sizeof(int), 1, Notas);

   while(!feof(Notas)) {
      cout << raux << endl;
      //paso 4
      sumatoria = sumatoria + raux;
      cont++;

      fread (&raux, sizeof(int), 1, Notas);
   }
   // Paso 5
   fclose(Notas);

   cout << "El promedio es: " << sumatoria/cont << endl;

   return 0;
}
