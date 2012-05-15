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
	desc = fopen("./dia_sanisidro.txt", "a"); 

	if (desc == NULL)
	{
		printf("Error, no se puede crear el archivo\n");
	}
	else
	{

		fprintf(desc, "%s", "que pases un buen dia");
		fclose(desc);
	}
	return(0);
}

