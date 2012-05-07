//ejemplo3_3.c
#include <stdio.h>

int main(){
    float nota;

    printf("\nIntroduzca la nota numérica : ");
    scanf("%f",&nota);
    if (nota <5){
        printf("\nSuspenso\n");
    }
    else if (nota <7){
        printf("\nAprobado\n");
    }
    else if (nota <8.5){
        printf("\nNotable\n");
    }
    else if (nota<9.5){
        printf("\nSobresaliente\n");
    }
    else{
        printf("\nMatricula de Honor\n");
    }
    system("pause");
}
