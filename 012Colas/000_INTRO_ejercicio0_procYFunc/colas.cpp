//============================================================================
// Name        : Colas2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo* sgte;
};

void agregar (Nodo* &cfte, Nodo* &cfin,int v);// cola (2 punteros) & valor
int suprimir (Nodo* &cfte, Nodo* &cfin);// cola

int main() {
	//Definir la Cola
   Nodo* cfte=NULL;
   Nodo* cfin=NULL;
   //Cargar la cola
   /*
    agregar(cfte,cfin,1);
    agregar(cfte,cfin,2);
    agregar(cfte,cfin,3);
    agregar(cfte,cfin,4);
    */
   int carga;
   cout<<"ingrese un valor, 0 para terminar"<<endl;
   cin>>carga;

   while (carga !=0){
      agregar(cfte,cfin,carga);
      cout<<"ingrese un valor, 0 para terminar"<<endl;
      cin>>carga;
   } //la cola ya va a estar cargada

   //Mostrar la cola
   int rdo;
   while (cfte!=NULL){
      rdo = suprimir (cfte,cfin);
      cout<<rdo<<endl;
   }
	return 0;
}

void agregar (Nodo* &cfte, Nodo* &cfin,int v){
   //Crear el nodo
   Nodo* nuevo = new Nodo(); //Pido memoria para el NODO "nuevo" que estoy CREANDO (new Nodo())
   //cargar el nodo
   nuevo->info=v; //Carga el valor(v) en el campo INFO del Nodo "nuevo" que necesito en la cola
   nuevo->sgte = NULL; ////Conectar con la estructura (es decir a nuevo->sgte primero se le asigna NULL)
   //encolarlo
   if (cfte == NULL){ //Si el puntero "cfte" está apuntando a NULL quiere decir que no hay colas precargadas, entonces:
      cfte = nuevo;  //El puntero "cfte" tiene que apuntar al NODO que creamos "nuevo"
   }else {           // Si ya hay una cola precargada quiere decir que "cfte" ya esta apuntando a un NODO que existe, entonces:
      cfin->sgte=nuevo; //El puntero "cfin->sgte" tiene que apuntar al NODO que creamos "nuevo"
   }
   cfin=nuevo;    //Finalmente queda que el puntero "cfin" también apunte al NODO que creamos "nuevo"
}

int suprimir (Nodo* &cfte, Nodo* &cfin){
   int ret; //Variable donde guardaremos el primer valor de la cola para retornarlo
   Nodo*aux = cfte; // Creamos un puntero 'aux' para que apunte al primer NODO de la cola por eso le asignamos el puntero "cfte"
   ret = aux->info; // Como ahora 'aux' apunta al primer NODO, entonce guardamos en "ret" el valor "info" del primer NODO (un INT)
   cfte = aux->sgte; // Ahora al puntero "cfte" le decimos que mire al siguiente NODO (recorda que 'aux' tiene lo mismo que tenía "cfte"
                     // en un principio. Es decir podríamos haber hecho "cfte = cfte->sgte;" y funcionaba igual)
   if (cfte == NULL){ // Si "cfte" es NULL es decir no hay una cola precargada entonces:
      cfin = NULL;    // le asignamos a "cfin" NULL ya que sino se quedaría apuntando a NADA al hacer el "delete"
   }
   delete(aux); // Como ya nos guardamos el valor del primer NODO ahora podemos eliminarlo
   return ret;  // Retornamos dicho valor
}
