/*
 * Programa:    prog_10_08
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 10:
 *              Programa con errores
 */
#include <stdio.h>

struct DatosBancarios {
    char nombre[128];   /* nombre del usuario */
    char cuenta[20];    /* n�mero de la cuenta */
}

int main(void)
{
    DatosBancarios  *cuenta;
    printf("Introduca el nombre del usuario de la cuenta: ");
    scanf("%s", cuenta.nombre);

    printf("Introduca el n�mero de la cuenta: ");
    scanf("%s", cuenta.numero);

    printf("El n�mero de cuenta introducido es %s\n", cuenta.cuenta);
    return(0);
}

