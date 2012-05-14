/* 
 * Programa:    prog12_08
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
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

    /* Apertura, con creaci�n si no existe, del archivo de salida */
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

