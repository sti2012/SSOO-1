//ejemplo5_4_2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercambia(int* num1, int* num2);

int main (){
    int num1,num2;
    srand(time(NULL));
    num1 = rand()% 101;
    num2 = rand()% 101;
    printf("\n Antes de la llamada num1=%i y num2=%i \n",num1,num2);
    intercambia(&num1,&num2);
    printf("\n Despu�s de la llamada num1=%i y num2=%i \n",num1,num2);
    system("pause");
    return 0;
}

void intercambia(int* num1, int* num2){
    int aux;
    printf("\n Al entrar a la funci�n num1=%i y num2=%i\n",*num1,*num2);
    aux=*num1;
    *num1=*num2;
    *num2=aux;
    printf("\n Al salir de la funci�n num1=%i y num2=%i \n",*num1,*num2);
}
