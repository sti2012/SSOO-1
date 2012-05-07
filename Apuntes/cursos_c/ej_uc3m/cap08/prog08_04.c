/*
 * Programa:    prog_08_04
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 8:
 *              Programa que calcula las temperaturas medias de un año
 *              utilizando una función
 */

#include <stdio.h>

#define NUMERO_MESES    12

float calcularMedias(const float v[], int n)
{
    int j;
    float media = 0.0;

    for (j = 0; j< n; j++)
        media = media + v[j];

    media = media / n;
    return (media);
}

int main(void)
{
    float temperaturasMedias[NUMERO_MESES];
    float temperaturaMedia = 0.0;
    int   j;

    for(j = 0; j < NUMERO_MESES; j++) {
        printf("Introduzca la temperatura del mes %d: ", j);
        scanf("%f", &temperaturasMedias[j]);
    }

    temperaturaMedia = calcularMedias(temperaturasMedias, NUMERO_MESES);
    printf("La temperatura media del año es %f\n", temperaturaMedia);

    return(0);
}


