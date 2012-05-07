/* 
 * Programa:    prog09_11
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
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

    /* se lee una l�nea */
    scanf("%s", &cadena3);
    print("La cadena le�da es %s\n", cadena3);

    return(0);
}
