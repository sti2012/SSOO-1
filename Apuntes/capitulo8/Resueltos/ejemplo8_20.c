//ejemplo8_20.c
#include <stdio.h>
#include <stdlib.h>
#define DIM 3

int main(){
    FILE *fhOut, *fhIn;
    float matriz[DIM][DIM];
    int i,j;

    for (i=0; i<DIM; i++)  // Petición de la matriz
        for (j=0; j<DIM; j++)
        {
            printf("Introduzca el elemento (%d,%d): ",i,j);
            scanf(" %f",&matriz[i][j]);
        }

    // Escritura de la matriz en un fichero binario
    fhOut=fopen("ficherobinario.dat","wb");
    if (fhOut==NULL){
        printf("No puedo abrir el archivo para escritura\n");
        return 1;
    }
    for (i=0; i<DIM; i++)
        for (j=0; j<DIM; j++)
            fwrite(&matriz[i][j],sizeof(float),1,fhOut);
    fclose(fhOut);

    // Lectura de la matriz del fichero binario
    fhIn=fopen("ficherobinario.dat","rb");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo para lectura\n");
        return 1;
    }
    for (i=0; i<DIM; i++)
        for (j=0; j<DIM; j++){
            float x;
            fread(&x,sizeof(float),1,fhIn);
            printf("Elemento (%d,%d)=%f\n",i,j,x);
        }
    fclose(fhIn);
    system("PAUSE") ;
    return 0 ;
}
