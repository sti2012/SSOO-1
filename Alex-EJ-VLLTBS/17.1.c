/*
	Ejercicio 17.1  (estadisticaEdad.c)
	Escribe un programa que pida al usuario 10 valores de edades.
	El programa mostrará entonces un listado con las edades introducidas y
	a continuación la edad media, la edad más alta y la más baja de todas.
*/

#include <stdio.h>

int main()
{
	int max,min,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10;

	printf("Escribe 10 valores de edades\n");
	printf("Edad 1: ");
	scanf("%d", &e1);
	max=min=e1;
	printf("Edad 2: ");
	scanf("%d", &e2);
	if (e2>max)
		max=e2;
	else if (e2<min)
		min=e2;
	printf("Edad 3: ");
	scanf("%d", &e3);
	if (e3>max)
		max=e3;
	else if (e3<min)
		min=e3;
	printf("Edad 4: ");
	scanf("%d", &e4);
	if (e4>max)
		max=e4;
	else if (e4<min)
		min=e4;
	printf("Edad 5: ");
	scanf("%d", &e5);
	if (e5>max)
		max=e5;
	else if (e5<min)
		min=e5;
	printf("Edad 6: ");
	scanf("%d", &e6);
	if (e6>max)
		max=e6;
	else if (e6<min)
		min=e6;
	printf("Edad 7: ");
	scanf("%d", &e7);
	if (e7>max)
		max=e7;
	else if (e7<min)
		min=e7;
	printf("Edad 8: ");
	scanf("%d", &e8);
	if (e8>max)
		max=e8;
	else if (e8<min)
		min=e8;
	printf("Edad 9: ");
	scanf("%d", &e9);
	if (e9>max)
		max=e9;
	else if (e9<min)
		min=e9;
	printf("Edad 10: ");
	scanf("%d", &e10);
	if (e10>max)
		max=e10;
	else if (e10<min)
		min=e10;

	printf("\nHas introducido: %d %d %d %d %d %d %d %d %d %d\n", e1,e2,e3,e4,e5,e6,e7,e8,e9,e10);
	printf("La edad media es: %d\n", (e1+e2+e3+e4+e5+e6+e7+e8+e9+e10)/10);
	printf("La edad mas alta es: %d\n", max);
	printf("La edad mas baja es: %d\n", min);

	system("pause");
	return 0;
}