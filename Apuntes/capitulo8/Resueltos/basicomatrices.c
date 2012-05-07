//basicomatrices.c
#include "basicmatrices.h"

int leerMatriz(char *nombreFichero, int nFilas, int nColumnas, float *matriz){
    int i,j;
    FILE* fhIn;
    fhIn=fopen(nombreFichero,"r");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo %s\n",nombreFichero);
        return 1;
    }

    for (i=0; i<nFilas; ++i)
        for (j=0; j<nColumnas; ++j){
            int nLeidos=fscanf(fhIn," %f",&(matriz[i*nColumnas+j]));
            if (nLeidos!=1){
                printf("No se pudo leer el elemento (%d,%d)\n",i,j);
                return 2;
            }
        }
    fclose(fhIn);
    return 0;
}

void imprimirMatriz(int nFilas, int nColumnas, float *matriz){
    int i,j;
    for (i=0; i<nFilas; ++i){
        for (j=0; j<nColumnas; ++j){
            printf("%f\t",matriz[i*nColumnas+j]);
        }
        printf("\n");
    }
}
