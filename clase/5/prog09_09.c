/* 
 * Programa:    prog09_09
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Cadenas de caracteres extendidos.
 */

#include <stdio.h>
#include <wchar_t.h>


int main(void)
{
    wchar_t cadena[] = L"Hola mundo\n";
    wchar_t *puntero;

    /*
     *  Imprimir el contenido de 'cadena'
     *  a trav�s de 'puntero'
     */
    puntero = cadena ;  /* direcci�n en memoria de la letra 'H' */

    /* formato, como cadena de caracteres amplios */
    wprintf(L"%Ls\n", puntero);   

    return (0) ;
}

