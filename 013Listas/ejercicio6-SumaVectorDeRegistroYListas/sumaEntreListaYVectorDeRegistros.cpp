//============================================================================
// Name        : Ej1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Ejercicios 6, 7 y 8 Son similares pero aplicados de distinta forma
//Se nos da un vector de registros cargado de 20 posiciones que contiene: id_prod, Unidades en stock.
//Además se cuenta con una lista de los nuevos pedidos que ingresaron (id_pro y unidades que entraron.
//Se pide actualizar el vector con los nuevos ingresos. 
// (o sea se tiene que sumar las unidades que entraron de la lista a las unid. en stock del vector de registros)


#include <iostream>
using namespace std;

struct tInfo{
   int idProd;
   int cant;
};

struct Nodo{
   tInfo info;
   Nodo* sgte;
};
int buscar (tInfo vec[], int len, int valor); // función de vectores amoldado al enunciado(vector de registros)
void liberar(Nodo*&Lista);
void ejComb (tInfo Vec[], Nodo* &Lista);

int main() {

	return 0;
}

void ejComb (tInfo Vec[],int len, Nodo* &Lista){
   Nodo *aux=Lista;
   int pos;
   while (aux!=NULL){

      pos=buscar(Vec,len, aux->info.idProd);

      if (pos>-1){ // si no es "-1" entonces lo encontró
         Vec[pos].cant= Vec[pos].cant+aux->info.cant;
      }else {
         cout<<"error"<<endl;
      }
      aux=aux->sgte;
   }

   liberar(Lista);
}

int buscar (tInfo vec[], int len, int valor){
   int i=0;

   while (i<len && vec[i].idProd!=valor){
      i++;
   }

   if (i==len){
      return -1;
   } else return i;
}

void liberar(Nodo*&Lista){
   Nodo*aux;
   while(Lista!=NULL){
      aux=Lista;
      Lista=Lista->sgte;//Lista=aux->sgte;
      delete(aux);
   }
}
