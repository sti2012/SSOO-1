//ejercicio8_3_3.c
#include<stdio.h>
#include<stdlib.h>

int main (){

    float num1,num2;
    char opcion;
    while (1){
        printf("\n-------CALCULADORA--------");
        printf("\n1.Realizar suma");
        printf("\n2.Realizar resta");
        printf("\n3.Realizar multiplicaci�n");
        printf("\n4.Realizar divisi�n");
        printf("\n5.Salir del programa");

        do{  //mientras no introduzca una opci�n v�lida
            printf("\n\nIntroduzca la opci�n deseada:");
            scanf(" %c",&opcion);
        }
        while ((opcion<'1')||(opcion> '5'));

        printf("\nIntroduzca el primer n�mero: ");
        scanf("%f",&num1);
        printf("\nIntroduzca el segundo n�mero: ");
        scanf("%f",&num2);
        switch (opcion){
        case '1':{
            float suma;
            suma=num1+num2;
            printf("\nEl resultado de la suma es: %f",suma);
            break;
        }
        case '2':{
            float resta;
            resta=num1-num2;
            printf("\nEl resultado de la resta es: %f",resta);
            break;
        }
        case '3':{
            float mult;
            mult=num1*num2;
            printf("\nEl resultado de la multiplicaci�n es: %f",mult);
            break;
        }
        case '4':{
            float div;
            div=num1/num2;
            printf("\nEl cociente de la divisi�n es: %f",div);
            break;
        }
        default:{
            return 0;
        }
      }
    }
}
