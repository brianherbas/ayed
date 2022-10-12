//ejercicio 2 tp2 (ALyED)
//Dadas 2 Pilas de enteros (PilaA y PilaB) genere la UNION en la PilaC

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo *sgte;
};

void push(Nodo *&pila, int valor);
int pop(Nodo*&pila);//tipo del info del nodo

int main() {
   //defino puntero para pila A
   Nodo*pilaA=NULL;
   //defino puntero para pila B
   Nodo*pilaB=NULL;
   //defino puntero para pila C
   Nodo*pilaC=NULL;

   int auxA,auxB;
   while(pilaA!=NULL){
      auxA=pop(pilaA);
      push(pilaC,auxA);
   }
   while(pilaB!=NULL){
      auxB=pop(pilaB);
      push(pilaC,auxB);
   }
   //

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