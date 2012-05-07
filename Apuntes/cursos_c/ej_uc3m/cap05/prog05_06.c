/*
 * Programa:    prog_05_06
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 5:
 *              Programa que lee un número y devuelve la suma desde 1 hasta el
 *              número
 */
#include <stdio.h>

int main()
{
    int numero;
    int suma = 0;
    
    /*
     * Leer el numero. Debe ser mayor que cero 
     */
    printf ("Introduzca un número (Debe ser mayor que 0): ");
    scanf ("%d", &numero);

    do {
        suma = suma + numero;
        numero = numero - 1;
    } while (0 < numero);
    printf ("El resultado de sumar 1+2+...+N es %d.\n",suma);
    return(0);
}

