/*
*ejemplox_54.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM    3


void leearray(int tabla[][TAM], int maxfilas, int maxcolumnas)
{
        int buf;
        int i, j;
           
        printf("Lectura de una tabla de enteros de %dx%d.\n", maxfilas, maxcolumnas);
        printf("Introduzca los terminos según se le vayan solicitando\n");

        for (i=0; i<maxfilas; i++) {
            for (j=0; j<maxcolumnas; j++) {
                printf("  termino (%d,%d): ", i, j);
                scanf("%d", &buf);
                tabla[i][j] = buf;
            }
        }
}

void imprimearray(int tabla[][TAM], int maxfilas, int maxcolumnas)
{
        char sep;
        int i, j;

        for (i=0; i<maxfilas; i++) {
            printf("[");
            sep = ' ';
            for (j=0; j<maxcolumnas; j++) {
                printf("%c%d", sep, tabla[i][j]);
                sep = ',';
            }
            printf(" ]\n");
        }
}
 
void sumamatrices(int res[][TAM], int ma[][TAM], int mb[][TAM], int maxfilas, int maxcolumnas)
{
        int i, j;

        for (i=0; i<maxfilas; i++) {
            for (j=0; j<maxcolumnas; j++) {
                res[i][j] = ma[i][j] + mb[i][j];
            }
        }
}


    
int main() {
   int m1[TAM][TAM], m2[TAM][TAM], res[TAM][TAM];
   float suma, media, varianza, desvtipica;
   int num, posminimo;

   leearray(m1, TAM, TAM);
   leearray(m2, TAM, TAM);

   sumamatrices(res, m1, m2, TAM, TAM);
   
   printf("m1:\n");
   imprimearray(m1, TAM, TAM);
   printf("m2:\n");
   imprimearray(m2, TAM, TAM);
   printf("m1 + m2:\n");
   imprimearray(res, TAM, TAM);
 
   system("PAUSE");	
   return 0;
}
