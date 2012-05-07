//ejemplo5_8.c
#include <stdio.h>
#define superficie longitud * ancho

int main(){
    int longitud, ancho;

    printf("Dame la longitud:");
    scanf("%d",&longitud);
    printf("Dame el ancho:");
    scanf("%d",&ancho);
    printf("La superficie es: %d",superficie);
    system("pause");
}
