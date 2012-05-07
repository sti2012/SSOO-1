/* 
 * Programa:    prog10_03
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripcin:  Ejemplo del Capítulo 10:
 *              Valores erroneos en una iniciación. Programa que determina 
 *              si dos puntos son iguales utilizando punteros a estructuras
 */


#include <stdio.h>
#include <stdlib.h>

struct Coordenadas {
    float x;
    float y;
};

int main(void)
{
    struct Coordenadas origen = {0.0, 0.0};
    struct Coordenadas *puntoA, *puntoB;

    puntoA = &origen;
    printf("Las coordenadas del origen son: ");
    printf("(%f %f) \n", puntoA->x, puntoA->y);

    /* Se reserva memoria para los puntos */
    puntoA = (struct Coordenadas *) malloc(sizeof(struct Coordenadas));
    puntoB = (struct Coordenadas *) malloc(sizeof(struct Coordenadas));
    if ((puntoA == NULL) || (puntoB == NULL)) {
        printf("Error, no hay memoria disponible\n");
        return(0);
    }

    printf("Introduzca la coordenada x del punto A: ");
    scanf("%f", &(puntoA->x));
    printf("Introduzca la coordenada y del punto A: ");
    scanf("%f", &(puntoA->y));

    printf("Introduzca la coordenada x del punto B: ");
    scanf("%f", &(puntoB->x));
    printf("Introduzca la coordenada y del punto B: ");
    scanf("%f", &(puntoB->y));
    if ((puntoA->x == puntoB->x) && (puntoA->y == puntoB->y))
        printf("Los puntos A y B son iguales\n");
    else
        printf("Los puntos A y B son distintos\n");

    free (puntoA);
    free (puntoB);

    return(0);
}

