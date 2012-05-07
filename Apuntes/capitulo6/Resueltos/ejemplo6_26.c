//ejemplo6_26.c
#include <stdio.h>
#include <string.h>
#define TAMBUF 256

void leeCadena(const char mensaje[], char cadena[]){
    printf("%s: ", mensaje);
    scanf("%s", cadena);
}

void separaPalabras(char cadena[]){
    const char delim[] = " ";
    char *res;

    res = strtok(cadena, delim);
    while (res){
        printf("<%s>\n", res);
        res = strtok(NULL, delim);
    }
}


int main(){
    char cadena[TAMBUF], sinduplicados[TAMBUF];

    leeCadena("Introduzca el texto a separar en palabritas", cadena);
    separaPalabras(cadena);
    system("PAUSE");
    return 0;
}
