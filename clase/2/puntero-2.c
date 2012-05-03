#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char saludo[20];
	int x=0,lenght;
	char *c=&saludo[0];

	printf("SALUDAME\n");
	//scanf("%[^\n]", &saludo);
	fgets(saludo,20,stdin);
	printf("%s\n", saludo);
	lenght = strlen(saludo);
	for (x = 0; x < lenght; ++x)
	{
		//*c=&saludo[x];
		printf("%p\n", *c+x);
	}
	return 0;
}
