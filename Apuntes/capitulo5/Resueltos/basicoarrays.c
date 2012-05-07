//basicoarrays.c
#include "basicoarrays.h"

int *creaArray(unsigned int tamano){
    int i, valor;
    int *array;

    if (tamano <= 0){
        printf("Introduzca el tamaño del array a ordenar: ");
        scanf("%u", &tamano);
    }
    array = (int *)malloc(tamano * sizeof(int));
    if (array == NULL){
        printf("Error en la asignación de memoria!\n");
        exit(0);
    }
    printf("Introduzca %d valores para llenar el array:\n", tamano);
    for (i=0; i<tamano; i++){
        printf("  valor % 3d: ", i);
        scanf("%d", &valor);
        array[i]= valor;
    }
    return array;
}

void destruyeArray(int *array){
    free(array);
}

void imprimeArray(int *array, unsigned int tamano){
    int i;
    char sep='[';
    for (i=0; i<tamano; i++){
        printf("%c%d", sep, array[i]);
        sep = ',';
    }
    printf("]\n");
}

