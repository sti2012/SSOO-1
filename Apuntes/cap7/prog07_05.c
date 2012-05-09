/*
 * Programa:    prog_07_05
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
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

    printf("Introduca el primer número: ");
    scanf("%d", &x);

    printf("Introduca el segundo número: ");
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

