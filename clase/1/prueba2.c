#include <stdio.h>
#include <stdlib.h>

int main()
{
	float base, altura, area;
	printf("Triangulo\n");
	printf("Introduce la base y la altura\n");
	scanf("%f %f",&base,&altura);
	area = (base * altura) / 2;
	printf("El area es %.2f\n",area);
	return 0;
}