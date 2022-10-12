#include <iostream>
using namespace std;

void Promedio2 (int sum, int cant);

struct Alumno {
    int Legajo;
    int Curso;
    int Nota;
};

int main() {
    Alumno alu; //estoy definiendo una variable del tipo de dato Alumno
    Alumno max; //registro para la nota mas alta
    int sum = 0;
    

    for(int i=0; i<3; i++) {
        cout << "Ingresar un Legajo" << endl;
        cin >> alu.Legajo;

        cout << "Ingrese un numero de curso:" << endl;
        cin >> alu.Curso;

        cout << "Ingrese una nota:" << endl;
        cin >> alu.Nota;

        sum = sum + alu.Nota;
    }


    Promedio2(sum,3);

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