/* 
 * Programa:    prog09_08
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Lee cadenas y encuentra cuantas palabras iguales a lector hay.
 */

#include <stdio.h>
#include <string.h>


int main(void)
{
    char palabra[128] ;
    int  total = 0 ; /* cuenta el n�mero de ocurrencias de "lector"*/

    while (scanf("%s", palabra) != EOF) /* no fin de archivo */
    {
        /* se compara la palabra le�da con "lector" */
        if (strcmp(palabra, "lector") == 0)
            total++;
    }
    printf("El n�mero total de veces que aparece lector es %d\n",
            total);

    return(0);
}

