/*
 * Programa:    prog_07_06
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que calcula el factorial recursivamente
 */
#include <stdio.h>

int factorial (int dato)
{
    int resultado;

    if (1 >= dato) {
        /* por esta rama finaliza la funci�n recursiva */
        resultado = 1;  
    } else {
        /* aqu� se ejecuta la llamada recursiva modificando los par�metros*/
        resultado = dato * factorial(dato - 1);
    }
    return (resultado);
}
int main(void) 
{
    int valor;
    int fact;

    printf ("introduzca un n�mero: ");
    scanf("%d",&valor);

    fact = factorial(valor);

    printf ("El factorial es %d\n", fact);
    
    return (0);
}

