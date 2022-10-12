/****************************************
Name        : ApareoArchivos2021.cpp
Consigna:
    Crear archivo "a" y "b" para probar el primer ejercicio de apareo que se vio en clase
*****************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno{
   int legajo;
   int dni;
   int nota1;
   int nota2;
};

int main() {

   // archivo a ->

   Alumno rcarga;

   FILE * AluA;

   AluA = fopen("a.dat","wb");

   cout<<"---------cargaArchivoA---------"<<endl;
   cout<<"ingrese el legajo del alumno"<<endl;
   cin>>rcarga.legajo;

   while(rcarga.legajo > 0){
      cout<<"Ingrese el dni"<<endl;
      cin>> rcarga.dni;

      cout<<"Ingrese nota1"<<endl;
      cin>>rcarga.nota1;

      cout<<"Ingrese nota2"<<endl;
      cin>>rcarga.nota2;

      fwrite(&rcarga,sizeof (struct Alumno),1,AluA);

      cout<<"ingrese el legajo del alumno"<<endl;
      cin>>rcarga.legajo;
   }
   fclose(AluA);

   // archivo b ->

   // Alumno rcarga;

   FILE * AluB;

   AluB = fopen("b.dat","wb");

   cout<<"---------cargaArchivoB---------"<<endl;
   cout<<"ingrese el legajo del alumno"<<endl;
   cin>>rcarga.legajo;

   while(rcarga.legajo > 0){
      cout<<"Ingrese el dni"<<endl;
      cin>> rcarga.dni;

      cout<<"Ingrese nota1"<<endl;
      cin>>rcarga.nota1;

      cout<<"Ingrese nota2"<<endl;
      cin>>rcarga.nota2;

      fwrite(&rcarga,sizeof (struct Alumno),1,AluB);

      cout<<"ingrese el legajo del alumno"<<endl;
      cin>>rcarga.legajo;
   }
   fclose(AluB);

	return 0;
}
