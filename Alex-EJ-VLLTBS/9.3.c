/*
	Ejercicio 9.3:
	Calcular, utilizando la sentencia for() el factorial de 5.
*/

#include <stdio.h>
#include <stdlib.h>

#define FACTORIAL 5

int main()
{
    int m=FACTORIAL;
    int n=FACTORIAL;

    for (m; m > 1; m--)
    {
        n = n*(m-1);
    }
    printf("%d! = %d\n", FACTORIAL, n);

    system("pause");
    return 0;
}