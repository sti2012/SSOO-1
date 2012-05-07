//ejemplo3_16_1.c
#include <stdio.h>

int main(){
    int i, contadorMultiplos=0, suma=0;

    for (i=1; i<=100; ++i){
        if (i%5==0){
            suma+=i;
            printf("%d es múltiplo de 5\n",i);
            ++contadorMultiplos;
        }
    }
    printf("Hay %d múltiplos de 5 entre 1 y 100\n",contadorMultiplos);
    printf("La suma de todos ellos es %d\n",suma);
    system("pause");
}
