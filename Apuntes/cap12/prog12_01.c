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

int main()
{
   FILE *desc;

   desc = fopen("./ejemplo.txt", "a"); //lo guarda en el directorio actual (./)
   /*
	  r --> Abre para lectura.
	  w --> Abre para crear nuevo archivo (si ya existe se pierden sus datos).
	  a --> Abre para a�adir al final.
	  r+ --> Abre archivo ya existente para modificar (leer/escribir).
	  w+ --> Crea un archivo para escribidleer (si ya existe se pierden los datos).
	  a+ --> Abre el archivo para modificar (exribidleer) al final. Si no existe es como w+.
   */
   if (desc == NULL)
   {
	  printf("Error, no se puede crear el archivo\n");
   }
   else
   {
	  /* Archivo creado. Se escribe algo */

	  fprintf(desc, "%s", "Hola pepe");
	  // fprintf(desc, "\n%d", "111111");

	  /* al final se cierra */
	  fclose(desc);
   }
   return(0);
}

