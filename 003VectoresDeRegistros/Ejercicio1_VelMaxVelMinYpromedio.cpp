//============================================================================
// Name        : VectoresReg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
//Dado un vector de velocidades de autopistas con la siguiente estructura:
//- ID Auotopista
//-Vel Max
//-Vel Min
//Calcular: Vel Max, Vel Min y promedio de velocidades max

#include <iostream>
using namespace std;

struct Vel{
   int ID;
   int velMax;
   int velMin;
};

void velMax (Vel v[],int len);
void velMin (Vel v[],int len);
void promedio (Vel v[],int len);

int main() {
   Vel vec[200];
   int len;

   velMax(vec,len);
   velMin(vec,len);
   promedio(vec,len);

	return 0;
}

void velMax (Vel v[],int len){
   int posMax = 0;
   for(int i=1; i<len; i++) {
      if(v[i].velMax > v[posMax].velMax) {
         posMax = i;
      }
   }
   cout<<"la autopista con la máxima más alta es: "<< v[posMax].ID << " con una velocidad maxima de: "<< v[posMax].velMax <<endl;
}
void velMin (Vel v[],int len){
   int posMin = 0;
   for(int i=1; i<len; i++){
      if(v[i].velMin < v[posMin].velMin) {
         posMin = i;
      }
   }
   cout<<"la autopista con la mínima más baja es: " << v[posMin].ID << "con la velocidd mínimna de: "<< v[posMin].velMin <<endl;
}

void promedio (Vel v[],int len){
   int suma = 0;
   for(int i=0; i<len; i++) {
      suma = suma + v[i].velMax;
   }
   cout<<"el promedio es: "<< suma/len <<endl;
}
