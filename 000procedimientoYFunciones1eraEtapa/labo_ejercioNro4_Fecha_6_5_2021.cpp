//============================================================================
// Name        : Ejercicio1.cpp
// Author      : Brian
// Version     : 1.0
// Enunciado: Dado un lote de numeros ingresados por el user,
//            este lote finaliza con un valor negativo,
//            calcular el promedio
// Estrategia: 1) Pedir al user el lote de valores
//             2) Leer valores por cada uno
//             3) por cada valor acumulo y cuento para luego calcular promedio
//             4) calcular promedio
//============================================================================

#include <iostream>
using namespace std;


void Promedio2 (int sum, int cant);
int main() {

    int numero;
    int acum = 0;
    int cont = 0;

    cout << "Ingrese un valor" << endl;
    cin >> numero;

    while (numero > 0) {
        acum = acum + numero;
        cont++;

        cout << "Ingrese un valor" << endl;
        cin >> numero;
    }


    Promedio2 (acum, cont);
    return 0;
}

void Promedio2 (int sum, int cant) {
    int aux;
    if (cant > 0){
        aux = sum / cant;
        cout << "El promedio es " << aux << endl;
    } else {
        cout << "No se pudo calcular el promedio porque no se ingresaron valores" << endl;
    }
}