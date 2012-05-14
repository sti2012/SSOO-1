/* 
 * Programa:    prog12_04
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Apertura y cierre de un archivo.
 */

#include <stdio.h>

int main(void)
{
   FILE *desc;
   int num;
   char letra;

   /* Creaci�n del archivo ejemplo.txt */
   desc = fopen("./ejemplo.txt", "w");
   if (desc == NULL)
   {
      printf("Error, no se puede crear el archivo\n");
   }
   else
   {
      /* Archivo creado. Se escriben 10000 'a'
       * con saltos de l�neas cada 80 caracteres
       */
      for (num = 0; num < 1000; num++)
      {
          if ((num % 80) != 0)
              fprintf(desc, "%c", 'a');
          else
              fprintf(desc, "%c", '\n');
     }
      /* al final se cierra */
      fclose(desc);
   }
   /* Apertura del archivo ejemplo.txt */
   desc = fopen("./ejemplo.txt", "r");
   if (desc == NULL)
   {
      printf("Error, no se puede abrir el archivo\n");
   }
   else
   {
      /* Archivo abierto. Se lee algo */
      fscanf(desc, "%c", &letra);
      printf("%c \n", letra); 
      /* al final se cierra */
      fclose(desc);
   }
   return(0);
}

