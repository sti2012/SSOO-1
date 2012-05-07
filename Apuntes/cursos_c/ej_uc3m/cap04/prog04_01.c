/*
 * Programa:    prog_04_01
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 4:
 *              Programa que ilustra el uso de los operadores aritm�ticos
 */

#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 3;
    int c;

    c = a + b;
    printf("%d + %d = %d\n", a, b, c);
    
    c = a - b;
    printf("%d - %d = %d\n", a, b, c);

    c = a * b;
    printf("%d * %d = %d\n", a, b, c);
    
    c = a / b;
    printf("%d / %d = %d\n", a, b, c);
    
    c = a % b;
    printf("%d %% %d = %d\n", a, b, c);
							        
    return(0);

}


