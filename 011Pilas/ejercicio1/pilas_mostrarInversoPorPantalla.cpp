//============================================================================
// Name        : Ej1Pilas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Clase 7 2°C - 30/09/2021

// Dado un lote de números, ingresados por el usuario y terminando con 0, mostrar el orden inverso por pantalla

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo *sgte;
};

void push(Nodo *&pila, int valor);
int pop(Nodo*&pila);//tipo del info del nodo

int main() {
	// Definir la pila
   Nodo* pila= NULL;

   //Cargar la pila
   int carga;
   cout<<"ingrese un valor distinto de 0"<<endl;
   cin>>carga;

   while(carga !=0){
      push(pila,carga);
      cout<<"ingrese un valor distinto de 0"<<endl;
      cin>>carga;
   }
   //en este punto la pila ya está cargada

   //mostrar el contenido de la pila
   int aux;
   while(pila !=NULL){
      aux=pop(pila);
      cout<<"valor:   "<<aux<<endl;
   }
   //mostré cada elemento de la pila, la pila no tiene más nodos
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
