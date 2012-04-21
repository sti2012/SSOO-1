/* Ejercicio 18.6  (invierteCadena.c)
      Programa que lee una frase y la escribe en orden inverso: del final hasta 
      el principio.
*/

/* Programa 18: ARRAYS DE CARACTERES
(cadenas de caracteres, "strings", vectores de caracteres)
*/

#include<stdio.h>

/* Recordar:
  Declaración de un array:
  tipo nombre[tamaño];

  El primer elemento tiene como índice 0; el último, el tamaño - 1.

*/

int main()
{
   /* arrays de caracteres:
      - almacenan caracteres: códigos ASCII (¡números!)
      - las cadenas de caracteres terminan en el carácter especial '\0', que
         tiene el valor numérico 0, que es un código ASCII no válido. Sirve para
         marcar el final de la cadena.
      - las cadenas de caracteres se representan entre comillas dobles:
         "A" es la cadena con el carácter 'A' más el terminador '\0'.
         'A' es un solo carácter.
      - Debe tenerse en cuenta el terminador de la cadena a la hora de reservar
        espacio. Siempre necesitaremos reservar: (longitud de la cadena) + 1
           Ejemplo: "Vaya" -> tamaño array = 4 + 1 = 5 caracteres
      - */

   char mensaje[30];

   /* Inicialización de variables en la declaración:
      puede darse un valor a una variable en el momento de declararla:

         int contador = 0;

      Los arrays también pueden inicializarse de la siguiente forma:

         int numeros[5] = {4, 5, 6, 1, 8};

      Las cadenas de caracteres se pueden inicializar como se muestra a
      continuación:
   */
   char saludo[10]="Hola";   /* No utilizamos todos los caracteres que hemos
                                reservado...*/
   char despedida[]="Adios"; /* Aquí el compilador calcula el tamaño del array*/

   /* Estas asignaciones SOLO pueden hacerse en el momento de declarar la
      variable: después nos daría un ERROR de compilación:
      despedida = "Bye" -> ¡Error! */

   /* Podemos imprimir cadenas de caracteres con la función printf: */
   printf("%s\n", saludo);  /* %s -> String. Solo damos el nombre del array */

   /* Podemos dar valores a cada elemento del array: */
   mensaje[0] = 'S';
   mensaje[1] = 'o';
   mensaje[2] = 'y';
   mensaje[3] = ' ';    /* el caracter blanco es un carácter más */
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
   mensaje[15] = '\0'; /* ¡terminador de cadena! */

   /* ¿Debemos dar valores al resto de los elementos del array?
       No es necesario: no importa qué valores tengan, ya que hemos
       marcado el final de la cadena y solo hasta ahí leeremos los
       caracteres almacenados.
   */

   /* imprimimos el mensaje */
   printf("%s\n", mensaje);

   /* también se pueden leer cadenas de caracteres con la función scanf, aunque
      esta función considera el espacio en blanco como un separador de cadenas
      y no lo asignaría a la variable */
   printf("Escribe un mensaje: ");
   scanf("%s", mensaje);  /* Nota: con los nombres de los arrays no hace falta
                             el símbolo '&' delante */

   printf("%s\n", mensaje);
   printf("%s\n", despedida);

   /* Supongamos que queremos que la variable mensaje almacene lo que
      contiene la variable despedida. Es decir, queremos copiar la cadena
      despedida en la cadena mensaje. La siguiente línea es INCORRECTA:
          mensaje = despedida;
      Deberíamos copiar uno a uno los elementos del array:
      mensaje[0] = despedida[0];
      mensaje[1] = despedida[1];
      ...sin olvidar el terminador !!

      Más adelante estudiaremos funciones que nos simplifican esta tarea.
   */


   system("pause");

}