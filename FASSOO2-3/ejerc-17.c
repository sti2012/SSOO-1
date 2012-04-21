/*
16. Declarar un array llamado conciencia de 100 elementos del tipo char.
inicializalo con el mensaje “No faltaré sin causa justificada a clase”. Realizar
la impresion del mismo continuamente y de la siguiente forma:

N
No
No f
No fa
...
*/

#include <stdio.h>

int main()
{
	int contador=0, max=1;
	char conciencia[100] = {"No faltare sin causa justificada a clase"};
//	char conciencia[100];
//	printf("Escribe una frase\n");
//	fgets(conciencia,100,stdin);
	int lenght= strlen(conciencia);
	do
	{
		if (max<lenght)
		{
			for (;contador<max;contador++)
			{
				printf("%c",conciencia[contador]);
			}
			max++;
			printf("\n");
			contador=0;
		}
		else
			max=0;
	}while(1);

	system("pause");
	return 0;
}