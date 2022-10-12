//============================================================================
// Name        : Ej1Colas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Dado un lote de números ingresados por el usuario y terminando en 0, mostrarlos en orden

struct Nodo{
   int info;
   Nodo* sgte;
};

void agregar (Nodo* &cfte, Nodo* &cfin,int v);// cola (2 punteros) & valor
int suprimir (Nodo* &cfte, Nodo* &cfin);// cola

#include <iostream>
using namespace std;

int main() {
	//Definir la cola
   Nodo* colafte=NULL;
   Nodo* colafin=NULL;

   //Carga de la cola
   int valor;
   cout<<"ingrese un valor y termine con 0"<<endl;
   cin>>valor;

   while(valor!=0){
      agregar(colafte,colafin,valor);
      cout<<"ingrese un valor y termine con 0"<<endl;
      cin>>valor;
   }//ya tengo la cola cargada

   //mostrar el contenido de la cola
   int aux;
   while (colafte!=NULL){
      aux=suprimir(colafte,colafin);
      cout<<"el valor es: "<<aux<<endl;
   }//la cola quedó vacía

	return 0;
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
