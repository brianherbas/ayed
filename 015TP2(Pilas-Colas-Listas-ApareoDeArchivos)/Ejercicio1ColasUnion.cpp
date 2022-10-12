//ejercicio 1 tp2 (ALyED)
//Dadas 2 Colas de enteros (Cola A y Cola B) genere la UNION de ambos en Cola C.

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo *sgte;
};
void agregar (Nodo* &cfte, Nodo* &cfin,int v);
int suprimir (Nodo* &cfte, Nodo* &cfin);

#include <iostream>
using namespace std;

int main() {
   //defino punteros para cola A
   Nodo*colafteA=NULL;
   Nodo*colafinA=NULL;

   //defino punteros para cola B
   Nodo*colafteB=NULL;
   Nodo*colafinB=NULL;

   //defino punteros para cola C
   Nodo*colafteC=NULL;
   Nodo*colafinC=NULL;

   int auxA,AuxB;
   while(colafteA!=NULL){ 
      auxA=suprimir(colafteA,colafinA);
      agregar(colafteC,colafinC,auxA);
   }
   while(colafteB!=NULL){ 
      auxB=suprimir(colafteB,colafinB);
      agregar(colafteC,colafinC,auxB);
   }

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
