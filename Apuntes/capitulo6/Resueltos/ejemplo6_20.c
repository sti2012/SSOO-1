//ejemplo6_20.c
#include <stdio.h>
#include <stdlib.h>

#define TAM 60
#define max(a,b) ((a)>(b) ? (a):(b))


void sumaEnterosLargos(const char *n1, const char *n2, char *res){
    int l1, l2, digito1, digito2, suma, len, i;
    int acarreo=0;
    char tmp;

    l1 = strlen(n1);
    l2 = strlen(n2);
    for (i=0; i<max(l1,l2); i++){
        digito1 = (i >= l1) ?  0 : n1[l1-(i+1)] - '0';
        digito2 = (i >= l2) ?  0 : n2[l2-(i+1)] - '0';
        suma = digito1 + digito2 + acarreo;
        res[i] = '0' + (suma % 10);
        acarreo = suma / 10;
    }
    if (acarreo){
        res[i++] = '1';
    }
    res[i] = 0;
    /* dar la vuelta a los dígitos del numero */
    len = strlen(res);
    for (i=0; i<len/2; i++){
        tmp = res[len-(i+1)];
        res[len-(i+1)] = res[i];
        res[i] = tmp;
    }
}

int main(){
    char num1[TAM], num2[TAM], suma[TAM];

    printf("Introduzca un entero largo: ");
    scanf("%s", num1);
    printf("Introduzca otro entero largo: ");
    scanf("%s", num2);
    sumaEnterosLargos(num1, num2, suma);
    printf("Resultado: %s + %s = %s\n", num1, num2, suma);
    system("PAUSE");
    return 0;
}
