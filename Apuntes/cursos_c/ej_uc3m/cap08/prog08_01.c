/*
 * Programa:    prog_08_01
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 8:
 *              Programa que calcula las temperaturas medias de un a�o
 */

#include <stdio.h>

#define NUMERO_MESES    12

int main(void)
{
    float temperaturasMedias[NUMERO_MESES];
    float temperaturaMedia = 0.0;
    short leidos;
    int   j;

    /*
     * Se leen las temperaturas medias de los 12 meses
     */
    for(j = 0; j < NUMERO_MESES; j++) {
        printf("Introduzca la temperatura del mes %d: ", j+1);
        leidos =  scanf("%f", &temperaturasMedias[j]);
        if (leidos < 1) {
            printf("Error al leer la temperatura\n");
            return(0);
        }
    }

    /*
     * Se calcula la temperatura media del a�o
     */
    for(j = 0; j < NUMERO_MESES; j++) 
        temperaturaMedia = temperaturaMedia + temperaturasMedias[j];

    temperaturaMedia = temperaturaMedia / NUMERO_MESES;
    printf("La temperatura media del a�o es %f\n", temperaturaMedia);

    return(0);
}

