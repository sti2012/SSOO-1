/*
 * Programa:    prog_08_01
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 8:
 *              Programa que calcula las temperaturas medias de un año
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
     * Se calcula la temperatura media del año
     */
    for(j = 0; j < NUMERO_MESES; j++) 
        temperaturaMedia = temperaturaMedia + temperaturasMedias[j];

    temperaturaMedia = temperaturaMedia / NUMERO_MESES;
    printf("La temperatura media del año es %f\n", temperaturaMedia);

    return(0);
}

