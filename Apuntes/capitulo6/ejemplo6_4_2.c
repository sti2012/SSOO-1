//ejemplo6_4_2.c
#include <stdio.h>
#include <stdlib.h>

int main (){
    float *arrayDinamico;
    int tam, i;
    float suma=0;

    printf(" Tamaño del array:");
    scanf("%d", &tam);
    arrayDinamico = (float *)malloc(tam*sizeof(float));
    if (arrayDinamico == NULL ){
        printf(" No hay memoria\n");
        exit(-1);
    }
    for ( i = 0; i < tam; i++ ){
        printf ("Introduzca el dato %d: ", i);
        scanf("%f", &arrayDinamico[i]);
    }

    for ( i = 0; i < tam; i++ ){
        suma = suma + arrayDinamico[i];
    }
    printf ("La media es %f", suma/i);
    free(arrayDinamico);
    system("pause");
}
