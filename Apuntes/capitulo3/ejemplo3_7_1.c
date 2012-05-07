//ejemplo3_7_1.c
#include <stdio.h>

int main(){
    //inicializamos factorial a 1, el elemento neutro de la multiplicación
    int factorial = 1, numero;
    printf("Introduzca la expresión: ");
    scanf("%d",&numero);
    while (numero>0);
    {
        factorial = factorial*numero;
        --numero;
    }
    //si el número introducido fuese 0 factorial contendrá 1
    printf("El factorial es %d\n",factorial);
    system("pause");
}
