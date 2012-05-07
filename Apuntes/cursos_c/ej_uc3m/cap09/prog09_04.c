/* 
 * Programa:    prog09_04
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Programa que lee línea e imprime las que tiene más de 40 
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
