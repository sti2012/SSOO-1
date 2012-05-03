#include <stdio.h>

int main()
{
	int numeros[10];
	int pos=0,neg=0,cero=0;
	printf("Escribe 10 numeros:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d. ___\b\b\b", i+1);
		scanf("%d", &numeros[i]);
		if (numeros[i] > 0)
		{
			pos = pos + 1;
		}
		else if (numeros[i] < 0)
		{
			neg = neg + 1;
		}
		else if (numeros[i] == 0)
		{
			cero = cero + 1;
		}
		else printf("Error!\n");
	}
	printf("Hay %d positivos, %d negativos y %d ceros\n", pos,neg,cero);
	return 0;
}