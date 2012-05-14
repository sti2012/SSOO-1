/* 
 * Programa:    prog12_06
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Ejemplo de escritura de datos.
 */


#include <stdio.h>

int main(void)
{
    int leidos, escritos;
    float cantidad;
    char unidad[15], elemento[21];

    /* Bucle de lectura.
     * Para cuando se alcanza el fin de la entrada (EOF)
     * o cuando hay un error de entrada.
     */
    do
    {
        leidos = fscanf(stdin, "cantidad: %f %14s de %20s", 
                      &cantidad, unidad, elemento);
        if (3 != leidos) {
            fscanf(stdin, "%*[^\n]");
            fscanf(stdin,"\n");
        } else {
            /* Escritura de datos o error */
            escritos = fprintf(stdout,  "cantidad: %f %14s de %20s \n", 
                          cantidad, unidad, elemento);
            if (escritos < 0) {
                fprintf(stderr, "Error de escritura en el stream stdout \n");
            }
        }
    } while (!feof(stdin) && !ferror(stdin));
    return(0);   
}