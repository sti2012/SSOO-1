/*
*ejemplox_132.c
*/
#include <stdio.h>
#include <stdlib.h>

void sinPunteros(int num1, int num2);
void conPunteros(int *num1, int *num2);

int main()
{
    int i=100, j=200;
    
    printf("Inicialmente numero1=%d y numero2=%d\n", i, j);
    sinPunteros(i, j);
    printf("Tras sinPunteros ahora valen numero1=%d y numero2=%d\n", i, j);
    conPunteros(&i, &j);
    printf("Tras conPunteros ahora valen numero1=%d y numero2=%d\n", i, j);

    system("PAUSE");	
    return 0;
}
 

void sinPunteros(int num1, int num2)
{
    printf("En este caso paso los parametros SIN punteros y los sumo\n");
    printf("NO se debe modificar el valor del parametro\n");
    num1 += num2;
}

void conPunteros(int *num1, int *num2)
{
    printf("En este caso paso los parametros CON punteros y los sumo\n");
    printf("El valor del parametro debe quedar modificado\n");
    *num1 += *num2;
}
