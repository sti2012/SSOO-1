/*
 * Programa:    prog_07_08
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
 *              Programa que calcula el maximo con una función inline
 */
#include <stdio.h>

/*
 * Función inline maximo
 */
inline float maximo(float a, float b) 
{
    float max;

    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    return(max); /* devuelve el valor máximo */
}

int main(void)
{
    int x, y;
    int mayor;

    printf("Introduzca dos numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);

    /* llamada a la función inline */
    mayor = maximo(x,y);    

    printf("El máximo es %d\n", mayor);

    return (0);
}

