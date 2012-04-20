#include <stdio.h>
int main()
{
	int a, b, c, d;
	int mayor;
	printf("Introduce 4 numeros: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	mayor = a;
	if (b > mayor)
	{
		mayor = b;
	}
	else if (c > mayor)
	{
		mayor = c;
	}	
	else if (d > mayor)
	{
		mayor = d;
	}
	else ;
	printf("El numero mayor es %d\n", mayor);
	system("pause");
	return 0;
}