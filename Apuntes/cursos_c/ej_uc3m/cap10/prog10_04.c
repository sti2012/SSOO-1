/* 
 * Programa:    prog10_04
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripcin:  Ejemplo del Cap�tulo 10:
 *              Disposici�n de los miembros de una estructura.
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

    printf("Tama�o tipos de datos\n");
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
     printf("Disposici�n de los miembros\n");
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

