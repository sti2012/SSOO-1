/*
 * Programa:    prog_05_05
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 5:
 *              Programa que ejecuta una cuenta atras
 */
#include <stdio.h>

int main()
{
    int numero;
    int indice;
    
    /*
     * Leer el inicio de la cuenta atrás 
     */
    printf ("Introduzca el inicio de la cuenta atrás: ");
    scanf ("%d", &numero);

    printf ("Comienza la cuenta atrás:\n");
    for (indice = numero; 0 <= indice; indice = indice - 1) {
        printf ("%d\n",indice);
    }
    printf ("Despegue...\n");
    return(0);
}

