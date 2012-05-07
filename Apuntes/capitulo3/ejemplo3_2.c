//ejemplo3_2.c
#include <stdio.h>

int main(){
    int n1, n2, mayor, menor;

    printf("Primer número: ");
    scanf("%d", &n1);
    printf("Segundo número: ");
    scanf("%d", &n2);
    mayor = (n1 > n2) ?   n1  :  n2;
    menor = (n1 < n2) ?   n1  :  n2;
    printf("El mayor es %d\n", mayor);
    printf("El menor es %d\n", menor);
    system("pause");
}
