/****************************************
Name        : crearArchivoMultas.cpp
Consigna:
    Crear archivo "multas" para probar el primer ejercicio de corteDeControl que se vio en clase
*****************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Auto{
   int dominio;
   int tipoMulta;
   int importe;
};

int main() {

   // archivo multas ->

   Auto rcarga;

   FILE * archivoMultas;

   archivoMultas = fopen("multas.dat","wb");

   cout<<"---------cargaArchivoMultas---------"<<endl;
   cout<<"ingrese el dominio del auto"<<endl;
   cin>>rcarga.dominio;

   while(rcarga.dominio > 0){
      cout<<"Ingrese el tipoMulta"<<endl;
      cin>> rcarga.tipoMulta;

      cout<<"Ingrese importe"<<endl;
      cin>>rcarga.importe;

      fwrite(&rcarga,sizeof (struct Auto),1,archivoMultas);

      cout<<"ingrese el dominio del auto"<<endl;
      cin>>rcarga.dominio;
   }
   fclose(archivoMultas);

	return 0;
}
