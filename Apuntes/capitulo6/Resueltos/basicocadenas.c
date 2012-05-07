//basicocadenas.c
#include "basicocadenas.h"

void leecadena(const char mensaje[], char cadena[], int maxlong){
    char buf[TAMBUF];
    char final[] = "fin";
    int i, pos;

    printf("%s: ", mensaje);
    fgets(cadena, maxlong, stdin);
    pos = strlen(cadena) - 1;
    if (cadena[pos] == '\n'){
        cadena[pos] = 0;  /* eliminar el newline */
    }
}
