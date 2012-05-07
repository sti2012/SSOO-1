/* 
 * Programa:    prog13_11
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Programa que ignora las señales de ruptura
 */
#include <stdio.h>
#include <signal.h>

int main(void)
{
    /* se ignora la señal SIGINT */
    signal(SIGINT, SIG_IGN);

    while(1) {
         /*
         bucle infinito que no se aborta pulsando
         contro-c
	 */
        printf("Este programa no acaba pulsando control-c\n");
   }
}
