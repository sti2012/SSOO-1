/*
 * Programa:    prog_04_08
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
 *              Programa que muestra errores en el uso de los operadores
 */
#include <stdio.h>

int main(void)
{
    int       a;
    int       b;
    int       c;
    unsigned  d;
    float     n;
    short     iguales;

    /*
     * Cálculo de 0.5
     */
    n = 1/2;
    printf("1/2 es = %f\n", n);
    
    /*
     * Cálculo de la media de 40 y 70
     */
    n = 40 + 80 / 2; 
    printf("Media de 40 y 80 = %f\n", n);

    /*
     * Asignar un valor negativo a una variable sin signo
     */
    a = -1000;
    d = a;
    printf("d(unsigned) = %u\n", a);

    /* 
     * Uso del operador condicional para saber si dos 
     * variables tienen el mismo valor 
     * Se usa el operador = en lugar de ==
     */
    iguales = (a = b) ?  1 : 0;
    iguales == 1 ? printf("a es igual a b \n") :
	    	   printf("a es distinto a b\n");

    /*
     * Calcular el AND binario entre a y b
     * utilizando && en lugar del operador binario &
     */
    a = 8000;
    b = 4050;
    c = a && b;
    printf("%d AND %d = %d\n", a, b, c);
    
    return (0);
	
}


