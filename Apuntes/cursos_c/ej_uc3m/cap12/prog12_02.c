/* 
 * Programa:    prog12_02
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
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

