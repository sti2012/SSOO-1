/* 
 * Programa:    prog10_01
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripcin:  Ejemplo del Cap�tulo 10:
 *              C�lculo del prefijo de un n�mero telef�nico.
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



