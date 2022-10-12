/****************************************
Name        : Archivos2021.cpp
pd: Antes de ejecutar ubicar primero el archivo "vendedores.dat" en el workspace
Consigna:
    Dado un archivo de vendedores de un local de electrónica (Los campos del registro son: CodVendedor,Categoría, CantUnidVend). 
    Crear 2 nuevos archivos por cada categoría y cargalos con los vendedores del original. 
    (Los campos del registro CodVendedor, CantUnidVend). Las categorías de los vendedores son 2: 'T' Telefonía e 'I' de informática
*****************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Vendedor{
   int codVend;
   char cat;
   int cantUnid;
};

int main() {
   Vendedor raux;

   //Paso 1
   FILE * Vend;
   FILE * Tel;
   FILE * Inf;

   //Paso 2
   Vend= fopen ("vendedores.dat", "rb"); //es el que existe y del cual voy a leer
   Tel = fopen ("telefonia.dat", "wb"); // creo estos 2 nuevos
   Inf = fopen ("informatica.dat", "wb");

   //Paso 3 - Leer
   fread(&raux,sizeof(struct Vendedor),1,Vend);

   while(!feof(Vend)){

      //Paso 4 - Procesar (Escribir en los nuevos archivos)
      if (raux.cat=='I'){
         fwrite(&raux,sizeof(struct Vendedor),1,Inf);
      }else if (raux.cat=='T'){
         fwrite(&raux,sizeof(struct Vendedor),1,Tel);
      }

      fread(&raux,sizeof(struct Vendedor),1,Vend);
   }

   //Paso 5
   fclose(Vend);
   fclose (Tel);
   fclose (Inf);

/*
   //Quiero ver lo que genero en Informatica y Telefonia (para probar esto comentar lo de arriba)

   Inf=fopen("informatica.dat","rb");

   fread(&raux, sizeof (struct Vendedor),1,Inf);

   while(!feof (Inf)){
      cout<< "Inf cod vend "<< raux.codVend<<endl;
      cout<< "Inf cat "<< raux.cat<<endl;
      cout<< "Inf cant unidades "<< raux.cantUnid<<endl;

      fread(&raux, sizeof (struct Vendedor),1,Inf);
   }

   fclose(Inf);

   Tel=fopen("telefonia.dat","rb");

   fread(&raux, sizeof (struct Vendedor),1,Tel);

      while(!feof (Tel)){
         cout<< "Tel cod vend "<< raux.codVend<<endl;
         cout<< "Tel cat "<< raux.cat<<endl;
         cout<< "Tel cant unidades "<< raux.cantUnid<<endl;

         fread(&raux, sizeof (struct Vendedor),1,Tel);
      }

      fclose(Tel);
*/
	return 0;
}
