/*
*ejemplo3_13.c
*/

#include <stdio.h>

int main()
{
    int suma=0, i;
    for (i=0; i<101; i++)
    {
        suma+=i;
    }
    printf("La suma de los 100 primeros números naturales es: %d\n",suma);
    system("pause");
}
