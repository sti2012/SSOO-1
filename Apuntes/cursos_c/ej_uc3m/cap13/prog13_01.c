/* 
 * Programa:    prog13_01
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que utiliza los parametros de la funcion main
 */
#include <stdio.h>

int main (int argc, char *argv[])
{
    int i;

    printf("El n�mero de argumentos es %d \n", argc);
    for (i = 0; i < argc; i++) {
        printf("El argumento %d es %s \n", i, argv[i]);
    }

    return (0);
}

