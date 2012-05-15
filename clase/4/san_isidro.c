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

