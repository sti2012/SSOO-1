/*
*ejemplo3_15.c
*/

#include <stdio.h>

int main()
{
    int nPositivos=0, nNegativos=0, i;
    float suma=0, numero;

    // Leer 20 números y mostrar resultados
    printf("Este programa solicita 20 números y calcula la suma de todos ellos,\n"
           "y la cantidad de números positivos y negativos\n\n");
    for (i=0; i<20; ++i)
    {
        printf("Introduzca el número %d: ",i);
        scanf(" %f",&numero);
        if (numero<0) ++nNegativos;
        else          ++nPositivos;
        suma+=numero;
    }

    // Mostrar resultados
    printf("Hay %d número negativos y %d números positivos\n",
           nNegativos,nPositivos);
    printf("La suma de todos los números es %f\n",suma);
    system("pause");
}
