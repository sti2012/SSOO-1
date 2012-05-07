/* 
 * Programa:    prog13_07
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que incrementa un n�mero entero en 1.
 */


#include <stdio.h>

void incrementar(int *n);

int main(void)
{
    int a = 3;

    printf("Introduzca el valor de a: ");
    scanf("%d", &a);
    incrementar(&a);
    printf("El valor de a + 1 es: %d\n",  a);
    return (0);
}

void incrementar(int *n)
{
    /* C�digo en ensamblador Intel Pentium. 
     * Compilador gcc.
     * la instrucci�n incl suma uno al valor de %0
     */
    asm(
        "\tincl %0\n\t"
       :"=m" (*n)
       :"m" (n)
    );
}


