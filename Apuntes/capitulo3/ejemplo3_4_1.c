//ejemplo3_4_1.c
#include <stdio.h>

int main(){
    int mes, dias;
    printf("\n\nIntroduzca el n�mero del mes: ");
    scanf("%d",&mes);
    switch (mes){
    case 2  :
        dias=28;
    case 4  :
    case 6  :
    case 9  :
    case 11 :
        dias=30;
    default :
        dias=31;
    }
    printf("El mes %d tiene %d d�as\n",mes,dias);
    system("pause");
}

