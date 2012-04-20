/* EJERCICIO 22.1.  (sizeOfDatos.c)
     Calcula el tamaño de los tipos de datos float, double y de un array de
     enteros. Comprueba que el tamaño del array es igual a:
      (num_elementos * tamaño_elemento).

 */

 #include <stdio.h>
/*  PROGRAMA 22: CÁLCULO DEL TAMAÑO (ESPACIO RESERVADO EN MEMORIA) DE LOS
    TIPOS DE DATOS: operador sizeof()

    Cuando declaramos una variable, el compilador reserva un espacio en memoria
    para dicha variable. El número de bytes reservados dependerá del tipo de
    datos. Además, para un mismo tipo de datos el espacio reservado puede variar
    con la plataforma utilizada (hardware y sistema operativo utilizado). Así,
    un entero puede ocupar 16, 32 ó 64 bits según el sistema en el que estemos
    desarrollando nuestro programa.

    El operador de tamaño sizeof devuelve la longitud en BYTES del operando,
    que puede ser una variable o un especificador de tipo.

 */


int main()
{
   char letras[20]="Hola";
   int dni;
   char c;

   int longitud;

   longitud = sizeof(char);
   printf("La longitud de un caracter es: %d \n", longitud);

   longitud = sizeof(c);
   printf("La longitud de un caracter es: %d \n", longitud);

   longitud = sizeof(int);
   printf("La longitud de un entero es: %d \n", longitud);

   longitud = sizeof(letras);
   printf("La longitud del array letras es: %d \n", longitud);
   /* Atención: la longitud de un array es su capacidad total,
      no el número de elementos que contenga */

   system("PAUSE");
   return 0;
}