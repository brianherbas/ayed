//============================================================================
// Name        : ApareoDeAyBe en archivo C.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

struct alumno{
   int legajo;
   int dni;
   int nota1;
   int nota2;
};

int main() {
   FILE * A;
   FILE * B;
   FILE * C;

   A = fopen ("a.dat","rb");
   B = fopen ("b.dat","rb");
   C = fopen ("c.dat","wb");

   alumno ra;
   alumno rb;

   fread (&ra,sizeof(struct alumno),1,A);
   fread (&rb,sizeof(struct alumno),1,B);

	while (!feof(A)&&!feof(B)){
	   if (ra.legajo < rb.legajo){
	      fwrite(&ra,sizeof(struct alumno), 1,C);
	      fread (&ra,sizeof(struct alumno),1,A);
	   }else {
         fwrite(&rb,sizeof(struct alumno), 1,C);
         fread (&rb,sizeof(struct alumno),1,B);
	   }
	}

	while(!feof(A)){
      fwrite(&ra,sizeof(struct alumno), 1,C);
      fread (&ra,sizeof(struct alumno),1,A);
	}

	while(!feof(B)){
      fwrite(&rb,sizeof(struct alumno), 1,C);
      fread (&rb,sizeof(struct alumno),1,B);
	}

	fclose(A);
	fclose(B);
	fclose(C);

	return 0;
}
