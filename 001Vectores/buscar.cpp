/******************************************************************************
 *Vectores: procedimiento "buscar" (en una posición específica en un vector cargado)
*******************************************************************************/

#include <iostream>

using namespace std;

void inicializar (int vec [], int cantPos, int valorIni);
int buscar (int vec[], int len, int valor);
void mostrar (int vec1[], int len1);
int main()
{
    int vector1[5];
    int len = 0;
    int aux, num;
    
    inicializar (vector1, 5, 0);
    //Se carga el vector manualmente con el fin de probar el procedimiento "buscar" :
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
    
    // Ahora se procede a buscar el valor de una posición específica
    cout <<"ingrese el valor que desea buscar en el vector"<<endl;
    cin >> num;
    aux = buscar(vector1, len, num);
    if(aux != -1){
        cout << "Se encontró el valor que está buscando en la posición:  " << aux << endl;
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
int buscar (int vec[], int len, int valor){
   int i=0;

   while (i<len && vec[i]!=valor){
      i++;
   }

   if (i==len){
      return -1;
   } else return i;
}
void mostrar (int vec1[], int len1){
   for  (int i=0; i<len1 ;i++){
      cout<<vec1[i]<<endl;
   }
}

