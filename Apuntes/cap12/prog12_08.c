/* 
 * Programa:    prog12_08
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 12:
 *              Programa que copia un archivo en otro usando E/S de caracteres.
 */


#include <stdio.h>

int main(void)
{
   FILE *fent;
   FILE *fsal;
   int   car;
   int   res = 0;

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

    /* Bucle de lectura y escritura */
    while ((car = fgetc(fent)) != EOF)
    {
        res = fputc(car, fsal);
        if (res == EOF)
            fprintf(stderr, "Error al escribir %c \n", car);
    }
    /* Cierre de los streams de entrada y de salida */
    fclose(fent);
    fclose(fsal);
    return(0);
}

