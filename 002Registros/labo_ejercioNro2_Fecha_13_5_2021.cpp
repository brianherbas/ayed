#include <iostream>
using namespace std;

void Promedio2 (int sum, int cant);

struct Alumno {
    int Legajo;
    int Curso;
    int Nota;
};

int main() {
    Alumno alu;
    Alumno alu2;
    Alumno alu3;

    int sum = 0;

    cout << "Ingresar un Legajo" << endl;
    cin >> alu.Legajo;

    cout << "Ingrese un numero de curso:" << endl;
    cin >> alu.Curso;

    cout << "Ingrese una nota:" << endl;
    cin >> alu.Nota;

    //////
    cout << "Ingresar un Legajo" << endl;
    cin >> alu2.Legajo;

    cout << "Ingrese un numero de curso:" << endl;
    cin >> alu2.Curso;

    cout << "Ingrese una nota:" << endl;
    cin >> alu2.Nota;

    //////
    cout << "Ingresar un Legajo" << endl;
    cin >> alu3.Legajo;

    cout << "Ingrese un numero de curso:" << endl;
    cin >> alu3.Curso;

    cout << "Ingrese una nota:" << endl;
    cin >> alu3.Nota;

    //////

    sum = alu.Nota + alu2.Nota + alu3.Nota;

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