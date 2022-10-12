/*****************************************
Se tiene un archivo de registros de tamaño fijo de alumnos con nombre ALU_G.DAT. El formato
del registro de este archivo es el siguiente:
NRO_LEG: Número de legajo del alumno / Numérico de hasta 7 posiciones.
APE_NOM: Apellido y nombre del alumno / Cadena de caracteres de hasta 50 posiciones.
ESP: Especialidad / Un caracter 'K' o 'I' (Sistemas o Industrial)
C1P: Calificación del primer parcial / Numérico entre 0 y 10 (0 significa ausente).
C2P: Calificación del segundo parcial / Numérico entre 0 y 10 (0 significa ausente).

Los registros en el archivo no tienen ningún orden específico y se sabe que no contiene más de 50.

Se pide:
Realizar un programa que lea ese archivo y genere dos con igual formato: Uno de nombre
ALU_K.DAT que contenga los alumnos de Sistemas (K) y otro ALU_I.DAT que contenga los
alumnos de Industrial (I). Además, los archivos que se generan deben estar ordenados número
de legajo.
El formato del registro de estos archivos es el siguiente:
NRO_LEG: Número de legajo del alumno / Numérico de hasta 7 posiciones.
APE_NOM: Apellido y nombre del alumno / Cadena de caracteres de hasta 50 posiciones.
C1P: Calificación del primer parcial / Numérico entre 0 y 10 (0 significa ausente).
C2P: Calificación del segundo parcial / Numérico entre 0 y 10 (0 significa ausente).
*****************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno{
   int Leg;
   char NyA;
   char esp;
   int C1P;
   int C2P;
};

struct Especial {
   int Leg;
   char NyA;
   int C1P;
   int C2P;
};

void inicializar (Especial vec [], int cantPos, Especial valorIni);
void insertar (Especial vec[], int &len, Especial valor, int pos);
void insertarOrdenado (Especial vec[], int &len, Especial valor);

int main() {
	Especial vecK [50];
	int lenK=0;
	Especial vecI [50];
	int lenI=0;

	Especial valorIni;

	valorIni.Leg = 0;
	valorIni.NyA ='N';
	valorIni.C1P = 0;
	valorIni.C2P = 0;

	inicializar (vecK,50,valorIni);
    inicializar (vecI,50,valorIni);
   //En este punto tengo los vectores para usar en el ejercicio

   FILE * ALUG;
   ALUG = fopen ("ALU_G.dat","rb");

   Alumno raux;
   Especial rcarga;

   fread(&raux,sizeof (struct Alumno),1,ALUG);

   while(!feof(ALUG)){

      if(raux.esp=='K'){
         rcarga.Leg=raux.Leg;
         rcarga.NyA=raux.NyA;
         rcarga.C1P=raux.C1P;
         rcarga.C2P=raux.C2P;

         insertarOrdenado(vecK,lenK,rcarga);
      }else {
         if(raux.esp=='I'){
            rcarga.Leg=raux.Leg;
            rcarga.NyA=raux.NyA;
            rcarga.C1P=raux.C1P;
            rcarga.C2P=raux.C2P;

            insertarOrdenado(vecI,lenI,rcarga);
         }
      }

      fread(&raux,sizeof (struct Alumno),1,ALUG);
   }

   fclose(ALUG);

   FILE * K;

   K = fopen("ALU_K.dat","wb");

   for(int i=0;i<lenK;i++){
      fwrite(&vecK[i],sizeof(struct Especial),1,K);
   }
   fclose(K);

   FILE * I;

   I = fopen("ALU_I.dat","wb");

   for(int i=0; i<lenI; i++){
      fwrite(&vecI[i],sizeof(struct Especial),1,I);
   }
   fclose(I);

	return 0;
}

void inicializar (Especial vec [], int cantPos, Especial valorIni){

   for (int i=0; i<cantPos; i++){
      vec [i].Leg = valorIni.Leg;
      vec [i].NyA = valorIni.NyA;
      vec [i].C1P = valorIni.C1P;
      vec [i].C2P = valorIni.C2P;
   }
}

void insertar (Especial vec[], int &len, Especial valor, int pos){
   for(int i=len; i>pos; i--){
      vec[i]=vec[i-1];
   }
   vec[pos].Leg=valor.Leg;
   vec[pos].NyA=valor.NyA;
   vec[pos].C1P=valor.C1P;
   vec[pos].C2P=valor.C2P; //insertando un nuevo valor al vector
   len++; //cada vez que inserto un elemento al vector incremento el len
}

void insertarOrdenado (Especial vec[], int &len, Especial valor){

   int i=0;
   //determinar la pos en la que tengo que insertar
   while (i<len && vec[i].Leg<=valor.Leg){
      i++;
   }
   //insertar en la posición
   if (i==len){
      vec[len].Leg=valor.Leg;
      vec[len].NyA=valor.NyA;
      vec[len].C1P=valor.C1P;
      vec[len].C2P=valor.C2P;;
      len++;
   }else insertar (vec,len,valor,i);

}
