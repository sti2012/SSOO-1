#include <stdio.h>
#include <string.h>

int main()
{
	int i=0;
	char cad[100];
	char cadinv[100];
	int lenght;

	printf("Detector de palindromos.\nIntroduce una palabra: ");
	scanf("%s", &cad);
	lenght = strlen(cad)-1;

	for (; i<=lenght; i++)
	{
		cadinv[i] = cad[lenght-i];
		printf("%c | %c\n", cadinv[i], cad[i]);
	}

	if (cad[lenght] == cadinv[lenght])
		printf("\nSi es un palindromo\n");
	else 
		printf("\nNo es un palindromo\n");

	system("pause");
	return 0;
}

/*
int main()
{
	int i=0;
	char cad[100];
	char cadinv[100];
	int lenght;
	// int mitad;

	printf("Detector de palindromos.\nIntroduce una palabra: ");
	scanf("%s", &cad);
	// gets(cad);

	lenght = strlen(cad);
	//mitad = lenght/2;
	for(; i<lenght; i++)
	{
		cadinv[i] = cad[lenght-1-i];
		printf("%c\t-\t%c\n", cadinv[i], cad[i]);
	}

	if(cad[lenght-1] == cadinv[lenght-1])
		printf("Si es un palindromo\n");
	else 
		printf("No es un palindromo\n");

	system("pause");
	return 0;
}
*/