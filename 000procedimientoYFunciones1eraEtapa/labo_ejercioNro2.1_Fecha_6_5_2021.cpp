//============================================================================
// Name        : Lab2.cpp
// Solicitar un n�mero al usuario y determinar si es par o no.
//============================================================================

/* Estrategia de resoluci�n:
 * 1) Pedir el n�mero al usuario
 * 2) Leer el n�mero
 * 3) Determinar si es par o no (si el resto de div por 2 es 0)
 */

#include <iostream>
using namespace std;

void esPar (int valor);

int main() {
   int numero;
   bool rdo;

	cout << "Ingrese un valor" << endl;
	cin>> numero;

	esPar (numero);

	return 0;
}

void esPar (int valor){

   if ((valor % 2) == 0){
      cout<< "es par" << endl;
   } else {
      cout <<"es impar" <<endl;
   }
}
