/* 
 * Programa:    prog09_02
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Programa lee una cadena e imprime su longitud
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * Calcula la longitud de una cadena
 */
int longitud(const char *c);

int main(void)
{
    
    char  *cadena;
    
    /* se reserva espacio para la cadena */
    cadena = (char *)malloc(256 * sizeof(char)) ;

    printf("Introduzca una cadena de caracteres (m�ximo 256): ");
    scanf("%s", cadena);
    printf("Su longitud es %d\n", longitud(cadena));

    /* se libera la cadena */
    free(cadena);
    return(0);
}


int longitud(const char *c)
{
    int l = 0;

    while(*c != '\0') {
        l++;
        c++;
    }
    return(l);
}
