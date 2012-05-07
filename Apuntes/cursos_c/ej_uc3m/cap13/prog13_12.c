/* 
 * Programa:    prog13_12
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que utiliza un manejador de se�al
 */
#include <stdio.h>
#include <signal.h>

void tratarSenial(int s)
{
    printf("Se ha recibido la se�al %d\n", s);
    return;
}

int main(void)
{
    /* se ignora la se�al SIGINT */
    signal(SIGINT, tratarSenial);

    while(1) {
        /* bucle infinito que no se aborta pulsando */
   }
   return(0);
}

