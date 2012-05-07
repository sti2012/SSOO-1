/* 
 * Programa:    prog09_06
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Concatena el nombre y los apellidos de una persona.
 */

#include <stdio.h>
#include <string.h>

#define TAM_LINEA   80


int main(void)
{
   char nombre[TAM_LINEA];
   char apellidos[TAM_LINEA];
   char nombreCompleto [TAM_LINEA * 2];

   printf("Introduzca su nombre: \n");
   gets(nombre);

   printf("Introduzca sus apellidos: \n");
   gets(apellidos);
     
   /*
    * Se almacena en nombreCompleto
    * el nombre completo de la persona
    */

   /* inicia nombreCompleto  */
   strcpy(nombreCompleto,"");    

   /* concatena el nombre */
   strcat(nombreCompleto, nombre);

   /* concatena un espacio en blanco */
   strcat(nombreCompleto, " ");

   /* concatena los apellidos */
   strcat(nombreCompleto, apellidos);

   /* se imprime el nombre completo */
   printf("Su nombre es %s\n", nombreCompleto);

   return (0);
}

