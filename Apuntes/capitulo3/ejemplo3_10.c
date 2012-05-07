//ejemplo3_10.c
#include <stdio.h>
#include <math.h>

#define MAXBASE 15
#define MAXEXP  7

int main(){
    int base,exponente,i;
    /* cabecera de la tabla, con los exponentes y una raya */
    printf("\n\n\n    ");
    for (exponente=1;exponente<=MAXEXP;exponente++){
        printf("%10i",exponente);
    }
    printf("\n");
    /* Imprimir barra horizontal (ASCII 196) */
    for (i=0; i<78; i++) printf("%c",196);
    printf("\n");
    /* bucles anidados */
    for (base=1;base<=MAXBASE;base++){
        /* base y barra vertical (ASCII 179) */
        printf("%2d %c",base,179);
        /* Tabla de exponenciación */
        for (exponente=1;exponente<=MAXEXP;exponente++){
            printf("%10li",(long) pow(base,exponente));
        }
        printf("\n");
    }
    system("pause");
}
