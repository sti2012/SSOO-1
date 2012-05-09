/*
 * Programa:    prog_07_06
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
 *              Programa que calcula el factorial recursivamente
 */
#include <stdio.h>

int factorial (int dato)
{
    int resultado;

    if (1 >= dato) {
        /* por esta rama finaliza la función recursiva */
        resultado = 1;  
    } else {
        /* aquí se ejecuta la llamada recursiva modificando los parámetros*/
        resultado = dato * factorial(dato - 1);
    }
    return (resultado);
}
int main(void) 
{
    int valor;
    int fact;

    printf ("introduzca un número: ");
    scanf("%d",&valor);

    fact = factorial(valor);

    printf ("El factorial es %d\n", fact);
    
    return (0);
}

