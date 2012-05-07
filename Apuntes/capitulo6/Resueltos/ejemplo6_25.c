//ejemplo6_25.c
#include <stdio.h>
#include <string.h>
#define TAMBUF 256

void leeCadena(const char mensaje[], char cadena[], int maxlong){
    printf("%s: ", mensaje);
    scanf("%s", cadena);
}

void eliminaDuplicados(char cadena[], char nueva[]){
    int i;

    strcpy(nueva, "");
    for (i=0; i<strlen(cadena); i++){
        if (strchr(nueva, cadena[i]) == NULL){
            strncat(nueva, cadena+i, 1);
        }
    }
}

int main(){
    char cadena[TAMBUF], sinduplicados[TAMBUF];

    leeCadena("Introduzca la cadena para eliminar duplicados", cadena, TAMBUF);
    eliminaDuplicados(cadena, sinduplicados);
    printf("La cadena sin duplicados es '%s'\n", sinduplicados);
    system("PAUSE");
    return 0;
}
