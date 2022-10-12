//============================================================================
// Name        : pilas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Estructura del NODO
struct Nodo{
   int info;
   Nodo *sgte;
};

void push(Nodo *&pila, int valor); //AGREGAR elementos a la pila
int pop(Nodo*&pila);//SACAR elementos de la pila; devuelve el dato del INFO del NODO(puede ser un valor int como este caso ó un registro(struct))

int main() {
	Nodo *pila = NULL; //Defino el puntero pila y lo inicializo en NULL.
	int aux2; // Defino aux2 para guardar el return del "pop" que sería el dato del INFO del NODO

	push(pila,1);
	push(pila,2);
	push(pila,3);

	while (pila!=NULL){
	   aux2=pop(pila);
	   cout<<aux2<<endl;

	}
	return 0;
}
void push(Nodo *&pila, int valor){
   //Crear nodo
   Nodo *nuevo = new Nodo(); //Pido memoria para el NODO "nuevo" que estoy CREANDO (new Nodo())
   //Cargar nodo
   nuevo->info =valor; //Carga el valor en el campo INFO del Nodo "nuevo" que necesito en la pila
   //Recorda que el puntero pila siempre está mirando al último nodo que ingresó
   nuevo->sgte = pila; //Conectar con la estructura (es decir a nuevo->sgte se le asigna el ÚLTIMO NODO QUE INGRESÓ)
   pila = nuevo; //finalmente el PUNTERO 'pila' se le asigna el nodo 'nuevo' que creamos es decir apunta al nuevo nodo
}

int pop(Nodo*&pila){
   int aux; //guardar el valor de retorno
   aux = pila->info; //Asigno a "aux" el último valor ingresado del info del nodo ya que la pila está apuntando al último que ingresó en push()
                     //Es decir está apuntando al nodo con el campo info = 3
   Nodo*q =pila; // se define el puntero 'q' y se le asigna el último nodo a la cúal la pila estaba apuntando
   pila = q->sgte; //Como el puntero 'q' ahora es igual a lo que miraba 'pila' tenemos que hacer que el puntero pila
                  //apunte al siguiente nodo en este caso al nodo con el campo info = 2 es decir hicimos esto: "pila=pila->sgte;"(otra forma) 
   delete (q);//elimine el nodo "q" ya que apuntaba a la pila con el campo info = 3 pero ya no lo necesitamos ya que guardamos su
               //'pila-info' en "aux" al principio
   return aux;
}
