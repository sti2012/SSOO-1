//ejercicio6_7.c
#include <stdio.h>
#include <stdlib.h>
#define DIMENSION 20

//tamaño real de la matriz con la que trabajamos
int dim;
void leer(int matriz[][DIMENSION]);
//para imprimir no es necesario modificar la matriz
void imprimir(const int matriz[][DIMENSION]);

int main (){
    int i,j;
    int matriz[DIMENSION][DIMENSION];
    int matrizTraspuesta[DIMENSION][DIMENSION];

    printf("Introduzca el numero de filas/columnas de la matriz\n");
    scanf("%d",&dim);
    leer(matriz);
    system("cls");
    //cálculo de la traspuesta
    for (i=0;i<dim;i++){
        for (j=0;j<dim;j++){
            matrizTraspuesta[i][j]=matriz[j][i];
        }
    }
    printf("La matriz es\n");
    imprimir(matriz);
    printf("La matriz traspuesta es\n");
    imprimir(matrizTraspuesta);
    system("pause");
}

//le de la consola a las matrices
void leer(int matriz[][DIMENSION]){
    int i,j;
    for (i=0;i<dim;i++){
        for (j=0;j<dim;j++){
            printf("Elemento [%d,%d]: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
        printf("\n");
    }
}

//muestra por consola las matrices
void imprimir(const int matriz[][DIMENSION]){
    int i,j;
    for (i=0;i<dim;i++) {
        for (j=0;j<dim;j++){
            printf("[ %d ] \t",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
