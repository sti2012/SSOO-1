/* EJERCICIO 21.1  (busquedaBin.c)
   Modifica el programa anterior para que en cada iteraci�n muestre qu� n�mero
   de iteraci�n es, as� como los valores del �ndice izquierdo, central y
   derecho.

*/

/* PROGRAMA 21:
Versi�n modificada de un programa del siguiente tutorial:
http://www.ulpgc.es/otros/tutoriales/mtutor/indice.html
+----------------------------------------+
| BUSQUEDA BINARIA (BUSQUEDA DICOTOMICA) |
+----------------------------------------+

        En este  programa se realiza  una b�squeda binaria  (llamada
tambi�n dicot�mica) en un vector ordenado de n�meros enteros.

        Este  algoritmo  es   v�lido  exclusivamente  para  vectores
ordenados y consiste  en comparar en primer lugar  con la componente
central del vector,  y si no es igual al  valor buscado se reduce el
intervalo  de b�squeda  a la  mitad derecha  o izquierda seg�n donde
pueda  encontrarse el  valor a  buscar. El  algoritmo termina  si se
encuentra el valor buscado o si  el tama�o del intervalo de b�squeda
queda anulado.

        En los casos  en que existan repeticiones en  el vector, del
valor buscado,  este algoritmo obtendr� uno  de ellos aleatoriamente
seg�n  los  lugares  que   ocupen,  los  cuales  necesariamente  son
consecutivos.
*/

#include <stdio.h>  /* printf (), getchar () */
#define LONGITUD 100
void main (void)
{
  int vector [LONGITUD];     /* declaraci�n de un vector de 100
                             elementos int */
  int x,                /* contiene valor a buscar */
  encontrado,           /* variable que s�lo toma dos valores:
                        cierto (1) o falso (0) */
  i, centro, izquierda, derecha; /* �ndices de vector */
  char continuar;

  /*  Relleno de los  100 componentes  del vector:
       A cada componente se le  asigna un valor equivalente
       al  doble del �ndice que  ocupan  en   el  vector.  */

  for (i = 0; i < LONGITUD; i++)
    vector[i] = i * 2;
    
  /* Escritura de la cabecera. */
  printf ("BUSQUEDA BINARIA EN UN VECTOR ORDENADO\n\n");

  /* imprimimos el vector a 10 columnas */
  printf ("\n\nVector:\n");
  for (i = 0; i < LONGITUD; i++)
  {
    printf ("%4d  ", vector[i]);
    if ( ((i+1)%10) == 0)
       printf("\n");
  }


  do
  {  
     printf("\nIntroduce el valor que quieres buscar: ");
     scanf("%d",&x);
     /* B�squeda binaria en vector ordenado. */
     encontrado = 0;
     izquierda = 0;
     derecha = LONGITUD - 1;
     while (! encontrado && izquierda <= derecha)
     {
       centro = (izquierda + derecha) / 2;

       if (x < vector[centro])
            derecha = centro - 1;
       else if (x > vector[centro])
            izquierda = centro + 1;
       else
            encontrado = 1;
     }

     /* Escritura en pantalla del resultado. */
     if (encontrado)
        printf ("\n\nValor %d encontrado en indice %d.\n", x, centro);
     else
        printf ("\n\nNo existe el valor %d en el vector.\n", x);
        
     printf("Desea continuar (S/N): ");
     scanf("\n%c", &continuar);
        
  }while(continuar != 'n' && continuar != 'N');
  /* Espera la pulsaci�n de la tecla RETURN para finalizar el
  programa. */
  system("pause");
}