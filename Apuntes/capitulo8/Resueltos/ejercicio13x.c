/*
*ejemplox_13x.c
*/
#include <stdio.h>
#include <stdlib.h>

int contarVocales(const char *cadena);

int main()
{
    char cadena[256];
    printf("Introduzca una cadena para contar sus vocales:\n");
    scanf("%s");

    system("PAUSE");	
    return 0;
}
 

int contarVocales(const char *cadena)
{
    int contador=0;

    while (cadena[i]!='\0') {
        i++;
    }
    return contador;
}  
