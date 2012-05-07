/* 
 * Programa:    prog09_08
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Lee cadenas y encuentra cuantas palabras iguales a lector hay.
 */

#include <stdio.h>
#include <string.h>


int main(void)
{
    char palabra[128] ;
    int  total = 0 ; /* cuenta el número de ocurrencias de "lector"*/

    while (scanf("%s", palabra) != EOF) /* no fin de archivo */
    {
        /* se compara la palabra leída con "lector" */
        if (strcmp(palabra, "lector") == 0)
            total++;
    }
    printf("El número total de veces que aparece lector es %d\n",
            total);

    return(0);
}

