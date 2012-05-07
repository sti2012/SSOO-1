/*
*ejemplo5_25.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "basicoarrays.h"

void burbuja(int *array, unsigned int tamano);

int main()
{
    int *array;
    unsigned int tamano;

    printf("Introduzca el tamaño del array a ordenar: ");
    scanf("%u", &tamano);

    array = creaArray(tamano);
    printf("El array sin ordenar es:\n");
    imprimeArray(array, tamano);

    burbuja(array, tamano);
    printf("El array ordenado es:\n");
    imprimeArray(array, tamano);

    destruyeArray(array);

    system("PAUSE");
    return 0;
}

void burbuja(int *array, unsigned int tamano)
{
    int control = 1;
    int auxiliar,j;

    for (auxiliar = 0; auxiliar < tamano-1 && control; auxiliar++)
    {
        control = 0;

        for (j = 0; j < tamano-auxiliar-1; j++)
        {
            if (array[j] > array[j+1])
            {
                int aux;
                control = 1;
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            };
        }
    }
}
