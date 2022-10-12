//============================================================================
// Name        : Ej3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*Se tiene un archivo de disponibilidad para las habitaciones de un hotel en la costa Verano2021.dat (sin Orden):
-  Número de Habitación: 999999
-  Tipo: ‘s’, ‘d’, ‘t’ o ‘c’ (Single, Doble, Triple o Cuádruple)
-  Días disponibles de la temporada: 999
-  Precio por día de la habitación: 999 (entero)
Se pide:
a) Ordenar el archivo Verano2021.DAT por precio de habitación
b) Armar una lista, ordenada por Número de habitación, y mostrarla por pantalla si el número de días
   disponibles es menor a 50 y son habitaciones singles o dobles.
 *
 */

#include <iostream>
#include <stdio.h>

using namespace std;

struct tInfo{
   int numHab;
   char tipo;
   int dias;
   int precio;
};

struct Nodo{
   tInfo info;
   Nodo* sgte;
};

void insertarOrdenado(Nodo*&Lista, tInfo valor);
void liberar(Nodo*&Lista);//libera TODA la lista (todos los nodos de la lista)
void mostrar(Nodo*Lista);//mostrar TODA la lista

int main() {
	FILE * Verano;

	Verano =fopen("Verano2021.dat","rb");
	tInfo raux;
	Nodo*lista=NULL;
	Nodo*listado=NULL;

	fread(&raux, sizeof(struct tInfo),1,Verano);

	while(!feof(Verano)){
        //a)
	   insertarOrdenado(lista,raux); // ACLARACIÓN: ORDENADO POR PRECIO (como parametro le pasamos el registro(raux) y luego en
       //                               el procedimiento insertarOrdenado() se realiza el proceso con su campo correspondiente(precio))
        //                              Para el parcial no hace falta modifical el insertarOrdenado()
       //                               (Con aclarar asi es válido y suficiente ya que el procedimiento "insertarOrdenado"
       //                               es un procedimiento que ya desarrollamos por lo cual para este ejercicio de tipo parcial
       //                               no es necesario modificar el procedimiento "insertarOrdenado" para que lo ordene por el
       //                               campo 'precio' como hicimos en ejercicio anteriores. Con esto se sobreentiende)

        //b)
	   if(raux.dias<50){
	      if(raux.tipo=='s'|| raux.tipo=='d'){
	         insertarOrdenado(listado,raux);//ACLARACIÖN: ORDENADO POR NUMERO DE HABITACIÓN (Aplica la misma explicación de arriba)
	      }
	   }
	   fread(&raux, sizeof(struct tInfo),1,Verano);
	}
	fclose(Verano);

	//punto B
	mostrar(listado);
	liberar(listado);

	//punto A
	Verano =fopen("Verano2021.dat","wb");
	Nodo*aux=lista;

	while(aux!=NULL){
	   fwrite(&aux->info,sizeof(struct tInfo),1,Verano);
	   aux=aux->sgte;
	}
	fclose(Verano);
	liberar(lista);

	return 0;
}
