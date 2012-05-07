//ejemplo8_18.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basicomatrices.h"

int determinarTamagnoMatriz(char *nombreFichero, nt *nFilas, int *nColumnas){
    int i,j;
    FILE* fhIn;
    char linea[1024];

    fhIn=fopen(nombreFichero,"r");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo %s\n",nombreFichero);
        return 1;
    }
    fscanf(fhIn," %[^\n]",linea);
    if (feof(fhIn)){
        *nFilas=*nColumnas=0;
        return 0;
    }
    else{
        float x;
        char *token;
        // Contar número de columnas
        *nColumnas=0;
        token=strtok(linea," \t");
        while (token!=NULL){
            if (sscanf(token,"%f",&x)==1) (*nColumnas)++;
            else{
                printf("No se puede leer un número del token %s\n",token);
                return 4;
            }
            token=strtok(NULL," \t");
        }
        // Contar el número de filas
        *nFilas=0;
        while (!feof(fhIn)){
            (*nFilas)++;
            fscanf(fhIn," %[^\n]",linea);
        }
    }
    fclose(fhIn);
    return 0;
}

int main(){
    int nFilas,nColumnas;
    char nombreFichero[100];
    float *matriz=NULL;
    int retval;

    printf("Introduzca el nombre del fichero: ");
    scanf(" %s",nombreFichero);
    if (retval=determinarTamagnoMatriz(nombreFichero,&nFilas,&nColumnas)){
        printf("Hubo un error al determinar el tamaño de la matriz\n");
        system("PAUSE");
        return retval;
    }
    matriz=(float *) malloc(nFilas*nColumnas*sizeof(float));
    if (matriz==NULL){
        printf("No se pudo reservar memoria para la matriz\n");
        system("PAUSE");
        return 3;
    }
    if (retval=leerMatriz(nombreFichero,nFilas,nColumnas,matriz)){
        printf("Hubo un error al leer el fichero\n");
        system("PAUSE");
        return retval;
    }
    imprimirMatriz(nFilas,nColumnas,matriz);
    system("PAUSE") ;
    return 0 ;
}
