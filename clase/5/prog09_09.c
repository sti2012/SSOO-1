/* 
 * Programa:    prog09_09
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
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
     *  a través de 'puntero'
     */
    puntero = cadena ;  /* dirección en memoria de la letra 'H' */

    /* formato, como cadena de caracteres amplios */
    wprintf(L"%Ls\n", puntero);   

    return (0) ;
}

