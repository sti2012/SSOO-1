//ejercicio5_10_2.c
#include <stdio.h>

#define pot(x) (x)*(x)

int main(){
    int valorFinal, valorInicial, diferencia, i;
    printf("Introduzca el valor inicial: ");
    scanf("%d", &valorInicial);
    printf("Introduzca el valor final: ");
    scanf("%d", &valorFinal);
    diferencia = valorFinal -valorInicial;
    for (i=0; i<diferencia; i++){
        printf("resultado = %d\n", pot(valorInicial +i));
    }
    system("pause");
}
