//============================================================================
// Name        : Archivos2021.cpp
// PD: Antes de ejecutar esto me queda pendiente crear el archivo "Algoritmos.dat" y ubicarlo en
//     en el mismo workspace
// Consigna    : Dado el Archivo de Algortimos, calcular el promedio de 1° parcial y 2° parcial
//============================================================================

#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno{
   int legajo;
   int dni;
   int nota1;
   int nota2;
};

int main() {
   Alumno raux;

   int sumaP1 = 0;
   int sumaP2 = 0;
   int contP1 = 0;
   int contP2 = 0;

   //Paso 1
   FILE*Alum;

   // Paso 2
   Alum = fopen ("Algoritmos.dat","rb");

   //Paso 3
   fread (&raux,sizeof (struct Alumno),1,Alum);

   while (!feof(Alum)){
      //hago este paso sólo para mostrar por pantalla el archivo
      cout<< "registro legajo "<< raux.legajo<<endl;
      cout<< "registro dni "<< raux.dni<<endl;
      cout<< "registro nota1 "<< raux.nota1<<endl;
      cout<< "registro Nota2 "<< raux.nota2<<endl;

      //Paso 4 - Asumo que puedo no tener notas en los parciales entonces uso los Ifs
      if(raux.nota1 >0){
      sumaP1 = sumaP1 + raux.nota1;
      contP1++;
      }

      if(raux.nota2 >0){
      sumaP2 = sumaP2 + raux.nota2;
      contP2++;
      }

      fread (&raux,sizeof (struct Alumno),1,Alum);
   }

   //Paso 5
   fclose (Alum);

   cout<< "El promedio de notas del parcial 1 es:  " << sumaP1/contP1 <<endl;
   cout<< "El promedio de notas del parcial 2 es:  " << sumaP2/contP2 <<endl;

	return 0;
}
