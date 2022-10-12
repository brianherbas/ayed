//============================================================================
// Name        : OrdArch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Ordenar el archivo BurgerFast(ejercicio3delTP1) por código de producto. Se sabe que máximo tiene 200 registros.

#include <iostream>
#include <stdio.h>

using namespace std;

struct Producto{
   int codP;
   int cant;
   char tipo;
   int venc;
};

void inicializar (Producto vec [], int cantPos, Producto valorIni);
void insertar (Producto vec[], int &len, Producto valor, int pos);
void insertarOrdenado (Producto vec[], int &len, Producto valor);

int main() {
   Producto raux,rini;
   Producto vec[200];
   int len = 0; // si el vector no viene dado es decir no existe entonces sería "int len = 0;"
   //registro vacio para inicializar el vector
   rini.codP=0;
   rini.cant=0;
   rini.tipo='N';
   rini.venc=0;

   inicializar(vec,200,rini);

   FILE * burger;

   burger=fopen("BurgerFast.dat","rb");

   fread(&raux, sizeof(struct Producto),1, burger);

   while(!feof(burger)){

      insertarOrdenado(vec,len,raux);//me estoy llevando al vector el registro que leí del archivo

      fread(&raux, sizeof(struct Producto),1, burger);
   }

   fclose(burger);

   //ordeno el archivo
   burger=fopen("BurgerFast.dat","wb");

   for(int i=0; i<len; i++){
      fwrite(&vec[i],sizeof(struct Producto),1,burger);
   }
   fclose(burger);

	return 0;
}

void inicializar (Producto vec[], int cantPos, Producto valorIni){

   for (int i=0; i<cantPos; i++) {
      vec[i].codP = valorIni.codP;
      vec[i].cant = valorIni.cant;
      vec[i].tipo = valorIni.tipo;
      vec[i].venc = valorIni.venc;
   }
}

void insertar (Producto vec[], int &len, Producto valor, int pos){
   for(int i = len; i > pos; i--) {
      vec[i] = vec[i-1];
   }
   vec[pos].codP = valor.codP;
   vec[pos].cant = valor.cant;
   vec[pos].tipo = valor.tipo;
   vec[pos].venc = valor.venc; //insertando un nuevo valor al vector
   len++; //cada vez que inserto un elemento al vector incremento el len
}

void insertarOrdenado (Producto vec[], int &len, Producto valor){
   int i = 0;
   //determinar la pos en la que tengo que insertar
   while (i<len && vec[i].codP <= valor.codP) {
      i++;
   }
   //insertar en la posición
   if (i == len) {
      vec[len].codP = valor.codP;
      vec[len].cant = valor.cant;
      vec[len].tipo = valor.tipo;
      vec[len].venc = valor.venc;
      len++;
   } else insertar (vec,len,valor,i);
}
