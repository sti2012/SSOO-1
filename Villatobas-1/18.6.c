/* Ejercicio 18.6  (invierteCadena.c)
      Programa que lee una frase y la escribe en orden inverso: del final hasta 
      el principio.
*/

/* Programa 18: ARRAYS DE CARACTERES
(cadenas de caracteres, "strings", vectores de caracteres)
*/

#include<stdio.h>

/* Recordar:
  Declaraci�n de un array:
  tipo nombre[tama�o];

  El primer elemento tiene como �ndice 0; el �ltimo, el tama�o - 1.

*/

int main()
{
   /* arrays de caracteres:
      - almacenan caracteres: c�digos ASCII (�n�meros!)
      - las cadenas de caracteres terminan en el car�cter especial '\0', que
         tiene el valor num�rico 0, que es un c�digo ASCII no v�lido. Sirve para
         marcar el final de la cadena.
      - las cadenas de caracteres se representan entre comillas dobles:
         "A" es la cadena con el car�cter 'A' m�s el terminador '\0'.
         'A' es un solo car�cter.
      - Debe tenerse en cuenta el terminador de la cadena a la hora de reservar
        espacio. Siempre necesitaremos reservar: (longitud de la cadena) + 1
           Ejemplo: "Vaya" -> tama�o array = 4 + 1 = 5 caracteres
      - */

   char mensaje[30];

   /* Inicializaci�n de variables en la declaraci�n:
      puede darse un valor a una variable en el momento de declararla:

         int contador = 0;

      Los arrays tambi�n pueden inicializarse de la siguiente forma:

         int numeros[5] = {4, 5, 6, 1, 8};

      Las cadenas de caracteres se pueden inicializar como se muestra a
      continuaci�n:
   */
   char saludo[10]="Hola";   /* No utilizamos todos los caracteres que hemos
                                reservado...*/
   char despedida[]="Adios"; /* Aqu� el compilador calcula el tama�o del array*/

   /* Estas asignaciones SOLO pueden hacerse en el momento de declarar la
      variable: despu�s nos dar�a un ERROR de compilaci�n:
      despedida = "Bye" -> �Error! */

   /* Podemos imprimir cadenas de caracteres con la funci�n printf: */
   printf("%s\n", saludo);  /* %s -> String. Solo damos el nombre del array */

   /* Podemos dar valores a cada elemento del array: */
   mensaje[0] = 'S';
   mensaje[1] = 'o';
   mensaje[2] = 'y';
   mensaje[3] = ' ';    /* el caracter blanco es un car�cter m�s */
   mensaje[4] = 'p';
   mensaje[5] = 'r';
   mensaje[6] = 'o';
   mensaje[7] = 'g';
   mensaje[8] = 'r';
   mensaje[9] = 'a';
   mensaje[10] = 'm';
   mensaje[11] = 'a';
   mensaje[12] = 'd';
   mensaje[13] = 'o';
   mensaje[14] = 'r';
   mensaje[15] = '\0'; /* �terminador de cadena! */

   /* �Debemos dar valores al resto de los elementos del array?
       No es necesario: no importa qu� valores tengan, ya que hemos
       marcado el final de la cadena y solo hasta ah� leeremos los
       caracteres almacenados.
   */

   /* imprimimos el mensaje */
   printf("%s\n", mensaje);

   /* tambi�n se pueden leer cadenas de caracteres con la funci�n scanf, aunque
      esta funci�n considera el espacio en blanco como un separador de cadenas
      y no lo asignar�a a la variable */
   printf("Escribe un mensaje: ");
   scanf("%s", mensaje);  /* Nota: con los nombres de los arrays no hace falta
                             el s�mbolo '&' delante */

   printf("%s\n", mensaje);
   printf("%s\n", despedida);

   /* Supongamos que queremos que la variable mensaje almacene lo que
      contiene la variable despedida. Es decir, queremos copiar la cadena
      despedida en la cadena mensaje. La siguiente l�nea es INCORRECTA:
          mensaje = despedida;
      Deber�amos copiar uno a uno los elementos del array:
      mensaje[0] = despedida[0];
      mensaje[1] = despedida[1];
      ...sin olvidar el terminador !!

      M�s adelante estudiaremos funciones que nos simplifican esta tarea.
   */


   system("pause");

}