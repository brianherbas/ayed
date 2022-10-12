//============================================================================
// Name        : Ej2Listas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Dado un lote de par de valores (1,a) ingresados por el usuario y temrinando con 0, mostrarlos ordenados.

#include <iostream>
using namespace std;

struct TInfo{
   int numero;
   char caracter;
};

struct Nodo{
   TInfo info;
   Nodo* sgte;
};

void mostrar(Nodo*Lista);//mostrar TODA la lista
void insertarOrdenado(Nodo*&Lista, TInfo valor);
void liberar(Nodo*&Lista);//libera TODA la lista (todos los nodos de la lista)


int main() {
	//definir la lista
   Nodo*lista=NULL;

   //cargar la lista
   TInfo carga;

   cout<<"ingrese un valor distinto de 0"<<endl;
   cin>>carga.numero;

   while(carga.numero!=0){
      cout<<"ingrese el caracter"<<endl;
      cin>>carga.caracter;
      insertarOrdenado(lista,carga);
      cout<<"ingrese un valor distinto de 0"<<endl;
      cin>>carga.numero;
   }//tengo la lista cargada

   //mostrar la lista
   mostrar(lista);
   //liberar la lista
   liberar(lista); //IMPORTANTE liberar al final

	return 0;
}

void insertarOrdenado(Nodo*&Lista, TInfo valor){
   //crear el nodo
   Nodo* nuevo= new Nodo();
   //cargar el nodo
   nuevo->info.numero=valor.numero;
   nuevo->info.caracter=valor.caracter;
   nuevo->sgte=NULL;
   //enlazarlo (en dónde?)
   Nodo*aux=Lista; //este lo creo para que lista no se modifique
   Nodo*ant=NULL; //este es el que me va a permitir enlazar el nodo

   while(aux!=NULL&& aux->info.numero<valor.numero){//definir el lugar de la lista en el que tiene que ir(va a insertarse entre ant y aux)
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
      cout<<aux->info.numero<<" "<< aux->info.caracter<<endl;
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
