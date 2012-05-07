//ejemplo6_15.c
#include <stdio.h>
#include <string.h>
#define TAM    5
#define TAMBUF 256

void leeCadena(const char mensaje[], char cadena[]){
    printf("%s: ", mensaje);
    scanf("%s", cadena);
}

int leeArray(char tabla[][TAMBUF], int maxcadenas){
    char buf[TAMBUF];
    char final[] = "fin";
    int i;

    printf("Lectura de una tabla de cadenas (máximo %d).\n", maxcadenas);
    printf("Introduzca las cadenas según se le vayan solicitando\n");
    printf("Introduzca 'fin' para finalizar\n");
    for (i=0; i<maxcadenas; i++){
        printf("  cadena %d: ", i);
        leeCadena("", buf);
        if (strncmp(buf, final, strlen(final)) == 0){
            strcpy(tabla[i], "");
            break;
        }
        strcpy(tabla[i], buf);
    }
    return i;
}

int buscaCadena(char tabla[][TAMBUF], char buscada[], int maxcadenas){
    int i;

    for (i=0; i<maxcadenas; i++){
        if (strcmp(tabla[i], buscada) == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    char cadenas[TAM][TAMBUF];
    char buscada[TAMBUF];
    int num, pos;

    num = leeArray(cadenas, TAM);
    printf("Introduzca la cadena a buscar: ");
    scanf("%s", buscada);
    pos = buscaCadena(cadenas, buscada, num);
    if (pos < 0){
        printf("La cadena buscada no se encuentra en el array\n");
    }
    else{
        printf("La cadena buscada está en la posición %d del array\n", pos);
    }

    system("PAUSE");
    return 0;
}
