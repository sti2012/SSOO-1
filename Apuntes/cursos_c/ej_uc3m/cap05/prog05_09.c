/*
 * Programa:    prog_05_09
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
    int suma;
    int contador;
    
    do {
        /*
         * Leer el numero. 
         */
        printf ("Introduzca un número: ");
        scanf ("%d", &numero);
        
        suma = 0;
        for (contador = 0; contador <= numero; contador = contador + 1) {
            suma = suma + contador;
        }
        printf ("El resultado de sumar 1+2+...+N es %d.\n",suma);
    } while (0 < numero);
    return(0);
}

