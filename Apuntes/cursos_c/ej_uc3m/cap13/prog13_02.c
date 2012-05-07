/* 
 * Programa:    prog13_02
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Programa que calcula una máscara de bits de un número
 */


#include <stdio.h>
#define MASCARA 0xF  /* 0...0000001111 */

int main(void)
{
    int n;

    printf("Introduzca n: ");
    scanf("%d", &n);
    printf("Bits menos significativos = %d\n",
        n & MASCARA );
    return (0);
}

