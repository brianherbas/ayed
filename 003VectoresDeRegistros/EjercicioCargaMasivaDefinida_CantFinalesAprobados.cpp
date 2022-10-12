/****************************************
Realice un programa que almacene el número los datos de los finales de un alumno; se sabe que
el máximo de finales por estudiante es de 100. Los datos serán ingresados por el usuario y luego
pedirán resultados. El usuario ingresará:
a) Nombre del alumno
b) Legajo
c) Materia
d) Nota (se aprueba con 6)
Se pide:
a- Cantidad de finales aprobados
b- Promedio de notas

*****************************************/
#include <iostream>
using namespace std;

struct Alumno{
   char NyA; //para ejecutarlo se lo define como caracter simple y NO como cadena de caracteres
   int Legajo;
   char Materia;
   int Nota;
};

void inicializar (Alumno vec [], int cantPos, Alumno valorIni);
void cargaMasiva2 (Alumno v[], int &len, int CP); // CP = cantidad de posiciones
void finalesAprobados (Alumno v[], int len);
void promedio (Alumno v[], int len);

int main() {
   Alumno valini; //registro para inicializar el vector

   //Paso 1
   Alumno vec[100];
   int len=0;

   //Paso 2
   valini.NyA = '/0'; //inicializo con una cadena vacía
   valini.Legajo = 0;
   valini.Materia = '/0'; //inicializo con una cadena vacía
   valini.Nota = 0;

   inicializar (vec,100,valini);

   //Paso 3
   cargaMasiva2(vec,len,100);

   //Paso 4
   finalesAprobados (vec,len);
   promedio (vec,len);

	return 0;
}

void inicializar (Alumno vec [], int cantPos, Alumno valorIni){

   for (int i=0; i<cantPos; i++){
      vec [i].NyA = valorIni.NyA;
      vec [i].Legajo = valorIni.Legajo;
      vec [i].Materia = valorIni.Materia;
      vec [i].Nota = valorIni.Nota;
   }
}

void cargaMasiva2 (Alumno v[], int &len, int CP){ // CP = cantidad de posiciones
   int cantNotas;
   char NyA;
   int Legajo;
   cout<<"Ingrese la Cantidad de notas a cargar"<<endl;
   cin>>cantNotas;



   //Valido que me ingrese una cantidad de notas menor o igual que la cant de posiciones
   // Si el usuario ingresa una cantidad mayor a 100 va a seguir loopeando(preguntando) hasta que
   // ingrese un nro menor a 100 y asi pueda continuar.
   while (cantNotas>CP){
      cout<<"Ingrese la Cantidad de notas a cargar"<<endl;
      cin>>cantNotas;
   }

   cout<<"Ingrese el Nombre del Alumno (Solo se admite 1 carácter)"<<endl;
   cin>>NyA;
   cout<<"Ingrese el Legajo del Alumno (INT)"<<endl;
   cin>>Legajo;

   for (int i=0; i<cantNotas; i++){
      v[i].NyA =NyA;
      v[i].Legajo =Legajo;
      cout<<"Ingrese la Materia (Solo se admite 1 carácter)"<<endl;
      cin>>v[i].Materia;
      cout<<"Ingrese la Nota"<<endl;
      cin>>v[i].Nota;
      len++;
   }
}

void finalesAprobados (Alumno v[], int len){
   int cont=0;
   for(int i=0; i<len; i++) {
      if (v[i].Nota >= 6) {
        cont++;
      }
   }
   cout<<"El alumno aprobó:  "<< cont<<"  finales"<<endl;

}

void promedio (Alumno v[], int len){
   int sum =0;

   for(int i=0; i<len; i++) {
      sum= sum + v[i].Nota;
   }

   cout<<"El promedio de notas es: "<< sum/len <<endl;
}
