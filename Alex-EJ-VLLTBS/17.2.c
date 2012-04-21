/*
	Ejercicio 17.2  (frecuencias.c)
	Realizar un programa que lea notas como valores enteros de 1 a 10 hasta
	que el usuario desee finalizar y muestre entonces cuántas veces se ha
	introducido cada valor de notas (1,2,3...10).
*/

#include <stdio.h>

int main()
{
	int i=0;
	int nota;
	int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0;
	printf("Inserta notas del 1 al 10. Escribe 0 para terminar.\n");
	do
	{
		scanf("%d", &nota);
		switch(nota)
		{
			case 0: break;
			case 1: n1++; break;
			case 2: n2++; break;
			case 3: n3++; break;
			case 4: n4++; break;
			case 5: n5++; break;
			case 6: n6++; break;
			case 7: n7++; break;
			case 8: n8++; break;
			case 9: n9++; break;
			case 10: n10++; break;
			default: printf("Inserta un numero del 1 al 10.\n"); break;
		}
		i++;
	}while(nota != 0);
	printf("Has introducido: 1(%d), 2(%d), 3(%d), 4(%d), 5(%d), 6(%d), 7(%d), 8(%d), 9(%d), 10(%d)\n", n1,n2,n3,n4,n5,n6,n7,n8,n9,n10);
	system("pause");
	return 0;
}