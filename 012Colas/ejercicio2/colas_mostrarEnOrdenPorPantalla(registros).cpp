//============================================================================
// Name        : Ej2Colas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Dado un lote de números y caracteres (1,a) ingresados por el usuario y terminando en 0, mostrarlos en orden
struct TInfo{
   int numero;
   char caracter;
};

struct Nodo{
   TInfo info;
   Nodo* sgte;
};

void agregar (Nodo* &cfte, Nodo* &cfin,TInfo v);// cola (2 punteros) & valor
TInfo suprimir (Nodo* &cfte, Nodo* &cfin);// cola

#include <iostream>
using namespace std;

int main() {
	//Definir Cola
   Nodo*colafte=NULL;
   Nodo*colafin=NULL;

   //Carga de la cola
   TInfo carga;

   cout<<"ingrese un valor distinto de 0"<<endl;
   cin>>carga.numero;

   while(carga.numero!=0){
      cout<<"ingrese el caracter"<<endl;
      cin>>carga.caracter;
      agregar (colafte,colafin,carga);
      cout<<"ingrese un valor distinto de 0"<<endl;
      cin>>carga.numero;
   }//cola cargada

   //mostrar el contenido
   TInfo aux;
   while(colafte!=NULL){
      aux=suprimir(colafte,colafin);
      cout<<"el par es: "<<aux.numero<< ","<<aux.caracter<<endl;
   }//quedó la cola vacía

	return 0;
}

void agregar (Nodo* &cfte, Nodo* &cfin,TInfo v){
   //Crear el nodo
   Nodo* nuevo = new Nodo();
   //cargar el nodo
   nuevo->info.numero=v.numero;
   nuevo->info.caracter=v.caracter;
   nuevo->sgte = NULL;
   //encolarlo
   if (cfte == NULL){
      cfte =nuevo;
   }else {
      cfin->sgte=nuevo;
   }
   cfin=nuevo;
}

TInfo suprimir (Nodo* &cfte, Nodo* &cfin){
   TInfo ret;
   Nodo*aux=cfte;
   ret.numero = aux->info.numero;
   ret.caracter =aux->info.caracter;
   cfte=aux->sgte;
   if (cfte==NULL){
      cfin=NULL;
   }
   delete (aux);
   return ret;
}
