/*
*ejemplox_113.c
*/

#include <stdio.h>
#include <stdlib.h>

int leerMatriz(char *nombreFichero, int nFilas, int nColumnas,
   float *matriz) {
   int i,j;
   FILE* fh_in;
   fh_in=fopen(nombreFichero,"r");
   if (fh_in==NULL) {
       printf("No puedo abrir el archivo %s\n",nombreFichero);
       return 1;
   }

   for (i=0; i<nFilas; ++i)
      for (j=0; j<nColumnas; ++j) {
         int nLeidos=fscanf(fh_in," %f",&(matriz[i*nColumnas+j]));
         if (nLeidos!=1) {
            printf("No se pudo leer el elemento (%d,%d)\n",i,j);
            return 2;
         }
      }

   fclose(fh_in);
   return 0;   
}    

void imprimirMatriz(int nFilas, int nColumnas, float *matriz) {
   int i,j;
   for (i=0; i<nFilas; ++i) {
      for (j=0; j<nColumnas; ++j) {
         printf("%f\t",matriz[i*nColumnas+j]);
      }
      printf("\n");
   }
}    

int main() {
    int nFilas,nColumnas;
    char nombreFichero[100];
    float *matriz=NULL;
    int retval;

    printf("Introduzca el número de filas de la matriz a leer: ");
    scanf(" %d",&nFilas);
    printf("Introduzca el número de columnas de la matriz a leer: ");
    scanf(" %d",&nColumnas);
    printf("Introduzca el nombre del fichero: ");
    scanf(" %s",nombreFichero);
    
    matriz=(float *) malloc(nFilas*nColumnas*sizeof(float));
    if (matriz==NULL) {
       printf("No se pudo reservar memoria para la matriz\n");
       system("PAUSE");
       return 3;
    }
    
    if (retval=leerMatriz(nombreFichero,nFilas,nColumnas,matriz)) {
       printf("Hubo un error al leer el fichero\n");
       system("PAUSE");
       return retval;
    }
    
    imprimirMatriz(nFilas,nColumnas,matriz);
    
    system("PAUSE") ;
    return 0 ;
}
