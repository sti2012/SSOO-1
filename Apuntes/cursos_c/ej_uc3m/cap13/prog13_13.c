/* 
 * Programa:    prog13_13
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Programa que gestiona una alarma
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>   /* para alarm */

void tratarSenial(int s)
{
    printf("Ha vencido la alarma\n");
    
    /* programa una nueva alarma */
    alarm(3);
    return;
}

int main(void)
{
    /* se ignora la señal SIGINT */
    signal(SIGALRM, tratarSenial);

    alarm(3);

    while(1) {
        // bucle infinito
    }

    return(0);
}
