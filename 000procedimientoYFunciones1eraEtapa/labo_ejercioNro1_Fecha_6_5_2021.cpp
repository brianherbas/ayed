//============================================================================
// Name        : Lab1.cpp
//1)  Solicitar un n�mero al usuario y calcular:
// a) la quinta parte
// b) Elresto de la quinta parte
// c) La s�ptima parte de la quinta parte
//============================================================================

/*Estrategia de resoluci�n:
  1)Pedir al usuario el n�mero
  2)Leer el n�mero ingresado por el usuario
  3)Calcular y mostrar la quinta parte
  4)Calcular el resto de la quinta parte
  5)Calcular la s�ptima parte de la quinta parte
 */

#include <iostream>
using namespace std;

int quintaparte (int valor);
void restoquintaparte (int val);
void septimapartedelaquintaparte (int num);

int main() {
   int numero;
   int rdo1;

   cout<< "Ingresar un n�mero" << endl;
   cin>>numero;

   rdo1 = quintaparte (numero);
   cout << "La quinta parte es:" << rdo1 << endl;
   restoquintaparte (numero);
   septimapartedelaquintaparte(numero);

	return 0;
}

int quintaparte (int valor){
   return (valor/5);
}

void restoquintaparte (int val){
   int aux;
   aux = val % 5;
   cout << "El resto de la quinta parte es: " << aux << endl;
}

void septimapartedelaquintaparte (int num){
   int aux;
   aux = quintaparte(num);
   aux= aux / 7;
   cout << "La septima parte de la quinta es: " << aux << endl;
}
