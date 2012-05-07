/* 
 * Programa:    prog12_02
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 12:
 *              Ejemplo de renombrado de un archivo.
 */

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   int res;

   res = rename("./ejemplo.txt", "./ejemplo_1.txt");
   if (res != 0)
   {
      printf("Error, no se puede renombrar el archivo\n");
   }
   system("PAUSE");
   return(0);
}

