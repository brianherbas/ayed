/******************************************************************************
 *Vectores: procedimiento "eliminar" (en una posición específica en un vector cargado)
*******************************************************************************/

#include <iostream>

using namespace std;

void inicializar (int vec [], int cantPos, int valorIni);
void eliminar (int vec[], int &len, int pos);
void mostrar (int vec1[], int len1);
int main()
{
    int vector1[5];
    int len = 0;
    
    inicializar (vector1, 5, 0);
    //Se carga el vector manualmente con el fin de probar el procedimiento "eliminar" :
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
    // Ahora se procede a eliminar el valor de una posición específica
    eliminar(vector1,len,2);
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
void eliminar (int vec[], int &len, int pos){
	for (int i = pos; i<len-1; i++){
		vec[i] = vec[i+1];
	}
	len--;
}
void mostrar (int vec1[], int len1){
   for  (int i=0; i<len1 ;i++){
      cout<<vec1[i]<<endl;
   }
}

