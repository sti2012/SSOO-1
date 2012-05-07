/*
 * Programa:    prog_08_06
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 8:
 *              Programa que multiplica matrices cuadradas de 10 x 10
 */
#include <stdio.h>
#define DIMENSION     2

void multiplicarMatriz(float A[DIMENSION][DIMENSION],
                       float B[DIMENSION][DIMENSION],
                       float C[DIMENSION][DIMENSION])
{
   int i, j, k;

   for(i = 0; i < 2; i++) {
      for(j = 0; j < 2; j++) {
         C[i][j] = 0.0;
         for(k = 0; k < 2; k++) {
             C[i][j] += A[i][k] * B[k][j];
         }
      }
   }
}

void imprimirMatriz (float M[DIMENSION][DIMENSION])
{
   int i, j;

   for(i = 0; i < DIMENSION; i++) {
      for(j = 0; j < DIMENSION; j++) {
          printf("%e\t  ", M[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

void leerMatriz (float M[DIMENSION][DIMENSION])
{
    int i, j;

    for(i = 0; i < DIMENSION; i++) {
        for(j = 0; j < DIMENSION; j++) {
            printf("Introduzca el elemento %d %d :", i, j);
            scanf("%f", &M[i][j]);
        }
        printf("\n");
    }
}

int main (int argc, char *argv[])
{
    /*
     * Definición de tres arrays bidimensionales
     */
    float A[DIMENSION][DIMENSION]; 
    float B[DIMENSION][DIMENSION];
    float C[DIMENSION][DIMENSION];

    leerMatriz(A);
    leerMatriz(B);
    multiplicarMatriz(A, B, C);
    imprimirMatriz(C);

    return (0);
}



