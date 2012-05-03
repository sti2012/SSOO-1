/*
	Array que nos lo muestre hacia delante y hacia detras
*/
#include <stdio.h>
#include <string.h>
int main()
{
	char saludo[20];
	int lenght;
	char *psaludo = &saludo[0];
	printf("Dime tu saludo: ");
	fgets(saludo, 20, stdin);
	lenght = strlen(saludo);
	printf("La cadena tiene %d caracteres\n",lenght);

	//psaludo = &saludo[strlen(saludo)];

	for (lenght; lenght>=0; lenght--)
	{
		printf("%c", *(psaludo+lenght));
	}

	psaludo = &saludo[lenght]-1;
	lenght = strlen(saludo);
	printf("\n");

	while(lenght != 0)
	{
		printf("%c", *(psaludo+lenght));
		lenght--;
	}

	lenght = strlen(saludo);
	psaludo = &saludo[lenght]-1;
	printf("\n");
	
	while(lenght != 0)
	{
		printf("%c", *psaludo);
		psaludo--;
		lenght--;
	}


	return 0;
 }



