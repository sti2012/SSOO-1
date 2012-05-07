//ejemplo2_11.c
#include <stdio.h>

int main (){
    int variableLogica = 0, variableLogica2;

    variableLogica2 = !variableLogica;
    printf("variableLogica: %d, variableLogica2: %d\n",
           variableLogica,variableLogica2);
    printf("variableLogica&&variableLogica2: %d\n",
           variableLogica&&variableLogica2);
    printf("variableLogica||variableLogica2: %d\n",
           variableLogica||variableLogica2);

    printf("\n\nTabla de verdad del operador &&:\n");
    printf("0 && 0: %d\n",0&&0);
    printf("0 && 1: %d\n",0&&1);
    printf("1 && 0: %d\n",1&&0);
    printf("1 && 1: %d\n",1&&1);

    printf("\n\nTabla de verdad del operador ||:\n");
    printf("0 || 0: %d\n",0||0);
    printf("0 || 1: %d\n",0||1);
    printf("1 || 0: %d\n",1||0);
    printf("1 || 1: %d\n",1||1);
}

