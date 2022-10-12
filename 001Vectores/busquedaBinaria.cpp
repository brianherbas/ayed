/******************************************************************************
 *Vectores: función "buscar"
*******************************************************************************/

#include <iostream>

using namespace std;

void inicializar (int vec [], int cantPos, int valorIni);
void cargaMasiva (int vec2[],int &len2, int cantPos1);
int busquedaBinaria (int vec[], int len, int valor);
void mostrar (int vec1[], int len1);
int main()
{
    int vector1[5];
    int len = 0;
    int aux = 0;
    int num;
    
    inicializar (vector1, 5, 0);
    mostrar(vector1,5);

    //Se carga el vector masivamente por el usuario
    cargaMasiva(vector1, len, 5);
    cout<<"--------vector cargado:---------"<<endl;
    mostrar(vector1,len);
    cout << "len = " << len <<endl;
    cout<<"-----------------"<<endl;

    cout <<"ingrese el valor que desea buscar en el vector"<<endl;
    cin >> num;
    aux = busquedaBinaria(vector1,len,num);

    if (aux != -1) {
        cout << "Se encontró el valor que está buscando en la posición: " << aux << endl;
    } else {
        cout << "No se encontró el valor que está buscando" << endl;
    }
    
    //cout<<"Hello World";

    return 0;
}

void inicializar (int vec [], int cantPos, int valorIni){
   for (int i=0; i<cantPos; i++){
      vec [i]=valorIni;
   }
}
void cargaMasiva (int vec2[],int &len2, int cantPos1){
   int aux;
   for (int i=0; i<cantPos1; i++){
      cout << "ingrese un valor al vector" << endl;
      cin >> aux;
      vec2[i] = aux;
      // se podría simplificar leyendo en la variable: cin>> vec2[i];
      len2++; //ESTO NO PUEDE FALTAR!!!!
   }
}
int busquedaBinaria (int vec[], int len, int valor){
    int pos = -1; // Variable que se retorna seteada en "-1" por si no se encuentra la posición del valor buscado
    int pri = 0;
    int ult = len - 1;
    int med;
        while (pri <= ult && pos == -1) {
            med = (pri + ult)/2;
            if (vec[med] == valor) {
                pos = med;
            } else if (valor > vec[med]) {
                pri = med +1;
            } else {
                ult = med -1;
            }
        }
    return pos;
}
void mostrar (int vec1[], int len1){
   for  (int i=0; i<len1 ;i++){
      cout<<vec1[i]<<endl;
   }

}