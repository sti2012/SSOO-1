// No compila.

#include <stdio.h>
#include <string.h>

int main()
{
	int i=0;
	char cad[];
	char cadinv[];
	int lenght, mitad;

	printf("Detector de palindromos.\nIntroduce una palabra: ");
//	scanf("%c", &cad);
	gets(cad);
	lenght = strlen(cad);
	mitad = lenght/2;
	for(; i<mitad; i++)
	{
		cadinv[i] = cad[lenght-i];
	}
//	printf("%s %s\n", cadinv, cad);
	if(cad = cadinv)
		printf("Si es un palindromo\n");
	else 
		printf("No es un palindromo\n");

	system("pause");
	return 0;
}