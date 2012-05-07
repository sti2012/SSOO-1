/*
 * Programa:    prog_08_04
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 8:
 *              Programa que calcula las temperaturas medias de un a�o
 *              utilizando una funci�n
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
    printf("La temperatura media del a�o es %f\n", temperaturaMedia);

    return(0);
}


