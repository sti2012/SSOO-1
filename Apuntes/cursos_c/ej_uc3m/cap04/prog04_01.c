/*
 * Programa:    prog_04_01
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
 *              Programa que ilustra el uso de los operadores aritméticos
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


