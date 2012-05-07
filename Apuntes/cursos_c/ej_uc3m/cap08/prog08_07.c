/*
 * Programa:    prog_08_07
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 8:
 *              Programa que multiplica matrices cuadradas utilizando 
 *              arrays bidimensionales creados dinámicamente
 */
#include <stdio.h>
#include <stdlib.h>

float **crearMatriz(int filas, int columnas)
{
    float  **m;
    int j;

    m = (float **) malloc(filas * sizeof(float *));
    for (j = 0; j < filas; j++)
        m[j] = (float *)malloc(columnas * sizeof(float));

    return (m);
}

void destruirMatriz(float **m, int filas, int columnas)
{
    int j;

    for (j = 0; j < filas; j++)
        free(m[j]);

    free(m);
    return;

}

void leerMatriz(float **m, int filas, int columnas)
{
    int i, j;
    float dato;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("Elemento [%d,%d]: ", i,j);
            scanf("%f", &dato);
            m[i][j]=dato;
        }
        printf("\n");
    }
}


void imprimirMatriz(float **m, int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("[ %e ] \t", m[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatriz(float **A, float **B, 
		       float **C, int dimension)
{
   int i, j, k;

   for(i = 0; i < dimension; i++) {
      for(j = 0; j < dimension; j++) {
         C[i][j] = 0.0;
         for(k = 0; k < 2; k++) {
             C[i][j] += A[i][k] * A[k][j];
         }
      }
   }
}



int main(void)
{
    float **A, **B, **C;
    int dimension;

    /*
     * Leer la dimensión de la matriz 
     */
    printf("Número de filas: ");
    scanf("%d", &dimension);

    /* 
     * Crear las tres matrices
     */
    A = crearMatriz(dimension, dimension);
    B = crearMatriz(dimension, dimension);
    C = crearMatriz(dimension, dimension);

    leerMatriz(A,dimension, dimension);
    leerMatriz(B,dimension, dimension);
    
    multiplicarMatriz(A, B, C, dimension);

    imprimirMatriz(C, dimension, dimension);

    destruirMatriz(A, dimension, dimension);
    destruirMatriz(B, dimension, dimension);
    destruirMatriz(C, dimension, dimension);

    return (0);
}



