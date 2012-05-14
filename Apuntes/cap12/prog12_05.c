/* 
 * Programa:    prog12_05
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Ejemplo de lectura de datos.
 */

#include <stdio.h>

int main(void)
{
    int leidos;
    float cantidad;
    char unidad[15], elemento[21];
    /* Bucle de lectura.
     * Para cuando se alcanza el fin de la entrada (EOF)
     * o cuando hay un error de entrada.
     */
    do
    {
        leidos = fscanf(stdin, "cantidad: %f %14s de %20s\n", 
                      &cantidad, unidad, elemento);
        if (3 != leidos) {
            fscanf(stdin, "%*[^\n]");
            fscanf(stdin,"\n");
        }
    } while (!feof(stdin) && !ferror(stdin));
    return(0);   
}
