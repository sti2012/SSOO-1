/* EJERCICIO 26.3  (reverseString.c)
   Escribe una función recursiva para leer caracteres por teclado y que los 
   imprima en orden inverso al que se introdujeron. No utilices arrays. Se 
   imprime y termina cuando se introduzca un espacio en blanco o un salto de
   línea. 
   
   Utiliza la función:  char getche(); para leer caracteres (devuelve
   el carácter leído y no es necesario introducir salto de línea con cada 
   caractercomo en la función scanf().
   */

#include <stdio.h>
#include <ctype.h>
/*  PROGRAMA 26: RECURSIVIDAD
    Algunos lenguajes de programación permiten que una función se llame a sí
    misma. Esta técnica se denomina recursividad y permite solucionar ciertos
    problemas en programación.
    
    Como ejemplo típico veremos el caso del cálculo del factorial. La función
    (matemática) factorial es: n! = n*(n-1)*(n-2)...*1.
    Podemos decir que la función factorial es:
            1! = 1
            n! = n*(n-1)!
    Así, si tenemos que calcular el factorial de 10, podemos decir que:
         10! = 10* 9!
    Y, para calcular el factorial de 9: 9! = 9*8!
    Así sucesivamente, hasta llegar a el factorial de 1 que, por definición,
    es uno. 
    Si tenemos una función que calcula el factorial, podemos escribir:
               factorial (10) = 10*factorial(9) = 10*9*factorial(8) = ...
    
    En este programa calcularemos el factorial utilizando recursividad. Ya vimos
    que el factorial se puede calcular mediante  iteraciones y, de hecho, de 
    esta forma es más eficiente que utilizando recursividad.
    
    Es muy IMPORTANTE que las funciones recursivas tengan una condición que haga
    que un momento dado, deje de llamarse a sí misma y retorne. Si se llaman
    continuamente a sí mismas, el programa además de no terminar, terminaría
    "rompiéndose" por consumir todo el espacio disponible en la pila (la 
    dirección de retorno y los parámetros pasados a una función se almacenan en
    la pila y se liberan cuando retornamos de la función. Si nunca retornamos...
    este espacio no se libera).

 */
void imprimeLinea(int linea);
int factorial(int n);

void imprimeLinea(linea)
{
   printf("* %d\n", linea);/* imprime '*', valor de linea y un salto de línea */
   if ( linea == 1 )
      return;
   else 
      imprimeLinea(linea-1);
    return;
}

int factorial(int num)
{
    if (num <=1)
       return 1;
    else
       return num*factorial(num - 1);
}
/* Forma equivalente de escribir la función factorial:
int factorial(int num)
{
    int resul; ¡¡esta variable es diferente en cada llamada a la función !!
    if (num <=1)
       return 1;
    else
    {
       resul=num*factorial(num - 1);
       return resul;
    }
}
*/

int main()
{
   int resultado, numero;
   imprimeLinea(5);
   
   
   numero = 0;
   resultado=factorial(numero);
   printf("El factorial de %d es %d \n", numero, resultado);
   
   numero = 3;
   resultado=factorial(numero);
   printf("El factorial de %d es %d \n", numero, resultado);
   
   numero = 5;
   resultado=factorial(numero);
   printf("El factorial de %d es %d \n", numero, resultado);
   
   system("PAUSE");
   return 0;
}