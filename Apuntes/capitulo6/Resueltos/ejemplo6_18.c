//ejemplo6_18.c
#include <stdio.h>
#include <stdlib.h>
#define TAM    5

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

void imprimeArray(int tabla[][TAM], int maxfilas, int maxcolumnas)
{
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

int leeNumero(const char *mensaje, int minimo, int maximo){
    int num;

    do{
        printf("  %s (rango %d - %d): ", mensaje, minimo, maximo);
        scanf("%d", &num);
    }
    while (num < minimo || num > maximo);
    return num;
}

void permutaArray(int tabla[][TAM], int maxcolumnas, int filai, int filaj){
    int tmp, j;

    if (filai == filaj){
        return;
    }

    for (j=0; j<maxcolumnas; j++){
        tmp = tabla[filai][j];
        tabla[filai][j] = tabla[filaj][j];
        tabla[filaj][j] = tmp;
    }
}

int main(){
    int tabla[TAM][TAM];
    int filai, filaj;

    leeArray(tabla, TAM, TAM);
    filai = leeNumero("Introduzca la fila a permutar", 0,4);
    filaj = leeNumero("Introduzca la fila permutada", 0,4);
    printf("antes:\n");
    imprimeArray(tabla, TAM, TAM);
    permutaArray(tabla, TAM, filai, filaj);
    printf("despues:\n");
    imprimeArray(tabla, TAM, TAM);
    system("PAUSE");
    return 0;
}
