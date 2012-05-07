//ejemplo8_2.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXL 200  //número máximo de caracteres que se podrán introducir
#define MAXC 40  //número máximo de líneas

int main (){
    char texto[MAXL][MAXC];
    int total = 0;

    do{//leemos las líneas
        char* exitoGets=gets(texto[total]);
        if (exitoGets==NULL){
            printf("Se ha producido un error durante la lectura\n");
            system("pause");
            return -1;
        }
        if (stricmp (texto[total], "salir")!=0){
            total++;
        }
    }
    while (stricmp (texto[total], "salir")!=0);
    int i;
    int exitoPuts=puts("El texto introducido ha sido:\n");
    if (!exitoPuts){
        printf("Se ha producido un error durante la escritura\n");
        system("pause");
        return -2;
    }
    for (i = 0; i<total; i++){
        exitoPuts=puts(texto[i]);
        if (exitoPuts==EOF){
            printf("Se ha producido un error durante la escritura\n");
            system("pause");
            return -2;
        }
    }
    system("pause");
    return 0;
}
