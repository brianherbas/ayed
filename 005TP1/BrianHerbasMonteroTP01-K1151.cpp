// 1-a) Desarrolle un procedimiento que dado una fecha DDMMAAAA, muestre por pantalla el año.
// 1-b) Desarrolle una función que dado un número, retorne verdadero si es par, o falso si es impar.
// 2) Dado un vector de enteros, que contiene velocidades que se detectaron en una ruta, calcular:
// a) Velocidad Máxima
// b) Velocidad Mínima
// c) Promedio de las velocidades colectadas

// Nota: El vector YA VIENE CARGADO. Se sabe que máximo hay 200 velocidades, pero podría haber menos.
//       Con esto quiere decir que tendríamos que hacer los correspondientes llamados desde el main.

// Ejercicio 3: 

// Se tiene un archivo de la materia prima necesaria para una cadena de comidas rápidas BurgerFast.dat. (sin orden)
// Código de Producto: 999999
// Cantidad de unidades en depósito: 99999
// Tipo de producto: ‘H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)
// Vencimiento: MMAAAA

// Se pide:
// Generar un archivo sólo para panes Pan.dat con la siguiente estructura:
// Código de Producto: 999999
// Cantidad de unidades en depósito: 99999
// Vencimiento: MMAAAA
// Generar un archivo UsarAntes.dat con los productos que tengan más de 1000 unidades en stock ó se venzan el 122019 o antes, con la estructura original
#include <iostream>
#include <stdio.h>
using namespace std;

// void mostrarFecha (int fecha);
// bool esParOImpar (int val);

// void velMax(int v[],int len);
// void velMin(int v[],int len);
// void promedioVelocidad(int vec[],int len);

//3)
struct Producto {
    int codProd;
    int cantUnidEnDepos;
    char tipoProd;
    int vencimiento;
};
struct Pan {
    int codProd;
    int cantUnidEnDepos;
    int vencimiento;
};
////////////////////////
int main() {
    //Punto 2
   //declaraciones para resolver mi punto 2
   int vec[200];
   int len; // si el vector no viene dado es decir no existe entonces sería "int len = 0;"

   velMax(vec,len);
   velMin(vec,len);
   promedioVelocidad(vec,len);

   //acá termina el punto 2
    
//3)
    FILE * stock;
    FILE * panes;
    FILE * antes;

    stock = fopen ("BurgerFast.dat", "rb");
    panes = fopen ("Pan.dat", "wb");
    antes = fopen ("UsarAntes.dat", "wb");

    Producto raux;
    Pan rcarga;
    int aux;

    fread(&raux, sizeof(struct Producto), 1, stock);

    while(!feof(stock)) {
        //resuelve el 3a
        if(raux.tipo =='P'){
            rcarga.codProd = raux.codProd;
            rcarga.cantU = raux.cantU;
            rcarga.venc = raux.venc;
            fwrite(&rcarga, sizeof(struct Pan), 1, panes);
        }
        //resuelve 3b
        if(raux.cantUnidEnDepos > 1000 || ((raux.vencimiento / 10000 <= 12) && (raux.vencimiento % 10000 <= 2019)) {
            fwrite(&raux,sizeof(struct Producto), 1, antes);
        }

        fread(&raux, sizeof(struct Producto), 1, stock);
    }

    fclose(stock);
    fclose(panes);
    fclose(antes);
    //------------------------------------------------------------------------------------

    return 0;
}


//1-a)
/*void mostrarFecha (int fecha) {
    int anio;
    anio = fecha % 10000;
    cout << "El año es: " << anio << endl;
}*/
//------------------------------------------------------------------------------------
//1-b)
/*bool esParOImpar (int val) {
    bool aux;
    if ((val % 2) == 0) {
        aux = true;
    } else {
        aux = false;
    }
    return aux;
}*/
//------------------------------------------------------------------------------------
//2-a
/*void velMax(int v[],int len) {
   int posMax = 0;
   for(int i=1; i<len; i++) {
      if(v[i] > v[posMax]) {
         posMax = i;
      }
   }
   cout<<"el máximo es: "<<v[posMax]<<endl;
}*/
//------------------------------------------------------------------------------------
//2-b
/*void velMin(int v[],int len) {
   int posMin = 0;
   for(int i=1; i<len; i++) {
      if(v[i] < v[posMin]) {
         posMin = i;
      }
   }
   cout<<"el minimo es: "<<v[posMin]<<endl;
}*/
//------------------------------------------------------------------------------------
//2-c
/*void promedioVelocidad (int vec[], int len){
    int suma = 0;
    float prom;
    for(int i = 0; i < len; i++) {
        suma = suma + vec[i];
    }
    prom = (float)suma/len;
    cout<< "El promedio de velocidades es: "<<prom<<endl;
}*/
//------------------------------------------------------------------------------------
