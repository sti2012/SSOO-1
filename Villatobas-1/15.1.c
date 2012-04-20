// Funciona, pero
// No se como incluir un #define en printf.

/* Ejercicio 15.1.  (hipotenusa.c)
      La función hypot tiene el siguiente prototipo:
      double hypot(double x, double y);
      y devuelve la longitud de la hipotenusa de un triángulo rectángulo cuando
      se le pasan como parámetros las longitudes de los catetos.
      Haz un programa que calcule el valor de la hipotenusa para los
      valores de los catetos: (3,4), (7.1, 1) y (5,5).
*/

#include <math.h>
#include <stdio.h>

/*
#define CATETOS1 '(3 , 4)'
#define CATETOS2 '(7.1 , 1)'
#define CATETOS3 '(5 , 5)'
*/

double hypot(double x, double y)
{
   double resultado;
   double xx, yy;
   double exp2 = 2;
   xx = pow(x, exp2);
   yy = pow(y, exp2);
   double zz = xx + yy;
   resultado = sqrt(zz);

   //resultado = double sqrt(double pow(x,2) + double pow(y,2));
   return resultado;

//double pow(double base, double exp);
//double sqrt(double num);

}

int main()
{
   double result1, result2, result3;
   double x1 = 3;
   double y1 = 4;
   double x2 = 7.1;
   double y2 = 1;
   double x3 = 5;
   double y3 = 5;
   result1 = hypot(x1, y1);
   result2 = hypot(x2, y2);
   result3 = hypot(x3, y3);
   printf("La hipotenusa de un cateto de lados (%.1lf , %.1lf) es %lf\n", x1, y1, result1);
   printf("La hipotenusa de un cateto de lados (%.1lf , %.1lf) es %lf\n", x2, y2, result2);
   printf("La hipotenusa de un cateto de lados (%.1lf , %.1lf) es %lf\n", x3, y3, result3);
   return 0;
}