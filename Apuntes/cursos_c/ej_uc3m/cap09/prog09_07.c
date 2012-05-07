/* 
 * Programa:    prog09_07
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Implementación de mistrcpy.
 */

#include <stdio.h>

char *mistrcpy(char *copia, const char *original)
{
   char *ch = copia;

   /*
    *  Copiar los caracteres de la cadena hasta
    *  el carácter fin de cadena.
    */
   while (*original != '\0') {
       *ch = *original;
       ch++;
       original++;
   }
   /* se copia el carácter nulo */
   *ch = '\0';
   return copia ;
}


int main(void) 
{
    char mensaje[] = "Hola a todos" ;
    char mensaje2[100] ;

    /* se copia mensaje en mensaje2 */
    mistrcpy(mensaje2, mensaje) ;
    printf("La cadena %s es la copia de %s\n",
           mensaje2, mensaje);
    return(0);
}

