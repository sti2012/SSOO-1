/*
 * Programa:    prog_07_05
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que emula una calculadora
 */
#include <stdio.h>

void calcular(int a, int b, int *s, int *r, int *p, int *d)
{
    *s = a + b;
    *r = a - b;
    *p = a * b;
    *d = a / b;

    return;
}

int main(void)
{
    int x, y;
    int suma, resta, producto, division;

    printf("Introduca el primer n�mero: ");
    scanf("%d", &x);

    printf("Introduca el segundo n�mero: ");
    scanf("%d", &y);

    if (y == 0) {
        printf("Error, no se puede dividir por cero\n");
        return(-1);
    }
    else {
        calcular(x, y, &suma, &resta, &producto, &division);
        
        printf("La suma es = %d\n", suma);
        printf("La resta es = %d\n", resta);
        printf("El producto es = %d\n", producto);
        printf("La division es = %d\n", division);
    }
    return(0);
}

