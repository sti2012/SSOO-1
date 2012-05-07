//ejemplo2_10.c
#include <stdio.h>

int main (){
    int entero = 20, entero2 = 11;
    char enteroChar;
    float real = 47.9F;
    double realLargo = 1E20;

    printf("entero: %i, real: %f\n",entero,real);
    //uso de cast, no es necesario pero es aconsejable
    enteroChar = (char) entero;
    printf("entero: %i, enteroChar: %i\n",entero,enteroChar);
    //uso de cast explícito en vez de el cast implícito del operador =
    entero = (int) real;
    printf("real: %f, entero: %i\n",real, entero);
    //uso de cast entre valores reales. Aunque el real es capaz de representar
    //el dato double podemos volver a comprobar que double tiene mayor precisión
    real = (float) realLargo;
    printf("real: %f, realLargo: %f\n",real,realLargo);
    //recordemos que la división de enteros es un entero
    real = entero/entero2;
    printf("entero: %i entero2 %i entero/entero2: %f\n",entero, entero2, real);
    //esta es la forma de obtener el resultado preciso
    real = (float) entero/entero2;
    printf("entero: %i, entero2 %i, entero/entero2: %f\n",entero, entero2, real);
    system ("pause");
}

