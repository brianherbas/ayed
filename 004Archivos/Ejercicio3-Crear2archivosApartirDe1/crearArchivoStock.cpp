/****************************************
Name        : Archivos2021.cpp
Consigna:
    Crear archivo stock para probar el ejercicio3
*****************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Producto{
   int codProd;
   int peso;
   int unid;
};

int main() {
   Producto rcarga;

   FILE * Stock;

   Stock = fopen("stock.dat","wb");

   cout<<"ingrese el código de producto"<<endl;
   cin>>rcarga.codProd;

   while(rcarga.codProd >0){
      cout<<"Ingrese el peso"<<endl;
      cin>> rcarga.peso;

      cout<<"Ingrese las unidades"<<endl;
      cin>>rcarga.unid;

      fwrite(&rcarga,sizeof (struct Producto),1,Stock);

      cout<<"ingrese el código de producto"<<endl;
      cin>>rcarga.codProd;
   }

   fclose(Stock);

	return 0;
}
