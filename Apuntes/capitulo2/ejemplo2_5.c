//ejemplo2_5.c
#include <stdio.h>

int main (){
    char caracter = 'a';
    int entero = 5;
    int entero2 = 6;
    float real = 47.9F;

    //un char es un entero a todos los efectos
    printf("Caracter + entero: %d\n", caracter + entero);
    printf("Caracter * entero: %d\n", caracter * entero);
    /*Al mostrar un n�mero entero como car�cter se muestra
    el car�cter correspondiente a la posici�n de la tabla ASCII
    representada por el entero*/
    printf("Caracter ASCII correspondiente al codigo 100: %c\n", 100);
    //no es posible representar cualquier valor decimal
    printf("Real: %f\n", real);
    //la aritm�tica de reales no es precisa
    printf("48 - 0.1F -47.8F - 0.1F: %f\n", 48 - 0.1F -47.8F - 0.1F);
    //aunque si usamos datos double es m�s precisa
    printf("48 - 0.1 -47.8 - 0.1: %f\n", 48 - 0.1 -47.8 - 0.1);
    //esta sentencia detiene la ejecuci�n del programa
    //hasta que el usuario pulsa una tecla
    system ("pause");
}
