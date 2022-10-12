//============================================================================
// Name        : Ej2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//(Es el mismo ejercicio de listas(ejercicio6))
//Dado un vector de registros de 20 posiciones que contiene: id_prod, Unidades en stock.
//Además se cuenta con una cola de los nuevos pedidos que ingresaron (id_pro y unidades que entraron).
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

int buscar (tInfo vec[], int len, int valor);// función de vectores amoldado al enunciado(vector de registros)
void ejcomb2(tInfo vec[], int len, Nodo* &cfte, Nodo* &cfin);
tInfo suprimir (Nodo* &cfte, Nodo* &cfin);

int main() {
	ejcomb2(vec,len,cfte,cfin);
	return 0;
}

void ejcomb2(tInfo vec[], int len, Nodo* &cfte, Nodo* &cfin){
   int pos;
   tInfo ret;

   while(cfte!=NULL){
      ret= suprimir(cfte,cfin);
      pos=buscar(vec,len,ret.idProd);
      if(pos>-1){ // si no es "-1" entonces lo encontró
         vec[pos].cant= vec[pos].cant + ret.cant;
      } else{
         cout<<"error"<<endl;
      }
   }
}

tInfo suprimir (Nodo* &cfte, Nodo* &cfin){
   int ret;
   Nodo*aux=cfte;
   ret = aux->info;
   cfte=aux->sgte;
   if (cfte==NULL){
      cfin=NULL;
   }
   delete (aux);
   return ret;
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
