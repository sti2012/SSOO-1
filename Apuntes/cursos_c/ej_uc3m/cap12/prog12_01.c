/* 
 * Programa:    prog12_01.c
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Ejemplo de creaci�n de un archivo.
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

