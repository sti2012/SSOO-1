/*
 * Programa:    prog_07_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
 *              Programa que lee dos números y devuelve el maximo 
 */
#include <stdio.h>

/*
 * Declaración de las función del programa.
 * Prototipos de las función
 */
float leerNumero(void);
float maximo(float a, float b); 

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

/*
 * Función leerNumero
 * Solicita al usuario un número
 */
float leerNumero(void)
{
    float n;

    printf("Introduzca un n: ");
    scanf("%f", &n);
    return (n) ;
}


/*
 * Función maximo
 * Definición de la función
 */
float maximo(float a, float b) 
{
    float max;

    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    return(max); /* devuelve el valor máximo */
}

