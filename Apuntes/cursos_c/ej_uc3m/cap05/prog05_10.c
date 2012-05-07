/*
 * Programa:    prog_05_010
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 5:
 *              Programa que lee un n�mero, lo comprueba y devuelve el resultado
 *              de sumar desde 1 hasta el n�mero
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
        printf ("Introduzca un n�mero positivo, 0 para terminar: ");
        scanf ("%d", &numero);
        
        if (0 == numero) {
            printf("Finalizando el programa.\n");
            break;
        }
        if (0 > numero) {
            printf("Error: N�mero negativo.\n");
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

