//============================================================================
// Name        : Ej4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Ejercicios 6, 7 y 8 Son similares pero aplicados de distinta forma
//Se tiene una lista con los productos de un depósito que contiene: id_prod, Unidades en stock.
//Además se cuenta con otra  lista de los nuevos pedidos que ingresaron (id_pro y unidades que entraron).
//Se pide actualizar la lista con los nuevos ingresos.

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

Nodo* buscar(Nodo*Lista,int valor);//devuelve NULL cuando No lo encuentra
void liberar(Nodo*&Lista);
void ejcomb4(Nodo*&ListaOrig,Nodo*&ListaPedido);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

void ejcomb4(Nodo*&ListaOrig,Nodo*&ListaPedido){
   Nodo*aux=ListaPedido;
   Nodo*rdo;

   while(aux!=NULL){
      rdo= buscar(ListaOrig, aux->info.idProd);
      rdo->info.cant=rdo->info.cant+aux->info.cant;
      aux= aux->sgte;
   }
   liberar (ListaPedido);
}

void liberar(Nodo*&Lista){
   Nodo*aux;
   while(Lista!=NULL){
      aux=Lista;
      Lista=Lista->sgte;//Lista=aux->sgte;
      delete(aux);
   }
}

Nodo* buscar(Nodo*Lista,int valor){
   Nodo*aux=Lista;
   while(aux!=NULL && aux->info.idProd!=valor){
      aux=aux->sgte;
   }
   return aux;
}
