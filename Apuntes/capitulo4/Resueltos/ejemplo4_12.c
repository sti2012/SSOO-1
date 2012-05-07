//ejemplo4_12.c
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main (){
    int i, valor, i0, iF;
    unsigned char *secuencia=NULL, *ptr=NULL;

    /* Solicitar memoria */
    secuencia=(unsigned char *)malloc(N*sizeof(unsigned char));
    if (!secuencia){
        printf("Hay un problema al solicitar memoria");
        system("PAUSE");
        exit(1);
    }

    /* Generar la secuencia aleatoria de números */
    printf("Secuencia generada según el orden de generación: ");
    for (i=0; i<N; ++i){
        valor=rand()%255;
        printf("%d ",valor);
        /* Buscar un lugar para este valor generado */
        i0=0;
        iF=i;
        while (i0!=iF){
            int imedio=(i0+iF)/2;
            if (*(secuencia+imedio)<valor){
                i0=imedio+1;
            }
            else{
                iF=imedio;
            }
        }
        /* Hacer un hueco para el nuevo índice */
        iF=i;
        while (iF>=i0){
            *(secuencia+iF)=*(secuencia+iF-1);
            --iF;
        }
        /* Introducir el nuevo valor en el array */
        *(secuencia+i0)=valor;
    }
    printf("\n");

    /* Mostrar secuencia ordenada */
    ptr=secuencia;
    printf("Secuencia generada ordenada: ");
    for (i=0; i<N; ++i, ++ptr){
        printf("%d ",*ptr);
    }
    printf("\n");
    /* Liberar memoria y terminar */
    free(secuencia);
    system("PAUSE");
}
