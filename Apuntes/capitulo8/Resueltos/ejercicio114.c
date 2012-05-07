/*
*ejemplox_114.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int determinarTamagnoMatriz(char *nombreFichero,
   int *nFilas, int *nColumnas) {
   int i,j;
   FILE* fh_in;
   char linea[1024];

   fh_in=fopen(nombreFichero,"r");
   if (fh_in==NULL) {
       printf("No puedo abrir el archivo %s\n",nombreFichero);
       return 1;
   }

   fscanf(fh_in," %[^\n]",linea);
   if (feof(fh_in)) {
      *nFilas=*nColumnas=0;
      return 0;
   } else {
      float x;
      char *token;
      // Contar número de columnas
      *nColumnas=0;
      token=strtok(linea," \t");
      while (token!=NULL) {
         if (sscanf(token,"%f",&x)==1) (*nColumnas)++;
         else {
            printf("No se puede leer un número del token %s\n",token);
            return 4;
         }
         token=strtok(NULL," \t");
      }
      
      // Contar el número de filas
      *nFilas=0;
      while (!feof(fh_in)) {
         (*nFilas)++;
         fscanf(fh_in," %[^\n]",linea);
      }
   }

   fclose(fh_in);
   return 0;   
}

int main() {
    int nFilas,nColumnas;
    char nombreFichero[100];
    float *matriz=NULL;
    int retval;

    printf("Introduzca el nombre del fichero: ");
    scanf(" %s",nombreFichero);
    
    if (retval=determinarTamagnoMatriz(nombreFichero,&nFilas,&nColumnas)) {
       printf("Hubo un error al determinar el tamaño de la matriz\n");
       system("PAUSE");
       return retval;
    }
    
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
