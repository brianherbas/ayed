//============================================================================
// Name        : Ej1b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


//desarrolle un procedimiento que genere una lista sin orden a partir de la intersección de 2 listas

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo* sgte;
};

void ej1b (Nodo* &Lista1, Nodo* &Lista2, Nodo * &Lista3);//Lista 1 y Lista luego no las voy a usar
Nodo* buscar(Nodo*Lista,int valor);
void liberar(Nodo*&Lista);
void agregarPrimero (Nodo*&Lista, int valor);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

void ej1b (Nodo* &Lista1, Nodo* &Lista2, Nodo * &Lista3){
   Nodo*aux=Lista1;
   Nodo*rdo;
   while(aux!=NULL){
      rdo=buscar(Lista2, aux->info);
      if (rdo!=NULL){ //Si es distinto de NULL quiere decir que lo encontró, significa que
                        // está presente en la lista 1 y en la lista 2, entonces lo escribo en la lista 3
         agregarPrimero(Lista3, aux->info);
      }
      aux=aux->sgte;
   }

   liberar(Lista1);
   liberar(Lista2);
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
   while(aux!=NULL && aux->info!=valor){
      aux=aux->sgte;
   }
   return aux;
}
void agregarPrimero (Nodo*&Lista, int valor){
   //crear el nodo
   Nodo* nuevo =new Nodo ();
   //cargar el nodo
   nuevo->info=valor;
   nuevo->sgte=NULL;
   //enlazar el nodo
   if (Lista!=NULL){
      nuevo->sgte=Lista;
   }
   Lista=nuevo;
}
