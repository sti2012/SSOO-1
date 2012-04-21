// Sin hacer

/* Ejercicio 9.4:
   Programa quinielístico: codificar un programa que calcule todas las
   combinaciones posibles de una quiniela, de forma que se asegure el pleno.
   El programa imprimirá por pantalla todas las combinaciones posibles de
   resultados. Para simplificar, suponer que la quiniela consta de cuatro
   partidos. El programa iría sacando por pantalla los siguientes valores
   (cada línea representa los valores de una columna):
   1 1 1 1
   1 1 1 X
   1 1 1 2
   1 1 x 1
   1 1 x x
   ...
   2 2 2 X
   2 2 2 2

   Nota: ayudarse de la sentencia "if () ... else "
    para imprimir el signo adecuado:
     if (i == 0)
     {
       printf("1")
     }
     else if (i == 1)
     {
        printf("x");
     }
     else...

*/

#include <stdio.h>
#include <stdlib.h>

/* Programa 9:
   Bucles con una nueva estructura de control:
   for(inicialización; condición; in(dec)cremento)
     sentencia;
*/

int main()
   {
    int i;
    int j;
    int k;
    int l;

      for (i = 0; i < 5; i++)
        {for (j = 0; j < 5; j++)
           {for (k = 0; i < 5; k++)
              {for (l = 0; j < 5; l++)
                 {printf("%d,%d,%d,%d \n", i, j, k, l);}
               }}}

      system("pause");
}