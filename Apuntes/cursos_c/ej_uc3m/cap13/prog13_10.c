/* 
 * Programa:    prog13_01
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Ejemplo completo de compilacion condicional
 */


#include <stdio.h>
#include <stdarg.h>


/*
 * Prototipos
 */
int sumarDos(int x, int y);
int sumar(int contador, ...);

/*
 * Programa principal
 */
int main(void)
{
   int suma;

#ifndef SUMAVARIABLE
   printf("SUMAVARIABLE no definida en Makefile\n");
   suma = sumarDos(4, 1);
#else
   printf("SUMAVARIABLE definida en Makefile\n");
   suma = sumar(4, 1, 2, 3, 4);
#endif
   printf("suma = %d\n", suma);
   return (0);
}

int sumarDos(int x, int y)
{
    return (x+y);
}

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

