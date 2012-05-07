/* 
 * Programa:    prog09_03
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Uso de printf y scanf para leer strings.
 */

#include <stdio.h>

#define TAM_CADENA    80


int main(void)
{
   char cadena[TAM_CADENA];

   /*
    *  Imprimir la cadena constante:
    *  "Introduzca una cadena: "
    */
   printf("Introduzca una cadena: ");

   /*
    *  Leer una cadena 
    */
   scanf("%s", cadena);

   /*
    *  Imprimir la variable 'cadena' 
    */
   printf("La cadena es %s\n", cadena);

   return (0);
}

