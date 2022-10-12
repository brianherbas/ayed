//============================================================================
// Name        : ApareoVectores.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 
/* 
Se carga de manera hardcodeada los vectores A y B con su respectivo len. Luego
Se hace el Apareo de A y B de manera tal que va ordenando y cargando los valores en el vector C
teniendo como salida final: 
vecC = 
1
3
4
5
8
9
10
*/
//============================================================================

#include <iostream>
using namespace std;

void mostrar (int v[], int len);

int main() {
	//Vec A y el vec B existe y están ordenados

   int vecA [5];
   int vecB [5];
   int vecC [10]; // 5 + 5
   int lenC=0; //lenC= lenA+ lenB;

   //Para asegurar contenido vecA y vecB; NO HACER!!!
   vecA[0]=1;
   vecB[0]=3;
   vecA[1]=5;
   vecB[1]=4;
   vecA[2]=9;
   vecB[2]=8;
   vecB[3]=10;
   int lenA=3;
   int lenB=4;

   mostrar (vecA,lenA);
   mostrar (vecB,lenB);

   int i=0; //indice para vecA
   int j=0; //indice para vecB
   int z=0; //indice para VecC
   while (i<lenA && j<lenB){

      if (vecA[i]< vecB[j]){
         vecC[z]=vecA[i];
         lenC++;
         i++;
         z++;
      }else {
         vecC[z]=vecB[j];
         lenC++;
         j++;
         z++;
      }
   }

   while (i<lenA){
      vecC[z]=vecA[i];
      lenC++;
      i++;
      z++;
   }

   while (j<lenB){
      vecC[z]=vecB[j];
      lenC++;
      j++;
      z++;
   }

   mostrar (vecC, lenC);

   return 0;
}

void mostrar (int v[],int len){
   for (int i=0; i<len;i++){
      cout<<v[i]<<endl;
   }
}
