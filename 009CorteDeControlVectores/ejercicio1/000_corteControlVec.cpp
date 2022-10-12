//============================================================================
// Name        : CorteControlVec.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct multa{
   int dominio;
   int tipoMulta;
   int monto;
};
void carga (multa v[], int &len);

int main() {
	multa vec [20];
	int len=0;

	//La carga(vec,len) no forma part del corte de control solo 
   //lo hago para poder probar el corte de control luego
	carga(vec,len);



   //(El comportamiento es igual al corte de control anterior que vimos con archivos)
	int i=0;

	while (i<len){
	   int anterior = vec[i].dominio;
	   int suma=0;

	   while (i<len && anterior == vec[i].dominio){
	      suma = suma + vec[i].monto;
	      i++;
	   }
	   cout<<"el dominio: " <<anterior<<"  debe: "<<suma<<endl;
	}
	return 0;
}

void carga (multa v[], int &len){
   int dominio;
   int i=0;

   cout<<"ingrese un dominio"<<endl;
   cin>> dominio;

   while(dominio > 0){
      v[i].dominio =dominio;
      cout<<"ingrese el tipo de multa"<<endl;
      cin>>v[i].tipoMulta;
      cout<<"ingrese el monto"<<endl;
      cin>>v[i].monto;
      len++;
      i++;
      cout<<"ingrese un dominio"<<endl;
      cin>> dominio;
   }
}
