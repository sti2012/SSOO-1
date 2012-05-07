/*
*ejemplox_120.c
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 3

int main() {
   FILE *fh_out, *fh_in;
   float matriz[DIM][DIM];
   int i,j;
   
   // Petición de la matriz
   for (i=0; i<DIM; i++)
      for (j=0; j<DIM; j++) {
         printf("Introduzca el elemento (%d,%d): ",i,j);
         scanf(" %f",&matriz[i][j]);
      }
   
   // Escritura de la matriz en un fichero binario
   fh_out=fopen("ficherotextual.txt","w");
   if (fh_out==NULL) {
       printf("No puedo abrir el archivo para escritura\n");
       return 1;
   }
   for (i=0; i<DIM; i++) {
      for (j=0; j<DIM; j++) {
         fprintf(fh_out,"%f\t",matriz[i][j]);
      }
      fprintf(fh_out,"\n");
   }
   fclose(fh_out);

   // Lectura de la matriz del fichero binario
   fh_in=fopen("ficherotextual.txt","r");
   if (fh_in==NULL) {
       printf("No puedo abrir el archivo para lectura\n");
       return 1;
   }
   for (i=0; i<DIM; i++)
      for (j=0; j<DIM; j++) {
         float x;
         fscanf(fh_in," %f",&x);
         printf("Elemento (%d,%d)=%f\n",i,j,x);
      }
   fclose(fh_in);

   system("PAUSE") ;
   return 0 ;
}
