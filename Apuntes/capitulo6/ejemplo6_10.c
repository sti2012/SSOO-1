//ejercicio6_10_1.c
#include<stdio.h>
//para usar la función strlen
#include<string.h>
#include<stdlib.h>

int main (){
    char cadena[100], cadenaInvertida[100];
    int i, tam;
    printf("Escriba la cadena\n");
    gets (cadena);
    tam=strlen(cadena);
    for (i=0;i<tam;i++){
        cadenaInvertida [i]= cadena[tam-i];
    }
    printf("\nLa cadena escrita al revés es: \n");
    printf ("%s", cadenaInvertida);
    system("pause");
}
