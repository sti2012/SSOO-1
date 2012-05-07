/* 
 * Programa:    prog13_11
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que ignora las se�ales de ruptura
 */
#include <stdio.h>
#include <signal.h>

int main(void)
{
    /* se ignora la se�al SIGINT */
    signal(SIGINT, SIG_IGN);

    while(1) {
         /*
         bucle infinito que no se aborta pulsando
         contro-c
	 */
        printf("Este programa no acaba pulsando control-c\n");
   }
}
