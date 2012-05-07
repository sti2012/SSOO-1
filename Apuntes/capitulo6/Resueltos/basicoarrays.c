//basicoarrays.c
#include "basicoarrays.h"

void leearray(int tabla[][TAM], int maxfilas, int maxcolumnas){
    int buf;
    int i, j;

    printf("Lectura de una tabla de enteros de %dx%d.\n", maxfilas, maxcolumnas);
    printf("Introduzca los terminos según se le vayan solicitando\n");

    for (i=0; i<maxfilas; i++){
        for (j=0; j<maxcolumnas; j++){
            printf("  termino (%d,%d): ", i, j);
            scanf("%d", &buf);
            tabla[i][j] = buf;
        }
    }
}

void imprimearray(int tabla[][TAM], int maxfilas, int maxcolumnas){
    char sep;
    int i, j;

    for (i=0; i<maxfilas; i++){
        printf("[");
        sep = ' ';
        for (j=0; j<maxcolumnas; j++){
            printf("%c%d", sep, tabla[i][j]);
            sep = ',';
        }
        printf(" ]\n");
    }
}
