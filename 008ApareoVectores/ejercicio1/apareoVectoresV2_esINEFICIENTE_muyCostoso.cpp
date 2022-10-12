//============================================================================
// Name        : ApareoVectorV2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

void mostrar (int v[], int len);
void insertar (int vec[], int &len, int valor, int pos);
void insertarOrdenado (int vec[], int &len, int valor);

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

   //otra versión del apareo
   int z=0;
   for (int i=0; i<lenA; i++){
      vecC[z]= vecA[i];
      lenC++;
      z++;
   } //vecC va a contener los todos los valores del vecA en el mismo orden que vecA

   for (int i=0; i<lenB; i++){
      insertarOrdenado (vecC, lenC, vecB[i]);
   }
   mostrar (vecC, lenC);

   return 0;
}

void mostrar (int v[],int len){
   for (int i=0; i<len;i++){
      cout<<v[i]<<endl;
   }
}
void insertar (int vec[], int &len, int valor, int pos){
   for(int i=len; i>pos; i--){
      vec[i]=vec[i-1];
   }
   vec[pos]=valor; //insertando un nuevo valor al vector
   len++; //cada vez que inserto un elemento al vector incremento el len
}

void insertarOrdenado (int vec[], int &len, int valor){

   int i=0;
   //determinar la pos en la que tengo que insertar
   while (i<len && vec[i]<=valor){
      i++;
   }
   //insertar en la posición
   if (i==len){
      vec[len]=valor;
      len++;
   }else insertar (vec,len,valor,i);

}
