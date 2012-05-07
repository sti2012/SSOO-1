//ejemplo5_24.c
#include <stdio.h>
#include <stdlib.h>
#include "basicoarrays.h"

void insercionDirecta(int *array, unsigned int tamano);

int main(){
    int *array;
    unsigned int tamano;

    printf("Introduzca el tamaño del array a ordenar: ");
    scanf("%u", &tamano);
    array = creaArray(tamano);
    printf("El array sin ordenar es:\n");
    imprimeArray(array, tamano);
    insercionDirecta(array, tamano);
    printf("El array ordenado es:\n");
    imprimeArray(array, tamano);
    destruyeArray(array);
    system("PAUSE");
    return 0;
}

void insercionDirecta(int *array, unsigned int tamano){
    int auxiliar;
    int i, j;
    i=0;
    while (i<tamano-1){
        i++;
        auxiliar=array[i];
        j=i-1;
        while (array[j]>auxiliar && j>0){
            array[j+1]=array[j];
            j--;
        }
        if (array[j]>auxiliar){
            array[j+1]=array[j];
            array[j]=auxiliar;
        }
        else{
            array[j+1]=auxiliar;
        }
    }
}
