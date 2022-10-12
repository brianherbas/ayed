//============================================================================
// Name        : matrices.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int main() {
	int vec [10]; //10 posiciones
	//cómo defino una matriz?
	//tipoDato nombreMatriz [filas][columnas]
	int mat [10][2]; //20 posiciones

	for (int i=0; i<10;i++){
	   //i es filas
	   for (int j=0; j<2;j++){
	      cout<<"ingrese un valor"<<endl;
	      cin>>mat[i][j];
	   }
	}

   for (int i=0; i<10;i++){
      //i es filas
      for (int j=0; j<2;j++){
         cout<< mat[i][j];
       }
      cout<<endl;
   }

	return 0;
}
