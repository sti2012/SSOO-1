//ejemplo3_19.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    float x;
    float sumaPositivos=0, sumaNegativos=0;
    int contadorPositivos=0, contadorNegativos=0;
    do{
        printf("Introduce un numero (0 = FIN):\n");
        scanf(" %f",&x);
        if (x<0){
            sumaNegativos+=x;
            ++contadorNegativos;
        }
        else if (x>0){
            sumaPositivos+=x;
            ++contadorPositivos;
        }
    }
    while (x!=0);
    float mediaPositivos = sumaPositivos / contadorPositivos;
    float mediaNegativos = sumaNegativos / contadorNegativos;
    printf("La media de los positivos es: %f\n",mediaPositivos);
    printf("La media de los negativos es: %f\n",mediaNegativos);
    system("pause");
}
