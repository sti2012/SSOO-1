/*
 * Programa:    prog_02_02
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 2:
 *              Programa estructurado en C. Imprime un saludo al lector
 */

#include <stdio.h>
#define DESTINO "Lector"

/*
 * Prototipo de funciones
 */
int imprimir_saludo (char * destino);

int main(void)
{
    
    /* 
     * Funci�n que imprime un mensaje de saludo al Lector
     */
     imprimir_saludo (DESTINO);

    /* 
     * Terminaci�n del programa 
     */
    return(0);  /* correcto */
}

int imprimir_saludo (char * destino)
{

    printf("Hola %s.\n", destino);
    return (0);
}
