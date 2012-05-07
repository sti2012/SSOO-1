/* 
 * Programa:    prog09_04
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Programa que lee l�nea e imprime las que tiene m�s de 40 
 *              caracteres.
 */

#include <stdio.h>

int longitud(const char *cadena);

#define TAM_LINEA     256


int main(void)
{
   char linea[TAM_LINEA];

   while(gets(linea) != NULL) {
       if (longitud(linea) < 40)
           puts(linea);
   }

   return (0);
}

int longitud(const char *c)
{
    int l = 0;

    while(*c != '\0') {
        l++;
        c++;
    }
    return(l);
}
