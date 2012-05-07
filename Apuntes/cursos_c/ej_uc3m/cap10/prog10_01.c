/* 
 * Programa:    prog10_01
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripcin:  Ejemplo del Capítulo 10:
 *              Cálculo del prefijo de un número telefónico.
 */
#include <stdio.h>

struct Coordenadas {
    float x;
    float y;
};

int main(void)
{
    struct Coordenadas  puntoA, puntoB;

    printf("Introduzca la coordenada x del punto A: ");
    scanf("%f", &(puntoA.x));
    printf("Introduzca la coordenada y del punto A: ");
    scanf("%f", &(puntoA.y));

    printf("Introduzca la coordenada x del punto B: ");
    scanf("%f", &(puntoB.x));
    printf("Introduzca la coordenada y del punto B: ");
    scanf("%f", &(puntoB.y));

    if ((puntoA.x == puntoB.x) && (puntoA.y == puntoB.y))
        printf("Los puntos A y B son iguales\n");
    else
        printf("Los puntos A y B son distintos\n");

    return(0);
}



