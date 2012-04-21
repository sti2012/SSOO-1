/*
16. Declarar un array llamado conciencia de 100 elementos del tipo char.
inicializalo con el mensaje “No faltaré sin causa justificada a clase”. Realizar
la impresion del mismo de la siguiente forma y durante 3 ciclos:

N
No
No f
No fa
...
*/

#include <stdio.h>

int main()
{
	int c=0,contador=0, max=1;
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
		{
			c++;
			max=0;
		}
	}while(c<3);

	system("pause");
	return 0;
}