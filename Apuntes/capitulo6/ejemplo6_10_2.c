//ejercicio6_10_2.c
#include<stdio.h>
//para usar la función strlen
#include<string.h>
#include<stdlib.h>

int main (){
    char cadena[100], cadenaInvertida[100];
    int i, tam;
    printf("Escriba la cadena\n");
    gets (cadena);
    printf("\nLa cadena escrita al revés es: \n");
    tam=strlen(cadena);
    for (i=0;i<tam;i++){
        //ignoramos el carácter nulo
        cadenaInvertida [i]= cadena[tam-i-1];
    }
    printf ("%s", cadenaInvertida);
    system("pause");
}

