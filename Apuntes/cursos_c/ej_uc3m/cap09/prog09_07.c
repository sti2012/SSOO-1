/* 
 * Programa:    prog09_07
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Implementaci�n de mistrcpy.
 */

#include <stdio.h>

char *mistrcpy(char *copia, const char *original)
{
   char *ch = copia;

   /*
    *  Copiar los caracteres de la cadena hasta
    *  el car�cter fin de cadena.
    */
   while (*original != '\0') {
       *ch = *original;
       ch++;
       original++;
   }
   /* se copia el car�cter nulo */
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

