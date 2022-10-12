//============================================================================
// Name        : Ej3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Mismo ejercicio que sumaEntreListaYVectorDeRegistros.cpp pero EN SENTIDO INVERSO
//Ejercicios 6, 7 y 8 Son similares pero aplicados de distinta forma
//Se tiene una lista con los productos de un depósito que contiene: id_prod, Unidades en stock.
//Además se cuenta con un vector de los nuevos pedidos que ingresaron (id_pro y unidades que entraron).
//(No se nos dice cuantos posiciones tiene el vector dado)
//Se pide actualizar la lista con los nuevos ingresos.
// (o sea se tiene que sumar las unidades que entraron del vector con las Unidades en stock de la lista)


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

Nodo* buscar(Nodo*Lista,int valor);//devuelve NULL cuando No lo encuentra (Procedimiento BUSCAR de LISTAS)
void ejComb3 (tInfo vec[], int len, Nodo* &Lista);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

void ejComb3 (tInfo vec[], int len, Nodo* &Lista){
   Nodo*aux;
   for(int i=0; i<len;i++){
      aux=buscar(Lista,vec[i].idProd); //se le asigna el nodo retornado a 'aux'
      if(aux!=NULL){
         aux->info.cant= aux->info.cant + vec[i].cant;
      }else {
         cout<<"error"<<endl;
      }
   }
}

Nodo* buscar(Nodo*Lista,int valor){
   Nodo*aux=Lista;
   while(aux!=NULL && aux->info.idProd!=valor){
      aux=aux->sgte;
   }
   return aux;
}
