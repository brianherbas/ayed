//============================================================================
// Name        : EjdeParcial2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Genere una lista ordenada a partir de la Unión de una pila y una cola, cargandolas con valores ingresados por el usuario.

struct Nodo{
   int info;
   Nodo *sgte;
};

void push(Nodo *&pila, int valor);
int pop(Nodo*&pila);//tipo del info del nodo
void agregar (Nodo* &cfte, Nodo* &cfin,int v);// cola (2 punteros) & valor
int suprimir (Nodo* &cfte, Nodo* &cfin);// cola
void mostrar(Nodo*Lista);//mostrar TODA la lista
void insertarOrdenado(Nodo*&Lista, int valor);

#include <iostream>
using namespace std;

int main() {
	//Definir una pila
   Nodo*pila=NULL;

   //definir una cola
   Nodo*colafte=NULL;
   Nodo*colafin=NULL;

   //definir la lista
   Nodo*lista=NULL;

   //cargar la pila
   int carga;
   cout<<"ingrese un valor distinto de 0"<<endl;
   cin>>carga;

   while(carga!=0){
      push(pila,carga);
      cout<<"ingrese un valor distinto de 0"<<endl;
      cin>>carga;
   }

   //cargar la cola
   cout<<"ingrese un valor distinto de 0"<<endl;
   cin>>carga;

   while(carga!=0){
      agregar(colafte,colafin,carga);
      cout<<"ingrese un valor distinto de 0"<<endl;
      cin>>carga;
   }

   //con ambas cargar la lista
   int aux;
   while(pila!=NULL){
      aux=pop(pila);
      insertarOrdenado(lista,aux);
   }

   while(colafte!=NULL){
      aux=suprimir(colafte,colafin);
      insertarOrdenado(lista,aux);
   }
   //ESTO NO ME LO PIDEN
   mostrar(lista);

	return 0;
}

void push(Nodo *&pila, int valor){
   //Crear nodo
   Nodo *nuevo = new Nodo(); //Pedí memoria para el nodo que estoy creando
   //Cargar nodo
   nuevo->info =valor; //cargando el valor que neceito en la pila
   nuevo->sgte = pila; //Conectar con la estructura
   pila =nuevo;
}

int pop(Nodo*&pila){
   int aux; //guardar el valor de retorno
   aux = pila->info;
   Nodo*q =pila;
   pila = q->sgte; //pila=pila->sgte;
   delete (q);//elimine el nodo
   return aux;
}

void agregar (Nodo* &cfte, Nodo* &cfin,int v){
   //Crear el nodo
   Nodo* nuevo = new Nodo();
   //cargar el nodo
   nuevo->info=v;
   nuevo->sgte = NULL;
   //encolarlo
   if (cfte == NULL){
      cfte =nuevo;
   }else {
      cfin->sgte=nuevo;
   }
   cfin=nuevo;
}

int suprimir (Nodo* &cfte, Nodo* &cfin){
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
