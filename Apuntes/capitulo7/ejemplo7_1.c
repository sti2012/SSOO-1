//ejemplo7_1.c
#include <stdio.h>

struct Datos{
    int    entero;
    char   caracter;
    double real;
};

int main (){

    printf("Tamaño de cada miembro:\n");
    printf("---------------------\n");
    printf("sizeof(int)          = %d\n", sizeof(int));
    printf("sizeof(char)         = %d\n", sizeof(char));
    printf("sizeof(double)       = %d\n\n", sizeof(double));
    printf("Tamaño de la estructura:\n");
    printf("---------------------\n");
    printf("sizeof(struct Datos) = %d\n", sizeof(struct Datos));
    printf("\n");
    system("pause");
    return 0;
}
