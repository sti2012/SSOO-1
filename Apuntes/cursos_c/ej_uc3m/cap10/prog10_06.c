/*
 * Programa:    prog_10_06
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 10:
 *              Programa que muestra un ejemplo de uni�n
 */

#include <stdio.h>

union Datos {
    int entero;
    double real;
};

int main(void)
{
    union  Datos dato;

    printf("El tama�o de un int es %d\n", sizeof(int));
    printf("El tama�o de un double es %d\n", sizeof(double));
    printf("El tama�o de la uni�n es %d\n", sizeof(union Datos));

    dato.entero = 8;
    printf("El valor entero de la uni�n es %d\n", dato.entero);
				    
    dato.real = 8.24;
    printf("El valor real de la uni�n es %f\n", dato.real);

    return(0);
}

