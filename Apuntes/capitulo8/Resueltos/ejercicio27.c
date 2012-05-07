/*
*ejemplox_27.c
*/
#include <stdio.h>
#include <stdlib.h>

void calcularEstadisticos (double x1, double x2, double x3, double x4,
   double *media, double *desviacion)
{
    double suma = x1 + x2 + x3 + x4;
    double suma2= x1*x1+x2*x2+x3*x3+x4*x4;
    *media = suma/4;
    *desviacion = sqrt(suma2/4-(*media)*(*media));
}

int main()
{
  double num1, num2, num3, num4;
  printf("Programa que calcula la media y la desviaci�n est�ndar de 4\n"
         "n�meros reales\n"
         "Introduzca los 4 n�meros:\n");
  scanf(" %lf %lf %lf %lf",&num1,&num2,&num3,&num4);
  double media, desviacion;
  calcularEstadisticos(num1, num2, num3, num4, &media, &desviacion);
  
  printf("El valor medio de los n�meros introducidos es: %f\n",media);
  printf("y su desvaci�n est�ndar es: %f\n",desviacion);
  
  system("PAUSE");	
}
