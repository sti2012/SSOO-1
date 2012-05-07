/*
 * Programa:    prog_05_01
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 5:
 *              Programa que lee un número y dice si es par
 */
#include <stdio.h>

int main()
{
    int numero;
    
    /*
     * Leer el numero
     */
    printf ("Introduzca un número: ");
    scanf ("%d", &numero);

    if (0 == (numero % 2)) 
        printf ("El número %d es par.\n",numero);
    return(0);
}

