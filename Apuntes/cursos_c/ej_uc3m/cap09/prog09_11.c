/* 
 * Programa:    prog09_11
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Programa que utiliza cadenas de caracteres con errores.
 */

#include <stdio.h>
#include <wchar_t.h>

int main(void)
{
    char cadena1[] = "Esto es una cadena;
    char cadena2[5];
    char *cadena3;

    strcpy(cadena2, cadena1);
    printf("Cadena2 es %d\n" cadena2);

    /* se lee una línea */
    scanf("%s", &cadena3);
    print("La cadena leída es %s\n", cadena3);

    return(0);
}
