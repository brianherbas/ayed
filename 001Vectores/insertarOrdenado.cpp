/******************************************************************************
 *Vectores: procedimiento "insertarOrdenado"
 *Para usar este procedimiento es necesario el uso del procedimiento "insertar"
*******************************************************************************/

#include <iostream>

using namespace std;

void inicializar (int vec [], int cantPos, int valorIni);
void insertar (int vec[], int &len, int valor, int pos);
void insertarOrdenado (int vec[], int &len, int valor);
void mostrar (int vec1[], int len1);
int main()
{
    int vector1[5];
    int len = 0;
    
    inicializar (vector1, 5, 0);
    //Se carga el vector manualmente con el fin de probar el procedimiento "insertarOrdenado" :
    cout<<"Vector1 manualmente cargado:"<<endl;
    vector1[0]=2;
    len++;
    vector1[1]=4;
    len++;
    vector1[2]=6;
    len++;
    vector1[3]=8;
    len++;
    mostrar(vector1,len);
    cout << "len = " << len <<endl;
    cout<<"-----------------"<<endl;
    // Ahora se procede a una carga directa de manera ordenada
    insertarOrdenado(vector1,len,7);
    mostrar(vector1,len);
    cout << "len = " << len <<endl;
    
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
void mostrar (int vec1[], int len1){
   for  (int i=0; i<len1 ;i++){
      cout<<vec1[i]<<endl;
   }
}

