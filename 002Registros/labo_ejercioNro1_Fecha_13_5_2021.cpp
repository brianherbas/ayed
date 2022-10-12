#include <iostream>
using namespace std;

// void Promedio2 (int sum, int cant);

struct Alumno {
    int Legajo;
    int Curso;
    int Nota;
};

int main() {
    Alumno alu;

    cout << "Ingresar un Legajo" << endl;
    cin >> alu.Legajo;


    cout << "Ingrese un numero de curso:" << endl;
    cin >> alu.Curso;

    cout << "Ingrese una nota:" << endl;
    cin >> alu.Nota;

    cout << "El legajo es :" << alu.Legajo << endl;
    cout << "El curso es: " << alu.Curso << endl;
    cout << "La nota es: " << alu.Nota << endl;
	return 0;
}