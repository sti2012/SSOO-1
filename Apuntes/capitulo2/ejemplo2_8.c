//ejemplo2_8.c
#include <stdio.h>

int main (){
    int entero = 1;
    float real = 10.0F;

    printf("entero: %d\n", entero);
    //la siguiente instrucción imprimirá 1 ya que el entero
    //se muestra antes de incrementarse
    printf("entero++: %d\n", entero++);
    //pero después de ejecutar la sentencia anterior entero vale 2
    printf("entero: %d\n", entero);
    //a continuación se imprimirá 3 ya que se incrementa antes de mostrarse
    printf("++entero: %d\n", ++entero);
    //y la siguiente imprimirá 3 ya que el entero se muestra antes
    //debe incrementarse
    printf("entero--: %d\n", entero--);
    //pero tras ejecutar la sentencia anterior entero vale 2
    printf("entero: %d\n", entero);
    //ahora se imprimirá 1 ya que se decrementa antes de mostrarse
    printf("--entero: %d\n", --entero);
    printf("real: %f\n",real);
    real += 2;//equivalente a real = real + 2;
    printf("real += 2: %f\n",real);
    real -= 6;//equivalente a real = real - 6;
    printf("real -= 6: %f\n",real);
    real *= 3;//equivalente a real = real * 3;
    printf("real *= 3: %f\n",real);
    real /= 9;//equivalente a real = real / 9;
    printf("real /= 9: %f\n",real);
    system ("pause");
}

