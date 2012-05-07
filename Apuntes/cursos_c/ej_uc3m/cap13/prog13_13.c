/* 
 * Programa:    prog13_13
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
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
    /* se ignora la se�al SIGINT */
    signal(SIGALRM, tratarSenial);

    alarm(3);

    while(1) {
        // bucle infinito
    }

    return(0);
}
