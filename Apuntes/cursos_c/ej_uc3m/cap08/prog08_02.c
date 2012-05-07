/*
 * Programa:    prog_08_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 8:
 *              Programa que calcula las temperaturas medias de un año
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
    printf("La temperatura media del año es %f\n", temperaturaMedia);

    return(0);
}

