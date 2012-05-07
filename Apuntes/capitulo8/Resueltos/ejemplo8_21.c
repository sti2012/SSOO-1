//ejemplo8_21.c
#include <stdio.h>
#include <stdlib.h>
#define DIM 3

int main(){
    FILE *fhOut, *fhIn;
    float matriz[DIM][DIM];
    int i,j;

    // Petición de la matriz
    for (i=0; i<DIM; i++)
        for (j=0; j<DIM; j++){
            printf("Introduzca el elemento (%d,%d): ",i,j);
            scanf(" %f",&matriz[i][j]);
        }

    // Escritura de la matriz en un fichero binario
    fhOut=fopen("ficherotextual.txt","w");
    if (fhOut==NULL){
        printf("No puedo abrir el archivo para escritura\n");
        return 1;
    }
    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            fprintf(fhOut,"%f\t",matriz[i][j]);
        }
        fprintf(fhOut,"\n");
    }
    fclose(fhOut);

    // Lectura de la matriz del fichero binario
    fhIn=fopen("ficherotextual.txt","r");
    if (fhIn==NULL)
        printf("No puedo abrir el archivo para lectura\n");
        return 1;
    }
    for (i=0; i<DIM; i++)
        for (j=0; j<DIM; j++){
            float x;
            fscanf(fhIn," %f",&x);
            printf("Elemento (%d,%d)=%f\n",i,j,x);
        }
    fclose(fhIn);
    system("PAUSE") ;
    return 0 ;
}
