//ejercicio8_9.c
#include<stdio.h>
#include<math.h>
#define LINEAS_CONSOLA 24

int main (){
    float x,fx;
    char nombreArchivo[100];
    int contador = 0;
    FILE *fichero;

    printf ("Introduzca el nombre del archivo de entrada: ");
    fflush(stdin);
    gets (nombreArchivo);
    if ((fichero =fopen(nombreArchivo,"r"))==NULL){
        printf("\nError de apertura de fichero");
        exit(-1);
    }

    while (fscanf(fichero, "x=%f, seno(x)=%f\n",&x,&fx) != EOF){
        printf("El valor del seno en x=%.2f es %.2f\n", x, fx);
        contador++;
        if (contador == LINEAS_CONSOLA-1){
            contador =0;
            system("pause");
        }
    }
    fflush(fichero);
    fclose(fichero);
    system("pause");
    return 0;
}

