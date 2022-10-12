/****************************************
Name        : Archivos2021.cpp
pd: Antes de ejecutar ubicar primero el archivo "stock.dat" en el workspace (aunque puede que este archivo que es el default
    que nos envió la profe este mal la parte de peso "Liviano" asi que primero podrías ejecutar el "crearArchivoStock.cpp"
    y entonces cargarlo manualmente y luego se crearía en el workspace
Consigna:
    Dado un archivo de stock con lo siguientes campos (codProd, peso, unid);
    Crear un archivo con los productos que tienen menos de 100 unidades (con los siguientes campos: codProd, peso, unid)
    Crear un segundo archivo con los productos livianos, peso menos a 5 kilos (con los siguientes campos: codProd, unid)
*****************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Producto{
   int codProd;
   int peso;
   int unid;
};

struct Liviano{
   int codProd;
   int unid;
};

int main() {
   Producto raux;
   Liviano rcarga;

   //Paso 1
   FILE * Stock;
   FILE * Menos100;
   FILE * Liv;

   //Paso 2
   Stock = fopen("stock.dat", "rb");
   Menos100 = fopen ("menos100.dat", "wb");
   Liv = fopen ("livianos.dat", "wb");

   //Paso 3
   fread(&raux,sizeof (struct Producto),1,Stock);

   while (!feof(Stock)){
      //Paso 4 - Cargar los archivos que cree

      if(raux.unid<100){
         fwrite(&raux,sizeof (struct Producto),1,Menos100);
      }

      if (raux.peso<5){
         rcarga.codProd = raux.codProd;
         rcarga.unid = raux.unid;

         fwrite(&rcarga,sizeof (struct Liviano),1,Liv);
      }

      fread(&raux,sizeof (struct Producto),1,Stock);
   }

   fclose (Stock);
   fclose (Menos100);
   fclose (Liv);
/*

   //Quiero ver lo que genero en Menos100 y lo que tenía Stock

      Menos100=fopen("menos100.dat","rb");

      fread(&raux, sizeof (struct Producto),1,Menos100);

      while(!feof (Menos100)){
         cout<< "M100 cod prod "<< raux.codProd<<endl;
         cout<< "M100 peso "<< raux.peso<<endl;
         cout<< "M100 cant unidades "<< raux.unid<<endl;

         fread(&raux, sizeof (struct Producto),1,Menos100);
      }

      fclose(Menos100);

      Liviano raux1;

      Liv=fopen("livianos.dat","rb");

      fread(&raux1, sizeof (struct Liviano),1,Liv);

         while(!feof (Liv)){
            cout<< "Liv cod prod "<< raux1.codProd<<endl;
            cout<< "Liv cant unidades "<< raux1.unid<<endl;

            fread(&raux1, sizeof (struct Liviano),1,Liv);
         }

         fclose(Liv);
*/
	return 0;
}
