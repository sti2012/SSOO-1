/* 
 * Programa:    prog12_03
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Ejemplo de borrado de un archivo.
 */

#include <stdio.h>

int main(void)
{
   int res;

   res = remove("./ejemplo_1.txt");
   if (res != 0)
   {
      printf("Error, no se puede borrar el archivo\n");
   }
   return(0);
}

