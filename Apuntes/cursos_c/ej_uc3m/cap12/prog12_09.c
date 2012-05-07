/* 
 * Programa:    prog12_09
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 12:
 *              Programa que copia un archivo en otro usando E/S de líneas.
 */

#include <stdio.h>

int main(void)
{
   FILE *fent;
   FILE *fsal;
   char car[120];
   int res = 0;
   char * ret;

    /* Apertura del archivo de entrada */
    fent = fopen("./entrada.txt", "r");
    if (fent == NULL)
    {
       fprintf(stderr, "Error abriendo entrada.txt \n");
       return(0);
    }

    /* Apertura, con creación si no existe, del archivo de salida */
    fsal = fopen("./salida.txt", "w");
    if (fsal == NULL)
    {
       fprintf(stderr, "Error creando salida.txt \n");
       fclose(fent);
       return(0);
    }

    /* Bucle de lectura y escritura con líneas */
    do
    {
        /* Lectura de la línea siguiente */
        ret = fgets(car, 110, fent);
        if ( car == NULL)
		fprintf(stderr, "Error al leer \n");
         else
            fprintf(stdin, "Longitud linea leida: %d \n", strlen(car));
        /* Escritura de la línea */
        if (ret != NULL) {
            res = fputs(car, fsal);
            if (res == EOF)
                fprintf(stderr, "Error al escribir %s \n", car);
        }
    } while (ret != NULL);
    /* Cierre de los streams de entrada y de salida */
    fclose(fent);
    fclose(fsal);
    return(0);
}

