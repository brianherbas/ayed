/******************************************************************************
 *Vectores: procedimiento "cargaMasivaOrdenado"
 *Para usar este procedimiento es necesario el uso del procedimiento "insertar" e "insertarOrdenado"
*******************************************************************************/

#include <iostream>

using namespace std;

void inicializar (int vec [], int cantPos, int valorIni);
void insertar (int vec[], int &len, int valor, int pos);
void insertarOrdenado (int vec[], int &len, int valor);
void cargaMasivaOrdenado (int vec2[],int &len2, int cantPos1);
void mostrar (int vec1[], int len1);
int main()
{
    int vector1[5];
    int len = 0;
    
    inicializar (vector1, 5, 0);
    mostrar(vector1,5);

    //Se carga el vector masivamente(ordenado) por el usuario
    cargaMasivaOrdenado(vector1, len, 5);
    cout<<"--------vector cargado y ordenado:---------"<<endl;
    mostrar(vector1,len);
    cout << "len = " << len <<endl;
    cout<<"-----------------"<<endl;
    
    
    //cout<<"Hello World";

    return 0;
}

void inicializar (int vec [], int cantPos, int valorIni){
   for (int i=0; i<cantPos; i++){
      vec [i]=valorIni;
   }
}
void insertar (int vec[], int &len, int valor, int pos) {
    for (int i=len; i>pos; i--) {
        vec[i] = vec[i-1];
    }
    vec[pos] = valor;
    len++;
}
void insertarOrdenado (int vec[], int &len, int valor){

   int i=0;
   //determinar la pos en la que tengo que insertar
   while (i<len && vec[i]<=valor){
      i++;
   }
   //insertar en la posición
   if (i==len){
      vec[len]=valor;
      len++;
   }else insertar (vec,len,valor,i);

}
void cargaMasivaOrdenado (int vec2[],int &len2, int cantPos1){
   int aux;
      for (int i=0; i<cantPos1; i++){
         cout<< "ingrese un valor al vector"<<endl;
         cin>>aux;
         insertarOrdenado(vec2,len2,aux);
      }
}
void mostrar (int vec1[], int len1){
   for  (int i=0; i<len1 ;i++){
      cout<<vec1[i]<<endl;
   }
}

