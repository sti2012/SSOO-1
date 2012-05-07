//ejemplo2_6.c
#include "stdio.h"

int main (){
    char caracter = 'a'; //variable tipo carácter
    char caracter2 = 98; //inicializado mediante un número
    int entero = -5; //variable tipo int
    int octal = 075; //expresada en base octal
    int hexadecimal = 0x7fffffff; //expresada en hexadecimal
    /*el entero anterior en binario sería un cero seguido de
    31 1s, es por tanto el mayor entero (int) representable en C*/
    const int constante = 8;
    //constante = 10; error de compilación puesto que se está
    //modificando una variable constante
    long enteroLargo = 5L; //variable tipo long
    unsigned short enteroCortoSinSigno = 5;//variable de tipo usigned short
    float real = 5.0F; //variable de tipo float
    double realLargo = 5.5; //variable de tipo double

    printf("Carácter%c\n", caracter);
    printf("Valor entero del carácter %d\n", caracter);
    printf("Valor entero del segundo carácter %d\n", caracter2);
    printf("Su carácter correspondiente %c\n", caracter2);
    printf("Entero %d\n", entero);
    printf("Entero expresado en octal %d\n", octal);
    printf("Entero más largo %d\n", hexadecimal);
    printf("Entero largo %ld\n", enteroLargo);
    printf("Entero corto sin signo %d\n", enteroCortoSinSigno);
    printf("Real %f\n", real);
    printf("Real largo %f\n", realLargo);
    system ("pause");
}

