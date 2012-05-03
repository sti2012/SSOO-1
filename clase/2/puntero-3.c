/*
	Array que nos lo muestre hacia delante y hacia detras
*/
#include <stdio.h>
#include <string.h>
int main()
{
	char array1[10];
	int i = ,lenght;
	char *c = &array1[0];
	printf("Dime tu saludo: ");
	fgets(array1, 10, stdin);
	lenght = strlen(array1);

	for (i = 0; i < lenght; i++)
	{
		printf("%c\t",*(c+i));
	}

	printf("\n");

	for (i = lenght-1; i >= 0; i--)
	{
		printf("%c\t",*(c+i));
	}
	
	return 0;
}