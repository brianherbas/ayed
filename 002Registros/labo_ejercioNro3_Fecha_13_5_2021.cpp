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
    int sum;
    int cont;

    sum = 0;
    cont = 0;
    

        cout << "Ingresar un Legajo" << endl;
        cin >> alu.Legajo;

        cout << "Ingrese un numero de curso:" << endl;
        cin >> alu.Curso;

        cout << "Ingrese una nota:" << endl;
        cin >> alu.Nota;

        max.Legajo = alu.Legajo;
        max.Curso = alu.Curso;
        max.Nota = alu.Nota;

    while (alu.Legajo > 0) {

        sum = sum + alu.Nota;
        cont++;

        if(alu.Nota > max.Nota) {
            max.Legajo = alu.Legajo;
            max.Curso = alu.Curso;
            max.Nota = alu.Nota;
        }

        cout << "Ingresar un Legajo" << endl;
        cin >> alu.Legajo;

        cout << "Ingrese un numero de curso:" << endl;
        cin >> alu.Curso;

        cout << "Ingrese una nota:" << endl;
        cin >> alu.Nota;

    }

    cout << "El legajo de nota más alta es: " << max.Legajo << endl;
    cout << "El curso de nota más alta es: " << max.Curso << endl;
    cout << "La nota más alta es: " << max.Nota << endl;

    Promedio2(sum,cont);

	return 0;
}

void Promedio2 (int sum, int cant) {
    int aux;
    if (cant > 0){
        aux = sum / cant;
        cout << "El promedio de las notas ingresadas es " << aux << endl;
    } else {
        cout << "No se pudo calcular el promedio porque no se ingresaron valores" << endl;
    }
}