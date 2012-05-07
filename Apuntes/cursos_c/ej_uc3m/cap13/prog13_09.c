/* 
 * Programa:    prog13_09
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Programa ejemplo de compilación condicional de código
 */


#include <stdio.h>
#include <stdarg.h>

int sumar(int contador, ...)
{
    va_list ap;
    int arg;
    int total = 0;
    int i = 0;

    va_start(ap, contador);
    for (i = 0; i < contador; i++)
    {
        arg = va_arg(ap, int);
#ifdef DEBUG
        printf("total = %d\n", total);
        printf("arg = %d\n", arg);
#endif
        total = total + arg;
    }
    va_end(ap);
    return(total);
}

int main(void)
{
    int suma;

    suma = sumar(4, 1, 2, 3, 4);
    printf("suma = %d\n", suma);
    return (0);
}

