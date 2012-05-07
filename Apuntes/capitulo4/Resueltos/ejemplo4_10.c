//ejemplo4_10.c
#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, rafagaIniciada, longitudRafaga, maxLongitudRafaga, N;
    unsigned char *secuencia=NULL, *ptr=NULL, *ptrComienzoRafaga=NULL,
                                        *ptrRafagaMasLarga=NULL;

    do{
        printf("Introduzca la longitud de la secuencia aleatoria: ");
        scanf(" %d",&N);
        if (N<0) printf("Longitud no v�lida\n");
    }
    while (N<0);

    /* Solicitar memoria */
    secuencia=(unsigned char *)malloc(N*sizeof(unsigned char));
    if (!secuencia){
        printf("Hay un problema al solicitar memoria");
        system("PAUSE");
        exit(1);
    }

    /* Generar la secuencia aleatoria de bits */
    ptr=secuencia;
    printf("Secuencia generada: ");
    for (i=0; i<N; ++i, ++ptr){
        *ptr=rand()%2;
        printf("%c",*ptr+'0');
    }
    printf("\n");

    /* Determinar la secuencia de 0s m�s larga */
    rafagaIniciada=0;
    longitudRafaga=0;
    maxLongitudRafaga=0;
    ptr=secuencia;
    for (i=0; i<N; ++i, ++ptr){
        if (*ptr==0 && !rafagaIniciada){
            rafagaIniciada=1;// Comienza r�faga
            ptrComienzoRafaga=ptr;
            longitudRafaga=1;
        }
        else if (*ptr==0 && rafagaIniciada){
            longitudRafaga++;// Contin�a r�faga
        }
        else if (*ptr==1 && rafagaIniciada){
            if (longitudRafaga>maxLongitudRafaga){// Fin de r�faga
                maxLongitudRafaga=longitudRafaga;
                ptrRafagaMasLarga=ptrComienzoRafaga;
            }
            rafagaIniciada=0;
        }
    }
    if (rafagaIniciada){
        if (longitudRafaga>maxLongitudRafaga){
            maxLongitudRafaga=longitudRafaga;
            ptrRafagaMasLarga=ptrComienzoRafaga;
        }
    }

    /* Mostrar resultados */
    printf("La r�faga m�s larga tiene longitud %d\n",maxLongitudRafaga);
    printf("y se produce en la posici�n %d del array\n",
           ptrRafagaMasLarga-secuencia);
    /* Liberar memoria y terminar */
    free(secuencia);
    system("PAUSE");
}
