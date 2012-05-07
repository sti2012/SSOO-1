//ejercicio6_5:
#include<stdio.h>
#include<stdlib.h>

float** reservarMemoria(int fil, int col);
void leerMatriz(float** matrizDinamica, int fil, int col);
void imprimirMatriz(float** matrizDinamica, int fil, int col);
float** multiplicarMatriz(float** matrizA, float** matrizB,
                          int filA, int colA, int colB);
void liberarMemoria(float** matrizDinamica, int fil, int col);

int main (){
    float** matrizA;
    float** matrizB;
    float** matrizC;
    int filasA,columnasA,filasB,columnasB;

    printf("Número de filas de la matriz A: ");
    scanf("%d", &filasA);
    printf("Número de columnas de la matriz A: ");
    scanf("%d", &columnasA);
    printf("Número de filas de la matriz B: ");
    scanf("%d", &filasB);
    printf("Número de columnas de la matriz B: ");
    scanf("%d", &columnasB);
    // Si no se cumple esta condición las matrices no se pueden multiplicar
    if (columnasA!=filasB){
        printf("ERROR, no se pueden multiplicar estas matrices\n");
    }
    else{

        matrizA = reservarMemoria(filasA, columnasB);
        matrizB = reservarMemoria(filasB, columnasB);
        system ("cls");
        printf("Introduzca los datos de la matriz A:\n");
        leerMatriz(matrizA,filasA, columnasA);
        system ("cls");
        printf("Introduzca los datos de la matriz B:\n");
        leerMatriz(matrizB,filasB, columnasB);
        system ("cls");

        matrizC = multiplicarMatriz(matrizA, matrizB, filasA, columnasA,
                                    columnasB);
        printf("La matriz matrizA es:\n");
        imprimirMatriz(matrizA, filasA, columnasA);
        printf("\n");
        printf("La matriz B es:\n");
        imprimirMatriz(matrizB, filasB, columnasB);
        printf("\n");
        printf("El resultado de A*B es:\n");
        imprimirMatriz(matrizC, filasA, columnasB);
        liberarMemoria(matrizA, filasA, columnasA);
        liberarMemoria(matrizB, filasB, columnasB);
        liberarMemoria(matrizC, filasA, columnasB);
    }
    system("pause");
}

//Reserva dinámicamente una matriz con las filas y columnas que se soliciten
float** reservarMemoria(int fil, int col){
    float** matrizDinamica;
    int j;
    //reservamos espacio para los punteros, uno por fila
    matrizDinamica = (float**) malloc(fil * sizeof(float*));
    //reservamos espacio para los datos
    //para cada fila hay que reservar tantos datos como columnas
    for (j = 0; j < fil; j++){
        matrizDinamica[j] = (float*)malloc(col * sizeof(float));
    }
    return (matrizDinamica);
}

//Lee los elementos de una matriz de la consola.
void leerMatriz(float** matrizDinamica, int fil, int col){
    int i, j;
    float dato;
    for (i = 0; i < fil; i++){
        for (j = 0; j < col; j++){
            printf("Introduzca el elemento [%d,%d]: ", i,j);
            scanf("%f", &dato);
            matrizDinamica[i][j]=dato;
        }
        printf("\n");
    }
}

//Muestra una matriz por consola.
void imprimirMatriz(float** matrizDinamica, int fil, int col){
    int i, j;
    for (i = 0; i < fil; i++){
        for (j = 0; j < col; j++){
            printf(" [%f]  \t", matrizDinamica[i][j]);
        }
        printf("\n");
    }
}

//Multiplica las dos matrices que se la pasan como argumento
float** multiplicarMatriz(float** matrizA, float** matrizB,
                          int filA, int colA, int colB){
    int i, j, k;
    //reservamos espacio para la matriz resultado
    float** matrizC = reservarMemoria(filA, colB);
    //para cada fila de la matriz resultado
    for (i = 0; i < filA; i++){
        //para cada columna de la matriz resultado
        for (j = 0; j < colB; j++){
            //se inicializa la posición a cero
            matrizC[i][j] = 0.0F;
            //se almacena en dicha posición la suma de los productos
            //de los elementos de la fila i de la primera matriz
            //por los elementos de la columna k de la segunda
            for (k = 0; k <= colA; k++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    return matrizC;
}

//Libera memoria de una matriz reservada dinámicamente
void liberarMemoria(float** matrizDinamica, int fil, int col){
    int j;
    for (j = 0; j < fil; j++){
        free(matrizDinamica[j]);
    }
    free(matrizDinamica);
}
