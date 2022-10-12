//============================================================================
// Name        : Listas.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo*sgte;
};

void agregarPrimero (Nodo*&Lista, int valor); //Agregar al principio
int eliminarPrimerNodo (Nodo*&Lista);//elimina el primer nodo y devuelve el valor(int) contenido en el mismo
void mostrar(Nodo*Lista);//recorre y muestra TODA la lista
void liberar(Nodo*&Lista);//recorre y libera TODA la lista (todos los nodos de la lista)
Nodo* buscar(Nodo*Lista,int valor);//Función: devuelve NULL cuando No lo encuentra y si lo
                                   //encuentra devuelve el nodo donde se encuentra el valor buscado
void buscarYMostrar(Nodo*Lista,int valor); //procedimiento: Mismo mecanismo que buscar() pero muestra directamente el valor del NODO
void insertarOrdenado(Nodo*&Lista, int valor); 
void ordenar(Nodo*&Lista); //Ordena los nodos de la lista fijandose en el valor contenido dentro del mismo
void agregarNodoFinal(Nodo*&Lista,int valor);

int main() {
   Nodo*L=NULL;

   agregarPrimero(L,1);
   agregarPrimero(L,0);
   agregarNodoFinal(L,2);
   insertarOrdenado(L,3);

   mostrar(L);
   liberar(L);
	return 0;
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

int eliminarPrimerNodo (Nodo*&Lista){
   int ret= Lista->info;
   Nodo*aux=Lista;
   Lista = Lista->sgte; //Lista=aux->sgte;
   delete (aux);
   return ret;
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

Nodo* buscar(Nodo*Lista,int valor){
   Nodo*aux=Lista;
   while(aux!=NULL && aux->info!=valor){
      aux=aux->sgte;
   }
   return aux; //retorna el nodo donde se encuentra el valor que buscamos. Si no lo encuentra retorna NULL
}

void buscarYMostrar(Nodo*Lista,int valor){
   Nodo*aux=Lista;
   while(aux!=NULL && aux->info!=valor){
      aux=aux->sgte;
   }
   if(aux==NULL){
      cout<<"No lo encontró"<<endl;
   }else{
      cout<<aux->info<<endl; //Muestra el valor dentro del nodo que buscamos.
   }
}

void insertarOrdenado(Nodo*&Lista, int valor){
   //crear el nodo
   Nodo* nuevo= new Nodo();
   //cargar el nodo
   nuevo->info=valor;
   nuevo->sgte=NULL;
   //enlazarlo (en dónde?)
   Nodo*aux=Lista; //este puntero lo creo para que lista no se modifique
   Nodo*ant=NULL; //este puntero es el que me va a permitir enlazar el nodo

   while(aux!=NULL && aux->info<valor){//definir el lugar de la lista en el que tiene que ir(va a insertarse entre ant y aux)
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

void ordenar(Nodo*&Lista){
   Nodo*Lista2;
   int ret;

   while (Lista!=NULL){
      ret=eliminarPrimerNodo(Lista);
      insertarOrdenado (Lista2,ret);
   }
   Lista=Lista2;
}

void agregarNodoFinal(Nodo*&Lista,int valor){
   //Crear el nodo
   Nodo* nuevo=new Nodo();
   //cargar el nodo
   nuevo->info=valor;
   nuevo->sgte=NULL;
   //enlazar al final
   if (Lista ==NULL){
      Lista=nuevo;
   }else {
      Nodo*aux=Lista;
      while(aux->sgte!=NULL){//avanzar hasta llegar al último nodo (el último nodo es aquel que su sgte es NULL)
         aux=aux->sgte;
      }//quiere decir que estoy mirando al ULTIMO nodo.
      aux->sgte=nuevo;
   }
}
