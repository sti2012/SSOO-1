//ejemplo6_22.c
#include <stdio.h>
#include <stdlib.h>
#define TAM 60

int leeNumero(const char *mensaje){
    int num;

    printf("%s: ", mensaje);
    scanf("%d", &num);
    return num;
}

void convierteHexa(int numero, char *respuesta){
    int solucion[TAM];
    int cociente = numero;
    int contador = 0;
    int resto;
    int i, r;

    r = 0;
    if (numero < 0){
        respuesta[r++] = '-';
        cociente = -numero;
    }

    while (cociente >= 16){
        resto = cociente % 16;
        cociente /= 16;
        solucion[contador++] = resto;
    }
    solucion[contador++] = cociente;

    for (i=contador-1; i>=0; i--){
        if (solucion[i] >= 10){
            respuesta[r++] = 'A' + (solucion[i] - 10);
        }
        else{
            respuesta[r++] = '0' + solucion[i];
        }
    }
    respuesta[r++] = 'H';
    respuesta[r] = 0;        /* fin de cadena */
}

int main(){
    int numero;
    char solucion[TAM];

    numero = leeNumero("Introduzca un número decimal para pasar a base 16");
    convierteHexa(numero, solucion);
    printf("El numero en base 16 es: %s\n", solucion);
    system("PAUSE");
    return 0;
}
