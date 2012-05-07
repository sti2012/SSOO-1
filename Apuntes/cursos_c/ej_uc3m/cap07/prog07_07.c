/*
 * Programa:    prog_07_07
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
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

    printf("El máximo es %d\n", mayor);

    return (0);
}

