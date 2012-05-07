/*
 * Programa:    prog_08_03
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 8:
 *              Programa que calcula las temperaturas medias de
 *              un a�o utilizando un array din�mico
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMERO_MESES    12

int main(void)
{
    float *temperaturasMedias;
    float temperaturaMedia = 0.0;
    short leidos;
    int   j;

    /*
     * Se reserva espacio para el array 
     */
    temperaturasMedias = (float *) malloc(NUMERO_MESES *sizeof(float));
    if (temperaturasMedias == NULL) {
        printf("Error no hay memoria suficiente\n");
        return(0);
    }


    for(j = 0; j < NUMERO_MESES; j++) {
        printf("Introduzca la temperatura del mes %d: ", j+1);
        leidos = scanf("%f", &temperaturasMedias[j]);
        if (leidos < 1) {
            printf("Error al leer la temperatura\n");
            return(0);
        }
    }

    for(j = 0; j < NUMERO_MESES; j++) 
        temperaturaMedia = temperaturaMedia + temperaturasMedias[j];


    temperaturaMedia = temperaturaMedia / NUMERO_MESES;
    printf("La temperatura media del a�o es %f\n", temperaturaMedia);

    /*
     * Se libera el espacio reservado para el array
     */
     free(temperaturasMedias);
    return(0);
}


