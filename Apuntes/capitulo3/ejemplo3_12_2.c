//ejemplo3_12_2.c
#include <stdio.h>
#include <time.h>

int main(){
    int numero, factor;
    printf("\nDame un número entero:  ");
    scanf("%d",&numero);
    for (factor = 2;factor<=numero;factor++){
        //saltamos a la siguiente iteracion
        if (numero%factor==0){
            printf("%d\n", factor);
            numero = numero/factor;
            //volvemos a probar si es visible otra vez por este término
            factor--;
        }
    }
    system("pause");
}
