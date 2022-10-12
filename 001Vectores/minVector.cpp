/******************************************************************************
 *Vectores: función "minVector"
*******************************************************************************/

#include <iostream>

using namespace std;

void inicializar (int vec [], int cantPos, int valorIni);
void cargaMasiva (int vec2[],int &len2, int cantPos1);
int minVector (int vec[], int len);
void mostrar (int vec1[], int len1);
int main()
{
    int vector1[5];
    int len = 0;
    int aux = 0;
    
    inicializar (vector1, 5, 0);
    mostrar(vector1,5);

    //Se carga el vector masivamente por el usuario
    cargaMasiva(vector1, len, 5);
    cout<<"--------vector cargado:---------"<<endl;
    mostrar(vector1,len);
    cout << "len = " << len <<endl;
    cout<<"-----------------"<<endl;
    aux = minVector(vector1, len);
    cout << "El valor mínimo del vector es: " << vector1[aux] << " que se encuentra en la posición: " << aux << endl;
    
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
int minVector (int vec[], int len){
   int rdo=0; //la posición 0 la tomo como la pósición en la que se encuentra el min

   for (int i=1; i<len;i++){ //arranco i en 1 porque la posición 0 del vector la asigne como min
      if (vec[i]<vec[rdo]){
         rdo=i;
      }
   }

   return rdo;
}
void mostrar (int vec1[], int len1){
   for  (int i=0; i<len1 ;i++){
      cout<<vec1[i]<<endl;
   }

}

