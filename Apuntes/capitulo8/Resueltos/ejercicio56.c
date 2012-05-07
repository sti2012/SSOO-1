/*
*ejemplox_56.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM    5


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

int leenumero(const char *mensaje, int minimo, int maximo)
{
        int num;

        do {
            printf("  %s (rango %d - %d): ", mensaje, minimo, maximo);
            scanf("%d", &num);
        } while (num < minimo || num > maximo);
        
        return num;
}

 
void permutaarray(int tabla[][TAM], int maxcolumnas, int filai, int filaj)
{
        int tmp, j;

        if (filai == filaj) {
           return;
        }
        
        for (j=0; j<maxcolumnas; j++) {
            tmp = tabla[filai][j];
            tabla[filai][j] = tabla[filaj][j];
            tabla[filaj][j] = tmp;
        }
}


    
int main() {
   int tabla[TAM][TAM];
   int filai, filaj;
   
   leearray(tabla, TAM, TAM);
   filai = leenumero("Introduzca la fila a permutar", 0,4);
   filaj = leenumero("Introduzca la fila permutada", 0,4);

   printf("antes:\n");
   imprimearray(tabla, TAM, TAM);
   permutaarray(tabla, TAM, filai, filaj);
   printf("despues:\n");
   imprimearray(tabla, TAM, TAM);

   system("PAUSE");	
   return 0;
}
