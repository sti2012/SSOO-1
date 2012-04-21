// Mal pero funciona.
// No da el resultado correcto. Puede ser fallo en conversion a radianes o que sea float en vez de double.

/* Ejercicio 15.2.  (trigonometria.c)
      Las funciones para calcular el seno y coseno de un ángulo son las
      siguientes:
          double sin(double arg);
          double cos(double arg);
        el parámetro arg debe estar en radianes.
      Hacer un programa que pregunte al usuario el valor de un ángulo en grados,
      y muestre por pantalla el valor de su seno y de su coseno.
*/

#include <math.h>
#include <stdio.h>

int main()
{
   float arg;
   float seno, coseno;
   printf("Escribe un angulo en grados: ");
   scanf("%f", &arg);
   seno = sin(arg);
   coseno = cos(arg);
   printf("Su coseno es %f\nSu seno es %f\n", seno, coseno);
   system("pause");
   //return 0;
}


/*
int main()
{
   double arg;
   double seno, coseno;
   printf("Escribe un angulo en grados: ");
   scanf("%lf", &arg);
   seno = sin(arg);
   coseno = cos(arg);
   printf("Su coseno es %lf\nSu seno es %lf\n", seno, coseno);
   system("pause");
   //return 0;
}
*/