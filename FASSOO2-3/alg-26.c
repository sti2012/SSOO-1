#include <stdio.h>

int main()
{
    int a, b, u, v;
    printf ("Introduzca dos numeros para calcular el MCD: ");
    scanf ("%d %d", &a, &b);
    u = a; v = b;
    while (u != v)
    {
    if (u > v) u = u - v;
    else v = v - u;
    }
    printf ("El maximo comun divisor de %d y %d es: %d\n", a, b, u);

    system("pause");
    return 0;
}