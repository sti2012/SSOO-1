/* 
 * Programa:    prog10_02
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripcin:  Ejemplo del Capítulo 10:
 *              Almacenamiento de los valores en una estructura.
 */


#include <stdio.h>
#include <stdlib.h>

struct Ejemplo 
{
    char    letra;
    long    entero;
    float   real;
    char    string1[256];
    char    *string2;
};

struct Ejemplo  ejemplo1;
struct Ejemplo  ejemplo2;

int main(void)
{
    /*
     *      * definición e iniciación de la estructura ejemplo1
     *           */
    struct Ejemplo ejemplo1 = {'a', 23L, 4.5, "Hola", "Estructura"};
    struct Ejemplo ejemplo2;
    struct Ejemplo ejemplo3;
    /* 
     *      * Copia en ejemplo2, ejemplo1
     *           */
     ejemplo2 = ejemplo1;

    /*
     *      * Se asignan valores inidividuales a los miembros de ejemplo3
     *           */
    ejemplo3.letra = 'b';
    ejemplo3.entero = 2345L;
    ejemplo3.real = 234.678;
    strcpy(ejemplo3.string1, "Cadena de ejemplo 1");
    ejemplo3.string2 = (char *) malloc(128 * sizeof(char));
    strcpy(ejemplo3.string2, "Cadena de ejemplo 2");

    printf("%c\n", ejemplo3.letra );
    printf("%ld\n", ejemplo3.entero );
    printf("%f\n", ejemplo3.real );
    printf("%s\n", ejemplo3.string1 );
    printf("%s\n", ejemplo3.string2 );


    return (0);
}

