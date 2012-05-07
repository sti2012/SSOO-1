/* 
 * Programa:    prog13_12
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
 *              Programa que utiliza un manejador de señal
 */
#include <stdio.h>
#include <signal.h>

void tratarSenial(int s)
{
    printf("Se ha recibido la señal %d\n", s);
    return;
}

int main(void)
{
    /* se ignora la señal SIGINT */
    signal(SIGINT, tratarSenial);

    while(1) {
        /* bucle infinito que no se aborta pulsando */
   }
   return(0);
}

