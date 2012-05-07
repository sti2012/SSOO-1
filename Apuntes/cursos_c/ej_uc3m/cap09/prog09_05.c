/* 
 * Programa:    prog09_05
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Lectura de una cadena carácter a carácter.
 */

#include <stdio.h>

#define TAM_LINEA   80


int main(void)
{
   char linea[TAM_LINEA];
   char ch;
   int i;

   printf("Introduzca una línea: \n");
   i  = 0;
   ch = getchar();
   while ( (ch != EOF) && (i < TAM_LINEA-1) )
   {
      linea[i] = ch;
      i++;
      ch = getchar();
   }
   linea[i]='\0';

   printf("Se ha leído la nota: %s\n", linea);
   return (0);
}

