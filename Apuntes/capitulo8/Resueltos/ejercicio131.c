/*
*ejemplox_131.c
*/
#include <stdio.h>
#include <stdlib.h>

void pasoParametros(int *pun, int val);

int main()
{
    int i=0, j=0;
    
    printf("Diferencia entre paso por puntero y por valor:\n");
    printf("Suma 100 a dos parametros, uno pasado por valor y otro por puntero,\n");
    printf("y cuyo valor inicial es 0:\n");
    pasoParametros(&i, j);
    printf("PASO POR PUNTERO: el valor tras sumar 100 es %d.\n", i);
    printf("PASO POR VALOR: el valor tras sumar 100 es %d.\n", j);
    printf("Comprobamos que el paso por puntero modifica el parametro,\n");
    printf("por contra, el paso por valor modifica una copia local\n");
    printf("del parametro dentro de la funcion.\n");

    system("PAUSE");	
    return 0;
}
 

void pasoParametros(int *pun, int val)
{
    *pun += 100;
    printf("El valor local del parametro pasado por PUNTERO es %d.\n", *pun);
    val += 100;
    printf("El valor local del parametro pasado por VALOR es %d.\n", val);
}
