/* 
 * Programa:    prog12_01.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 12:
 *              Ejemplo de creación de un archivo.
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *desc;

   desc = fopen("./ejemplo.txt", "w");
   if (desc == NULL)
   {
      printf("Error, no se puede crear el archivo\n");
   }
   else
   {
      /* Archivo creado. Se escribe algo */
      fprintf(desc, "%d", 111111);
      /* al final se cierra */
      fclose(desc);
   }
   system("PAUSE");
   return(0);
}

