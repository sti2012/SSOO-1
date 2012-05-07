//ejercicio6_10_3.c
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
        cadenaInvertida [i]= cadena[tam-i-1];
    }
    //ponemos el carácter \0 al final de la cadena
    cadenaInvertida [tam] = 0;
    printf ("%s", cadenaInvertida);
    system("pause");
}
