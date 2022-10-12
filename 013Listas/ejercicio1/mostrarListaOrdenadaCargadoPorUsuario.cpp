//============================================================================
// Name        : Ej1Listas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Dado un lote de valores ingresados por el usuario y temrinando con 0, mostrarlos ordenados.

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo* sgte;
};

void mostrar(Nodo*Lista);//recorre y muestra TODA la lista
void insertarOrdenado(Nodo*&Lista, int valor);
void liberar(Nodo*&Lista);//recorre y libera TODA la lista (todos los nodos de la lista)

int main() {
	//definir la lista
   Nodo* lista=NULL;

   //cargar la lista ordenadamente
   int carga;

   cout<<"ingrese un valor distinto de 0"<<endl;
   cin>>carga;

   while(carga!=0){
      insertarOrdenado(lista,carga);
      cout<<"ingrese un valor distinto de 0"<<endl;
      cin>>carga;
   }//ya tengo la lista ordenda

   //mostrar la lista
   mostrar(lista);
   //liberar la lista
   liberar(lista);

	return 0;
}

void insertarOrdenado(Nodo*&Lista, int valor){
   //crear el nodo
   Nodo* nuevo= new Nodo();
   //cargar el nodo
   nuevo->info=valor;
   nuevo->sgte=NULL;
   //enlazarlo (en dónde?)
   Nodo*aux=Lista; //este lo creo para que lista no se modifique
   Nodo*ant=NULL; //este es el que me va a permitir enlazar el nodo

   while(aux!=NULL&& aux->info<valor){//definir el lugar de la lista en el que tiene que ir(va a insertarse entre ant y aux)
      ant=aux;
      aux=aux->sgte;
   }
   if(ant==NULL){//1) lista vacia ó 2) su lugar sea el primero de la lista
      Lista=nuevo;
   }else {//1) en alguna parte de la lista ó 2)que lo agregue al final
      ant->sgte=nuevo;
   }
   nuevo->sgte=aux;
}

void mostrar(Nodo*Lista){
   Nodo*aux=Lista;
   while(aux!=NULL){
      cout<<aux->info<<endl;
      aux=aux->sgte;
   }
}
void liberar(Nodo*&Lista){
   Nodo*aux;
   while(Lista!=NULL){
      aux=Lista;
      Lista=Lista->sgte;//Lista=aux->sgte;
      delete(aux);
   }
}
