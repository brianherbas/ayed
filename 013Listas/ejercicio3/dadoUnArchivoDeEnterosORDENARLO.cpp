//============================================================================
// Name        : EJ1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// DADO un archivo de enteros ordenarlo

#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo{
   int info;
   Nodo*sgte;
};

void insertarOrdenado(Nodo*&Lista, int valor);
void liberar(Nodo*&Lista);//libera TODA la lista (todos los nodos de la lista)

int main() {
   //Paso 1: Definir un puntero a archivo
   FILE* Arch;

   //Paso 2: Abrir el archivo (leer)
   Arch = fopen ("archivo.dat", "rb");

   //Paso 3: Lectura
   int raux;
   //defino el puntero de la lista
   Nodo *lista;
   fread (&raux,sizeof(int),1,Arch);

   while (!feof(Arch)){
      //Paso 4: Procesar (Ordenar)- a) Definir la lista b)insertar de manera ordenada en la lista
      insertarOrdenado(lista,raux);
      fread (&raux,sizeof(int),1,Arch);
   }//leí el archivo y cargué la lista

   //Paso 5: Cerrar el archivo -->> leí el archivo y cargué la lista
   fclose(Arch);

   //Paso 6: Abrir el archivo para escribir
   Arch=fopen("archivo.dat","wb");

   //Paso 7: Recorro la lista y cargo el archivo
   Nodo *aux=lista; //defino un puntero auxiliar 'aux' en el cual le asigno el puntero de la lista que procesamos anteriormente(insertarOrdenado)
    //Recorro la lista
   while(aux!=NULL){
       //cargo el archivo
      fwrite(&aux->info,sizeof(int),1,Arch);
      aux=aux->sgte;
   }

////////////////
    /*Esto que está comentado es otra forma de recorrer la lista, cargarla y a la vez ir liberando la lista por cada iteraciób*/
   /* int ret;
    * while (lista!=NULL){
    * ret=eliminar1erNodo(lista);
    * fwrite(&ret,sizeof(int),1,Arch);
    * }
    */
/////////////////////

   //Paso 8: SIEMPRE LIBERAR la lista y Cerrar el archivo
   fclose(Arch);
   liberar(lista); //IMPORTANTE

	return 0;
}

void liberar(Nodo*&Lista){
   Nodo*aux;
   while(Lista!=NULL){
      aux=Lista;
      Lista=Lista->sgte;//Lista=aux->sgte;
      delete(aux);
   }
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
