/* 
 * Programa:    prog09_05
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Lectura de una cadena car�cter a car�cter.
 */

#include <stdio.h>

#define TAM_LINEA   80


int main(void)
{
   char linea[TAM_LINEA];
   char ch;
   int i;

   printf("Introduzca una l�nea: \n");
   i  = 0;
   ch = getchar();
   while ( (ch != EOF) && (i < TAM_LINEA-1) )
   {
      linea[i] = ch;
      i++;
      ch = getchar();
   }
   linea[i]='\0';

   printf("Se ha le�do la nota: %s\n", linea);
   return (0);
}

