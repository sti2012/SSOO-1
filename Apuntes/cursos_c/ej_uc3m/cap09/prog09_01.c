/* 
 * Programa:    prog09_01.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Programa que cuenta el número de veces que aparece la letra a
 *              en una cadena.
 */

#include <stdio.h>


int main(void)
{
    
    char  cadena[256];
    char  *puntero  ;
    int vecesA = 0;   /* contabiliza el número de a */

    printf("Introduzca una cadena de caracteres (máximo 256): ");
    scanf("%s", cadena);

    puntero = cadena ;
    while ( *puntero != '\0' ) {
        if ((*puntero == 'a') || (*puntero == 'A')) {
            vecesA++;
        }
        puntero++ ;
    }

    printf("La letra a aparece %d veces\n", vecesA);
    return (0) ;
}

