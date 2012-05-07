/* 
 * Programa:    prog13_07
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Programa que incrementa un número entero en 1.
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
    /* Código en ensamblador Intel Pentium. 
     * Compilador gcc.
     * la instrucción incl suma uno al valor de %0
     */
    asm(
        "\tincl %0\n\t"
       :"=m" (*n)
       :"m" (n)
    );
}


