#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c;
	float x1, x2, discr;
	printf("Vamos a calcular la ecuacion de segundo grado Ax^2 + Bx + C\n\n");
	printf("Dame el valor de A: ");
	scanf("%f", &a);
	printf("Dame el valor B: ");
	scanf("%f", &b);
	printf("Dame el valor C: ");
	scanf("%f", &c);
	discr = b*b-4.0*a*c;
	if (discr>=0.0)
	{
		x1 = (-b+sqrt(discr))/(2.0*a);
		x2 = (-b-sqrt(discr))/(2.0*a);
		printf("\nSoluciones: %f y %f\n", x1, x2);
	}
	else
	printf("\nNo existe solucion real.\n");
	system("pause");
	return 0;
}