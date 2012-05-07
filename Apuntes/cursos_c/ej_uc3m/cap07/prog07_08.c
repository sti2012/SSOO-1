/*
 * Programa:    prog_07_08
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que calcula el maximo con una funci�n inline
 */
#include <stdio.h>

/*
 * Funci�n inline maximo
 */
inline float maximo(float a, float b) 
{
    float max;

    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    return(max); /* devuelve el valor m�ximo */
}

int main(void)
{
    int x, y;
    int mayor;

    printf("Introduzca dos numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);

    /* llamada a la funci�n inline */
    mayor = maximo(x,y);    

    printf("El m�ximo es %d\n", mayor);

    return (0);
}

