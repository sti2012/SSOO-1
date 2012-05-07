//ejemplo6_24.c
#include <stdio.h>
#include <stdlib.h>
#define TAMBUF 60

void leeCadena(const char mensaje[], char cadena[]){
    printf("%s: ", mensaje);
    scanf("%s", cadena);
}

int buscaSubcadena(const char *cadena, const char *subcadena){
    int i, j, lsub, encontrada;

    lsub = strlen(subcadena);
    for (i=0; i<strlen(cadena)-lsub+1; i++){
        encontrada = 1;
        for (j=0; j<lsub; j++){
            if (cadena[i+j] != subcadena[j]){
                encontrada = 0;
                break;
            }
        }
        if (encontrada){
            return i;
        }
    }
    return -1;
}

int main(){
    char cadena[TAMBUF], subcadena[TAMBUF];
    int pos;

    leeCadena("Introduzca la cadena original", cadena);
    leeCadena("Introduzca la cadena a buscar en la anterior", subcadena);
    pos = buscaSubcadena(cadena, subcadena);
    if (pos == -1){
        printf("La subcadena '%s' no se encuentra en la cadena '%s'.\n", subcadena, cadena);
    }
    else{
        printf("La subcadena '%s' está en la posición %d.\n", subcadena, pos);
    }
    system("PAUSE");
    return 0;
}
