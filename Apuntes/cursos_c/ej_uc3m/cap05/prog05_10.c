/*
 * Programa:    prog_05_010
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 5:
 *              Programa que lee un número, lo comprueba y devuelve el resultado
 *              de sumar desde 1 hasta el número
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
        printf ("Introduzca un número positivo, 0 para terminar: ");
        scanf ("%d", &numero);
        
        if (0 == numero) {
            printf("Finalizando el programa.\n");
            break;
        }
        if (0 > numero) {
            printf("Error: Número negativo.\n");
            continue;
        }
        suma = 0;
        for (contador = 0; contador <= numero; contador = contador + 1) {
            suma = suma + contador;
        }
        printf ("El resultado de sumar 1+2+...+N es %d.\n",suma);
    } while (1);
    return(0);
}

