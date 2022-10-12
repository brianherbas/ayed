//ejercicio 4 tp2 (ALyED)
/*
Se tienen 2 archivos ordenados, de la materia prima necesaria para una cadena de comidas rápidas, FoodFast. El archivo 1, BurgerFast.dat, contiene las opciones de panes en almacén con la siguiente estructura:

- Código de producto (ordenado por este campo)

- Cantidad de unidades

- Vencimiento MMAAAA

El archivo 2, OtrosFast.dat, contiene el resto de los productos utilizados, con la misma estructura:

- Código de producto (ordenado por este campo)

- Cantidad de unidades

- Vencimiento MMAAAA

Se pide:
- Generar un archivo unificado que contenga todos los productos ordenados por el código.
- Mostrar por pantalla los que se vencen el 122021.
*/


#include <iostream>
#include <stdio.h>
using namespace std;

struct materiaPrima{
   int codProd;
   int cantUnid;
   int vencimiento;
};

int main() {
   FILE * PANES;
   FILE * OTROSPROD;
   FILE * TODOSLOSPRODUCTOS;

   PANES = fopen ("BurgerFast.dat","rb");
   OTROSPROD = fopen ("OtrosFast.dat","rb");
   TODOSLOSPRODUCTOS = fopen ("productos.dat","wb");

   materiaPrima ra;
   materiaPrima rb;

   fread (&ra,sizeof(struct materiaPrima),1,PANES);
   fread (&rb,sizeof(struct materiaPrima),1,OTROSPROD);

	while (!feof(PANES)&&!feof(OTROSPROD)){
	   if (ra.codProd < rb.codProd){
         if(ra.vencimiento == 122021){
            cout<<"El producto con codigo = " << ra.codProd << " vence el: " << ra.vencimiento <<endl;
         }
         if(rb.vencimiento == 122021) {
            cout<<"El producto con codigo = " << rb.codProd << " vence el: " << rb.vencimiento <<endl;
         }
	      fwrite(&ra,sizeof(struct materiaPrima), 1,TODOSLOSPRODUCTOS);
	      fread (&ra,sizeof(struct materiaPrima),1,PANES);
	   }else {
         fwrite(&rb,sizeof(struct materiaPrima), 1,TODOSLOSPRODUCTOS);
         fread (&rb,sizeof(struct materiaPrima),1,OTROSPROD);
	   }
	}

	while(!feof(PANES)){
      fwrite(&ra,sizeof(struct materiaPrima), 1,TODOSLOSPRODUCTOS);
      fread (&ra,sizeof(struct materiaPrima),1,PANES);
	}

	while(!feof(OTROSPROD)){
      fwrite(&rb,sizeof(struct materiaPrima), 1,TODOSLOSPRODUCTOS);
      fread (&rb,sizeof(struct materiaPrima),1,OTROSPROD);
	}

	fclose(PANES);
	fclose(OTROSPROD);
	fclose(TODOSLOSPRODUCTOS);

	return 0;
}
