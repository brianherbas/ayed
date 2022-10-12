//============================================================================
// Name        : Ejercicio1.cpp
// Author      : Brian
// Version     : 1.0
// Enunciado: Solicitar un número al usuario y calcular:
//             a. La quinta parte de ese n�mero
//             b. El RESTO de la parte de ese n�mero
//             c. La s�ptima parte de la quinta parte
// Estrategia: 1) Pedir el n�mero al usuario
//             2) Leer el número que me ingresa el usuario
//             3) Hacer los c�lculos
//             4) Mostrar los resultados
//============================================================================

#include <iostream>
using namespace std;

int main() {

   //Declaraci�n de Variables
   int numero;
   bool rdo;


   cout << "Ingrese un valorrr" << endl;
   cin >> numero;
   
   esPar(numero);

//  rdo = esParF(numero)
/*
   if(rdo) {
       cout << "es par" << endl;
   } else {
       cout << "es impar" << endl;
   }
*/
   return 0;
}

void esPar (int valor) {
    if ((vallor % 2) == 0) {
        cout << "es par" << endl;
    } else {
        cout << "es impar" << endl;
    }
}

bool esParF (int val) {
    bool aux;
    if ((vallor % 2) == 0) {
        aux = true;
    } else {
        aux = false;
    }
    return aux;
}