//ejemplo6_34.c
#include <stdio.h>
#include <stdlib.h>

void pedirCantidad (int *cantidad);
void contarMonedas (int cantidad);

int main(){
    int cantidad;
    pedirCantidad(&cantidad);
    contarMonedas(cantidad);
    system("PAUSE");
    return 0;
}

void pedirCantidad (int *cantidad){
    printf("El programa indica el n�mero m�nimo de monedas necesarias\n"
           "para una cantidad de c�ntimos entre 1 y 99\n"
           "Introduzca la cantidad de c�ntimos deseados: ");
    scanf(" %d",cantidad);
}

void contarMonedas (int cantidad){
    int monedas[6]={50,20,10,5,2,1};
    int contador, i;
    for (i=0; i<=5; ++i)
        contador=0;
        while (cantidad>=monedas[i]){
            if (cantidad>=monedas[i]){
                ++contador;
                cantidad-=monedas[i];
            }
        }
        printf("El n�mero de monedas usadas de valor %d c�ntimos es %d\n",
               monedas[i],contador);
    }
}

