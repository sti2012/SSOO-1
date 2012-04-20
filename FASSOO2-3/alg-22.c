#include <stdio.h>
int main()
{
	int suma=0;
	int contador=0;
	int numero;
	printf("Suma y media aritmetica de numeros. (Terminar con 0)\n");
	printf("Escribe un numero: ");
	scanf("%d",&numero);
	if (numero !=0)
	{
		suma=suma+numero;
		do
		{
			printf("Escribe otro numero: ");
			scanf("%d",&numero);
			suma=suma+numero;
			contador++;
			
		}while(numero !=0);
		printf("La suma es %d. La media es %d.\n",suma, suma/contador);
	}
	else printf("No has introducido ningun numero.\n");
	system("pause");
	return 0;
}