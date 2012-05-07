/*
*ejemplo3_14.c
*/

#include <stdio.h>

int main()
{
    int N, sumaPares=0, sumaImpares=0, i;

    // Solicitar N
    printf("Este programa calcula la suma de los números\n"
           "pares hasta N y de los impares hasta N\n\n");
    do
    {
        printf("Introduzca N (N>0): ");
        scanf(" %d",&N);
    }
    while (N<=0);

    // Calcular las sumas
    for (i=0; i<=N; i++)
    {
        if (i%2==0) sumaPares+=i;
        else        sumaImpares+=i;
    }

    // Mostrar resultados
    printf("La suma de todos los números   pares de 0 a %d "
           "es %d\n",N,sumaPares);
    printf("La suma de todos los números impares de 0 a %d "
           "es %d\n",N,sumaImpares);
    system("pause");
}
