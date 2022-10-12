//============================================================================
// Name        : Ejercicio1.cpp
// Author      : Brian
// Version     : 1.0
// Enunciado: pedir 3 valores y calcular el promedio
// Estrategia: 1) Pedir 3 valores
//             2) Leer 3 valores
//             3) Calcular promedio
//============================================================================

#include <iostream>
using namespace std;

void Promedio (int n1, int n2, int n3);
void Promedio2 (int sum, int cant);

int main() {
    
    int val1;
    // int val2;
    // int val3;
    int acum = 0;
    int cont = 0;
    int i;
    // int promedio;
    
    for (i = 0; i < 3; i++) {
        cout << "Ingrese un valor" << endl;
        cin >> val1;

        acum = acum + val1;
        cont ++;
    }

    Promedio2 (acum, cont);

    
    return 0;
}

void Promedio (int n1, int n2, int n3) {
    int aux;

    aux = (n1 + n2 + n3) / 3;
    cout << "El promedio es " << aux << endl;
}

void Promedio2 (int sum, int cant) {
    int aux;
    aux = sum / cant;
    cout << "El promedio es " << aux << endl;
}