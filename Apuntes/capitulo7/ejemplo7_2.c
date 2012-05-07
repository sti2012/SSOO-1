//ejemplo7_2.c
#include <stdio.h>
#include <stdlib.h>

struct Estructura{
    char    letra;
    long    entero;
    float   real;
    char    cadena1[256];
    char    *cadena2;
};

int main (){
    struct Estructura estructura1 = {'a', 23L, 4.5, "Hola", "Estructura"};
    struct Estructura estructura2;
    struct Estructura estructura3;

    estructura2 = estructura1;
    estructura3.letra = 'b';
    estructura3.entero = 2345L;
    estructura3.real = 234.678;
    strcpy(estructura3.cadena1, "Cadena1");
    estructura3.cadena2 = (char *) malloc(128 * sizeof(char));
    strcpy(estructura3.cadena2, "Cadena2");
    printf("%c\n", estructura3.letra );
    printf("%d\n", estructura3.entero );
    printf("%f\n", estructura3.real );
    printf("%s\n", estructura3.cadena1 );
    printf("%s\n", estructura3.cadena2 );
    free (estructura3.cadena2);
    system("pause");
    return 0;
}
