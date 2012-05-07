/*
 * Programa:    prog_10_08
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 10:
 *              Programa con errores
 */
#include <stdio.h>

struct DatosBancarios {
    char nombre[128];   /* nombre del usuario */
    char cuenta[20];    /* número de la cuenta */
}

int main(void)
{
    DatosBancarios  *cuenta;
    printf("Introduca el nombre del usuario de la cuenta: ");
    scanf("%s", cuenta.nombre);

    printf("Introduca el número de la cuenta: ");
    scanf("%s", cuenta.numero);

    printf("El número de cuenta introducido es %s\n", cuenta.cuenta);
    return(0);
}

