/*
 * Programa:    prog_05_04
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
     * Leer el numero 
     */
    printf ("Introduzca un número: ");
    scanf ("%d", &numero);

    while (0 < numero) {
        suma = suma + numero;
        numero = numero - 1;
    }
    printf ("El resultado de sumar 1+2+...+N es %d.\n",suma);
    return(0);
}

