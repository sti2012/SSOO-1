//ejemplo4_11.c
#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, N, bit;
    unsigned char *secuencia=NULL, *ptr=NULL, mascara=0x80;

    do{
        printf("Introduzca la longitud de la secuencia aleatoria: ");
        scanf(" %d",&N);
        if (N%8!=0) printf("Longitud no válida, debe ser un múltiplo de 8\n");
    }
    while (N%8!=0);

    /* Solicitar memoria */
    secuencia=(unsigned char *)malloc(N/8*sizeof(unsigned char));
    if (!secuencia){
        printf("Hay un problema al solicitar memoria");
        system("PAUSE");
        exit(1);
    }

    /* Generar la secuencia aleatoria de bits */
    ptr=secuencia;
    printf("Secuencia generada: ");
    for (i=0; i<N; ++i){
        bit=rand()%2;
        printf("%c",bit+'0');
        if (bit==1){
            *ptr=*ptr | mascara;
        }
        mascara=mascara>>1;
        if (mascara==0){
            ++ptr;
            mascara=0x80;
        }
    }
    printf("\n");

    /* Mostrar secuencia en hexadecimal */
    ptr=secuencia;
    printf("Secuencia generada en hexadecimal: ");
    for (i=0; i<N/8; ++i, ++ptr){
        printf("%X",*ptr);
    }
    /* Liberar memoria y terminar */
    free(secuencia);
    system("PAUSE");
}
