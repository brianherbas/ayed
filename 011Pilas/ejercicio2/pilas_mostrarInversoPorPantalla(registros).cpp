//============================================================================
// Name        : Ej2Pilas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Dado un lote de números y caracteres Ejemplo (1,'A'), ingresados por el usuario y terminando con 0, mostrar el orden inverso por pantalla

#include <iostream>
using namespace std;

struct TInfo{
   int numero;
   char caracter;
};

struct Nodo{
   TInfo info;
   Nodo *sgte;
};


void push(Nodo *&pila, TInfo valor);
TInfo pop(Nodo*&pila);//tipo del info del nodo

int main() {
	//Definir la pila
   Nodo* pila=NULL;

   //Carga de la pila
   TInfo carga;

   cout<<"ingrese un valor y termine ingresando 0"<<endl;
   cin>>carga.numero;

   while(carga.numero!=0){
      cout<<"ingrese el caracter"<<endl;
      cin>>carga.caracter;

      push(pila,carga);

      cout<<"ingrese un valor y termine ingresando 0"<<endl;
      cin>>carga.numero;
   }//tengo la pila cargada

   //mostrar el contenido de la pila
   TInfo aux;
   while (pila!=NULL){
      aux=pop(pila);
      cout<<"el par es:  "<<aux.numero<<","<<aux.caracter<<endl;
   }//la pila quedó vacía

	return 0;
}

void push(Nodo *&pila, TInfo valor){
   //Crear nodo
   Nodo *nuevo = new Nodo(); //Pedí memoria para el nodo que estoy creando
   //Cargar nodo
   nuevo->info.numero =valor.numero; //cargando el valor que neceito en la pila
   nuevo->info.caracter =valor.caracter;
   nuevo->sgte = pila; //Conectar con la estructura
   pila =nuevo;
}

TInfo pop(Nodo*&pila){
   TInfo aux; //guardar el valor de retorno
   aux.numero = pila->info.numero;
   aux.caracter =pila->info.caracter;
   Nodo*q =pila;
   pila = q->sgte; //pila=pila->sgte;
   delete (q);//elimine el nodo
   return aux;
}
