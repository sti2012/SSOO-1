//ejemplo6_16.c
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

void imprimeMedia(int total, int suma, const char *quemedia){
    if (total > 0){
        printf("Media de los valores %ss: %f.\n", quemedia, 1.0*suma/total);
    }
    else{
        printf("No hay ningún valor %s en la tabla.\n", quemedia);
    }

}

void calculaMedias(int tabla[TAM][TAM], int maxfilas, int maxcolumnas){
    int totalpos=0, totalneg=0, sumapos=0, sumaneg=0;
    int elemento;
    int i, j;

    for (i=0; i<maxfilas; i++){
        for (j=0; j<maxcolumnas; j++){
            elemento = tabla[i][j];
            if (elemento > 0){
                totalpos++;
                sumapos += elemento;
            }
            else if (elemento < 0){
                totalneg++;
                sumaneg += elemento;
            }
        }
    }
    imprimeMedia(totalpos, sumapos, "positivo");
    imprimeMedia(totalneg, sumaneg, "negativo");
}

int main(){
    int tabla[TAM][TAM];
    float suma, media, varianza, desvtipica;
    int num, posminimo;

    leeArray(tabla, TAM, TAM);
    calculaMedias(tabla, TAM, TAM);
    system("PAUSE");
    return 0;
}
