//ejemplo8_17.c
#include <stdio.h>
#include <stdlib.h>
#include "basicomatrices.h"

int main(){
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
    if (matriz==NULL){
        printf("No se pudo reservar memoria para la matriz\n");
        system("PAUSE");
        return 3;
    }
    if (retval=leerMatriz(nombreFichero,nFilas,nColumnas,matriz))
        printf("Hubo un error al leer el fichero\n");
        system("PAUSE");
        return retval;
    }
    imprimirMatriz(nFilas,nColumnas,matriz);
    system("PAUSE") ;
    return 0 ;
}
