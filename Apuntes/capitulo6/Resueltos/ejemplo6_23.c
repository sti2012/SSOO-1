//ejemplo6_23.c
#include <stdio.h>
#include <string.h>
#define TAMBUF 256

void leeCadena(const char mensaje[], char cadena[]){
    printf("%s: ", mensaje);
    scanf("%s", cadena);
}

void eliminaEspacios(char cadena[], char nueva[]){
    int i;

    strcpy(nueva, "");
    for (i=0; i<strlen(cadena); i++){
        if (cadena[i] != ' '){
            strncat(nueva, cadena+i, 1);
        }
    }
}


int main(){
    char cadena[TAMBUF], sinespacios[TAMBUF];

    leeCadena("Introduzca la cadena para eliminar espacios", cadena);
    eliminaEspacios(cadena, sinespacios);
    printf("La cadena sin espacios es '%s'\n", sinespacios);
    system("PAUSE");
    return 0;
}
