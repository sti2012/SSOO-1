/*
 * Programa:    prog_05_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 5:
 *              Programa que lee un número y devuelve su cuadrado
 */
#include <stdio.h>

int main()
{
    int numero;
    int cuadrado;
    
    /*
     * Leer el numero
     */
    printf ("Introduzca un número: ");
    scanf ("%d", &numero);

    if (0 == (numero % 2)) {
        cuadrado = numero * numero;
        printf ("El cuadrado de %d es %d.\n",numero, cuadrado);
    }
    return(0);
}

