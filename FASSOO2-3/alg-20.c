#include <stdio.h>
int main ()
{
	int A, B, C;
	printf("Dime tres numeros:\n");
	printf("A: ");
	scanf("%d", &A);
	printf("B: ");
	scanf("%d", &B);
	printf("C: ");
	scanf("%d", &C);
	if (A + B == C)
		printf("Se cumple que A+B=C\n");
	else if (A + C == B)
		printf("Se cumple que A+C=B\n");
	else if (B + C == A)
		printf("Se cumple que B+C=A\n");
	else 
		printf("No se cumple ninguna relacion de suma entre esos valores.\n");
	system("pause");
	return 0;
}