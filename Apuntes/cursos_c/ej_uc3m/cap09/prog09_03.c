/* 
 * Programa:    prog09_03
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
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

