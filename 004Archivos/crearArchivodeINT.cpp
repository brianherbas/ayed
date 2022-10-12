//============================================================================
// Name        : Archivo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>

using namespace std;

//creo el archivo que voy a usar en el otro.cpp

int main() {
   int nota;

   FILE * K1151;
   K1151 = fopen ("notas2021.dat","wb");

	cout << "Ingrese una nota y 0 para finalizar" << endl;
	cin >> nota;

	while (nota > 0){
	   //carga al archivo
	   fwrite(&nota,sizeof(int),1,K1151);

	   cout << "Ingrese una nota" << endl;
	   cin >> nota;
	}

	fclose(K1151);

	return 0;
}
