/*
*ejemplox_52.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM    100
#define TAMBUF 256


int leearray(float tabla[], int maxnum)
{
        char buf[TAMBUF];
        const char fin = 'f';
        int i;
           
        printf("Lectura de hasta %d números reales.\n", maxnum);
        printf("Introduzca los terminos o pulse '%c' para acabar la "
		"entrada de numeros\n", fin);

        for (i=0; i<maxnum; i++) {
            printf("  termino %03d: ", i);
            scanf("%s", buf);
            if (tolower(buf[0]) == 'f') {
		break;
	    }
            tabla[i] = atof(buf);
        }
        return i;
}

void imprimearray(float tabla[], int num)
{
     int i;
     
   printf("Ha introducido los siguientes %d números.\n", num);
   for (i=0; i<num; i++) {
       printf("  posición %03d: valor %f\n", i, tabla[i]);
   }
} 
    
int calculaminimo(float tabla[], int num)
{
   int pos = -1;
   int i;

   for (i=0; i<num; i++) {
	if (pos < 0 || tabla[i] < tabla[pos]) {
	    pos = i;
	}
   }
   return pos;
}

float calculasuma(float tabla[], int num)
{
   float suma = 0.0;
   int i;

   for (i=0; i<num; i++) {
	suma += tabla[i];
   }
   return suma;
}

float calculamedia(float suma, int num)
{
   float media = suma / num;

   return media;
}

float calculavarianza(float tabla[], int num, float media)
{
   float suma = 0.0;
   float varianza, termino;
   int i;

   for (i=0; i<num; i++) {
	termino = tabla[i] - media;
	suma += termino * termino;
   }
   varianza = suma / num;
   return varianza;
}

float calculadesviaciontipica(int num, float varianza)
{
   float desvtipica = sqrt(varianza);

  return desvtipica;
}

    
int main() {
   float tabla[TAM];
   float suma, media, varianza, desvtipica;
   int num, posminimo;

   num = leearray(tabla, sizeof tabla);

   imprimearray(tabla, num);

   posminimo = calculaminimo(tabla, num);
   printf("El valor mínimo introducido es la posición %d, valor %f.\n",
	posminimo, tabla[posminimo]);
   suma = calculasuma(tabla, num);
   printf("La suma de los %d elementos vale %f.\n", num, suma);
   media = calculamedia(suma, num);
   printf("La media de los %d elementos vale %f.\n", num, media);
   varianza = calculavarianza(tabla, num, media);
   printf("La varianza de los %d elementos vale %f.\n", num, varianza);
   desvtipica = calculadesviaciontipica(num, varianza);
   printf("La desviación típica de los %d elementos es %f.\n", num, desvtipica);
 
   system("PAUSE");	
   return 0;
}
