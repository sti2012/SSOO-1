/*
 * Programa:    prog_04_03
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 4:
 *              Prioridad de los operadores aritm�ticos
 */
#include <stdio.h>

int main(void)
{
    int  a = 4;
    int  b = 7;
    int  c = 3;
    int  d = 9;
    int resultado;

    resultado = a + b * c;
    printf("Resultado = %d\n", resultado);

    resultado = a * b / c * d;
    printf("Resultado = %d\n", resultado);

    resultado = (a + b) * (d / c);
    printf("Resultado = %d\n", resultado);



    return (0);

}


