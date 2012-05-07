//ejemplo6_14.c
#include <stdio.h>
#include <stdlib.h>

#define TAM    100
#define TAMBUF 256

int leeArray(float tabla[], int maxnum){
    char buf[TAMBUF];
    const char fin = 'f';
    int i;

    printf("Lectura de hasta %d números reales.\n", maxnum);
    printf("Introduzca los terminos o pulse '%c' para acabar la "
           "entrada de numeros\n", fin);
    for (i=0; i<maxnum; i++){
        printf("  termino %03d: ", i);
        scanf("%s", buf);
        if (tolower(buf[0]) == fin){
            break;
        }
        tabla[i] = atof(buf);
    }
    return i;
}

void imprimeArray(float tabla[], int num){
    int i;

    printf("Ha introducido los siguientes %d números.\n", num);
    for (i=0; i<num; i++){
        printf("  posición %03d: valor %f\n", i, tabla[i]);
    }
}

int calculaMinimo(float tabla[], int num){
    int pos = -1;
    int i;

    for (i=0; i<num; i++){
        if (pos < 0 || tabla[i] < tabla[pos]){
            pos = i;
        }
    }
    return pos;
}

float calculaSuma(float tabla[], int num){
    float suma = 0.0;
    int i;

    for (i=0; i<num; i++){
        suma += tabla[i];
    }
    return suma;
}

float calculaMedia(float suma, int num){
    float media = suma / num;
    return media;
}

float calculaVarianza(float tabla[], int num, float media){
    float suma = 0.0;
    float varianza, termino;
    int i;

    for (i=0; i<num; i++){
        termino = tabla[i] - media;
        suma += termino * termino;
    }
    varianza = suma / num;
    return varianza;
}

float calculaDesviacionTipica(int num, float varianza){
    float desvtipica = sqrt(varianza);
    return desvtipica;
}

int main(){
    float tabla[TAM];
    float suma, media, varianza, desvtipica;
    int num, posminimo;

    num = leeArray(tabla, sizeof tabla);
    imprimeArray(tabla, num);
    posminimo = calculaMinimo(tabla, num);
    printf("El valor mínimo introducido es la posición %d, valor %f.\n",
           posminimo, tabla[posminimo]);
    suma = calculaSuma(tabla, num);
    printf("La suma de los %d elementos vale %f.\n", num, suma);
    media = calculaMedia(suma, num);
    printf("La media de los %d elementos vale %f.\n", num, media);
    varianza = calculaVarianza(tabla, num, media);
    printf("La varianza de los %d elementos vale %f.\n", num, varianza);
    desvtipica = calculaDesviacionTipica(num, varianza);
    printf("La desviación típica de los %d elementos es %f.\n", num, desvtipica);
    system("PAUSE");
    return 0;
}
