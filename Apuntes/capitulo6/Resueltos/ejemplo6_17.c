//ejemplo6_17.c
#include <stdio.h>
#include <stdlib.h>
#define TAM    3

void leeArray(int tabla[][TAM], int maxfilas, int maxcolumnas){
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

void imprimeArray(int tabla[][TAM], int maxfilas, int maxcolumnas){
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

void sumaMatrices(int res[][TAM], int ma[][TAM], int mb[][TAM], int maxfilas, int maxcolumnas){
    int i, j;

    for (i=0; i<maxfilas; i++){
        for (j=0; j<maxcolumnas; j++){
            res[i][j] = ma[i][j] + mb[i][j];
        }
    }
}

int main(){
    int m1[TAM][TAM], m2[TAM][TAM], res[TAM][TAM];
    float suma, media, varianza, desvtipica;
    int num, posminimo;

    leeArray(m1, TAM, TAM);
    leeArray(m2, TAM, TAM);
    sumaMatrices(res, m1, m2, TAM, TAM);
    printf("m1:\n");
    imprimeArray(m1, TAM, TAM);
    printf("m2:\n");
    imprimeArray(m2, TAM, TAM);
    printf("m1 + m2:\n");
    imprimeArray(res, TAM, TAM);
    system("PAUSE");
    return 0;
}