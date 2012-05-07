/* 
 * Programa:    prog10_04
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripcin:  Ejemplo del Capítulo 10:
 *              Disposición de los miembros de una estructura.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


struct Datos
{
    int    entero;
    char   caracter;
    double real;
};

int main(void)
{

    printf("Tamaño tipos de datos\n");
    printf("---------------------\n");
    printf("sizeof(int)          = %d\n", sizeof(int));
    printf("sizeof(char)         = %d\n", sizeof(char));
    printf("sizeof(double)       = %d\n", sizeof(double));
    printf("sizeof(struct Datos) = %d\n",
                sizeof(struct Datos));
    printf("\n");

    /*
     *  Se imprime el desplazamiento dentro de la estructura
     */
     printf("Disposición de los miembros\n");
     printf("---------------------------\n");
     printf("offsetof(dato.entero)      = %d\n",
                offsetof(struct Datos, entero));
     printf("offsetof(dato.caracter)     = %d\n",
                offsetof(struct Datos, caracter));
     printf("offsetof(dato.real) = %d\n",
                offsetof(struct Datos, real));
     printf("\n");

     return (0) ;
}

