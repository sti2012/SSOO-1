/*
 * Programa:    prog_07_01
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que lee dos n�meros y devuelve el maximo
 */
#include <stdio.h>

/*
 * Funci�n leerNumero
 * Solicita al usuario un n�mero
 */
float leerNumero(void)
{
    float n;

    printf("Introduzca un n: ");
    scanf("%f", &n);
    return (n) ;
}

/*
 * Funci�n maximo
 * Devuelve el m�ximo de a y b.
 */
float maximo(float a, float b) 
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
    float x, y;
    float mayor;

    x = leerNumero();
    y = leerNumero();

    /* llamada a la funcion */
    mayor = maximo(x,y);    
    printf("El maximo es %f\n", mayor);

    return (0);
}
