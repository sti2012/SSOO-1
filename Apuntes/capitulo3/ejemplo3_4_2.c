//ejemplo3_4_2.c
#include <stdio.h>

int main(){
    int mes, dias;
    printf("\n\nDame el n�mero del mes : ");
    scanf("%d",&mes);
    switch (mes){
    case 2  :
        dias=28;
        break;
    case 4  :
    case 6  :
    case 9  :
    case 11 :
        dias=30;
        break;
    default :
        dias=31;
    }
    printf("El mes %d tiene %d d�as\n",mes,dias);
    system("pause");
}

