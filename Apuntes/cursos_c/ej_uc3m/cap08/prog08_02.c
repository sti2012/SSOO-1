/*
 * Programa:    prog_08_02
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 8:
 *              Programa que calcula las temperaturas medias de un a�o
 *              utilizando un puntero
 */
#include <stdio.h>

#include <stdio.h>

#define NUMERO_MESES    12

int main(void)
{
    float temperaturasMedias[366];
    float temperaturaMedia = 0.0;
    float *ptr;
    short   leidos;
    int   j;

    ptr = temperaturasMedias;

    for(j = 0; j < NUMERO_MESES; j++) {
        printf("Introduzca la temperatura del mes %d: ", j+1);
        leidos = scanf("%f", ptr);
        if (leidos < 1) {
            printf("Error al leer la temperatura\n");
            return(0);
        }
        ptr ++;
    }

    for(j = 0; j < NUMERO_MESES; j++) {
        temperaturaMedia = temperaturaMedia + *ptr;
        ptr ++;
    }

    temperaturaMedia = temperaturaMedia / NUMERO_MESES;
    printf("La temperatura media del a�o es %f\n", temperaturaMedia);

    return(0);
}

