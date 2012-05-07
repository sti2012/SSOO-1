/*
 * Programa:    prog_07_07
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que calcula el maximo mediante una macro
 */
#include <stdio.h>

/*
 * Macro maximo
 */
#define maximo(a, b) (( a > b ) ? a : b ) 

int main(void)
{
    int x, y;
    int mayor;

    printf("Introduzca dos numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);

    /* llamada a la macro */
    mayor = maximo(x,y);    

    printf("El m�ximo es %d\n", mayor);

    return (0);
}

