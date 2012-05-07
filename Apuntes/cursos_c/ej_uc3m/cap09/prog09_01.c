/* 
 * Programa:    prog09_01.c
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Programa que cuenta el n�mero de veces que aparece la letra a
 *              en una cadena.
 */

#include <stdio.h>


int main(void)
{
    
    char  cadena[256];
    char  *puntero  ;
    int vecesA = 0;   /* contabiliza el n�mero de a */

    printf("Introduzca una cadena de caracteres (m�ximo 256): ");
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

