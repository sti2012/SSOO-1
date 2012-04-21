/* EJERCICIO 22.1.  (sizeOfDatos.c)
     Calcula el tama�o de los tipos de datos float, double y de un array de
     enteros. Comprueba que el tama�o del array es igual a:
      (num_elementos * tama�o_elemento).

 */

 #include <stdio.h>
/*  PROGRAMA 22: C�LCULO DEL TAMA�O (ESPACIO RESERVADO EN MEMORIA) DE LOS
    TIPOS DE DATOS: operador sizeof()

    Cuando declaramos una variable, el compilador reserva un espacio en memoria
    para dicha variable. El n�mero de bytes reservados depender� del tipo de
    datos. Adem�s, para un mismo tipo de datos el espacio reservado puede variar
    con la plataforma utilizada (hardware y sistema operativo utilizado). As�,
    un entero puede ocupar 16, 32 � 64 bits seg�n el sistema en el que estemos
    desarrollando nuestro programa.

    El operador de tama�o sizeof devuelve la longitud en BYTES del operando,
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
   /* Atenci�n: la longitud de un array es su capacidad total,
      no el n�mero de elementos que contenga */

   system("PAUSE");
   return 0;
}