//ejercicio 3 tp2 (ALyED)
//Dadas 1 Pila de enteros y 1 Cola de enteros, se pide cargar la UNION ambos en una Lista Ordenada y mostrarla por pantalla.


#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo *sgte;
};

int pop(Nodo*&pila);//tipo del info del nodo
int suprimir (Nodo* &cfte, Nodo* &cfin);// cola
void mostrar(Nodo*Lista);//mostrar TODA la lista
void insertarOrdenado(Nodo*&Lista, int valor);


int main() {
    //La pila, cola y lista ya vienen dados
	//Definir puntero para una pila
   Nodo*pila=NULL;

   //definir punteros para una cola
   Nodo*colafte=NULL;
   Nodo*colafin=NULL;

   //definir puntero para la lista
   Nodo*lista=NULL;

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
   
   mostrar(lista);

	return 0;
}

int pop(Nodo*&pila){
   int aux; //guardar el valor de retorno
   aux = pila->info;
   Nodo*q =pila;
   pila = q->sgte; //pila=pila->sgte;
   delete (q);//elimine el nodo
   return aux;
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
