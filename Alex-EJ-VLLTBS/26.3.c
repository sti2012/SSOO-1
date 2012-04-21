/* EJERCICIO 26.3  (reverseString.c)
   Escribe una funci�n recursiva para leer caracteres por teclado y que los 
   imprima en orden inverso al que se introdujeron. No utilices arrays. Se 
   imprime y termina cuando se introduzca un espacio en blanco o un salto de
   l�nea. 
   
   Utiliza la funci�n:  char getche(); para leer caracteres (devuelve
   el car�cter le�do y no es necesario introducir salto de l�nea con cada 
   caractercomo en la funci�n scanf().
   */

#include <stdio.h>
#include <ctype.h>
/*  PROGRAMA 26: RECURSIVIDAD
    Algunos lenguajes de programaci�n permiten que una funci�n se llame a s�
    misma. Esta t�cnica se denomina recursividad y permite solucionar ciertos
    problemas en programaci�n.
    
    Como ejemplo t�pico veremos el caso del c�lculo del factorial. La funci�n
    (matem�tica) factorial es: n! = n*(n-1)*(n-2)...*1.
    Podemos decir que la funci�n factorial es:
            1! = 1
            n! = n*(n-1)!
    As�, si tenemos que calcular el factorial de 10, podemos decir que:
         10! = 10* 9!
    Y, para calcular el factorial de 9: 9! = 9*8!
    As� sucesivamente, hasta llegar a el factorial de 1 que, por definici�n,
    es uno. 
    Si tenemos una funci�n que calcula el factorial, podemos escribir:
               factorial (10) = 10*factorial(9) = 10*9*factorial(8) = ...
    
    En este programa calcularemos el factorial utilizando recursividad. Ya vimos
    que el factorial se puede calcular mediante  iteraciones y, de hecho, de 
    esta forma es m�s eficiente que utilizando recursividad.
    
    Es muy IMPORTANTE que las funciones recursivas tengan una condici�n que haga
    que un momento dado, deje de llamarse a s� misma y retorne. Si se llaman
    continuamente a s� mismas, el programa adem�s de no terminar, terminar�a
    "rompi�ndose" por consumir todo el espacio disponible en la pila (la 
    direcci�n de retorno y los par�metros pasados a una funci�n se almacenan en
    la pila y se liberan cuando retornamos de la funci�n. Si nunca retornamos...
    este espacio no se libera).

 */
void imprimeLinea(int linea);
int factorial(int n);

void imprimeLinea(linea)
{
   printf("* %d\n", linea);/* imprime '*', valor de linea y un salto de l�nea */
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
/* Forma equivalente de escribir la funci�n factorial:
int factorial(int num)
{
    int resul; ��esta variable es diferente en cada llamada a la funci�n !!
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