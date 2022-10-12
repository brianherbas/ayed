//============================================================================
// Name        : Ej2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//

//Dado un archivo de registro (codPrd; tipodeProd) generar 2 archivos ordenados (según el tipo 'A' ó 'B') por codigo de producto

#include <iostream>
#include <stdio.h>

using namespace std;

struct tInfo{
   int codProd;
   char tipo;
};

struct Nodo{
   tInfo info;
   Nodo* sgte;
};

void insertarOrdenado(Nodo*&Lista, tInfo valor);
void liberar(Nodo*&Lista);//libera TODA la lista (todos los nodos de la lista)

int main() {
	//Paso 1: Declarar los punteros
   FILE* Arch;
   FILE* ArchA;
   FILE* ArchB;

   //Paso 2: Abrir el archivo (Arch)
   Arch =fopen("archivo.dat","rb");

   //Paso 3: Leer el archivo Arch
   tInfo raux;
   Nodo*listaA=NULL;
   Nodo*listaB=NULL;

   fread(&raux,sizeof(struct tInfo),1,Arch);

   while(!feof(Arch)){
      //Paso4: procesar - cargar las listas de manera ordenada
      if(raux.tipo == 'A'){
         insertarOrdenado(listaA,raux);
      }else {
         insertarOrdenado(listaB,raux);
      }
      fread(&raux,sizeof(struct tInfo),1,Arch);
   }
   //Paso 5: Cerrar el archivo original
   fclose(Arch);
   //Paso 6: Abrir el ArchA y voy a cargar el ArchA
   ArchA=fopen("archivoA.dat","wb");

   Nodo*aux=listaA;//defino un puntero auxiliar 'aux' en el cual le asigno el puntero de la listaA que procesamos anteriormente(insertarOrdenado)
    //Recorro la lista
   while (aux!=NULL){
       //cargo el archivo
      fwrite(&aux->info,sizeof(struct tInfo),1,ArchA);
      aux=aux->sgte;
   }
   //Paso 7: cerrar Archivo y liberar lista
   fclose(ArchA);
   liberar(listaA);

   //Paso 8: repetir para ArchB
   ArchB=fopen("archivoB.dat","rb");
   aux=listaB;

   while (aux!=NULL){
      fwrite(&aux->info,sizeof(struct tInfo),1,ArchB);
      aux=aux->sgte;
   }

   fclose(ArchB);
   liberar(listaB);

	return 0;
}
