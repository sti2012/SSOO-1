/*
*ejemplox_112.c
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, N=0, suma=0, maximo, minimo;
    float media;
    FILE* fh_in;
    
    fh_in=fopen("numeros.txt","r");
    if (fh_in==NULL) {
        printf("No puedo abrir el archivo numeros.txt\n");
        system ("PAUSE") ;
        return 1;
    }
    
    fscanf(fh_in," %d",&x);
    maximo=minimo=x;
    while (!feof(fh_in)) {
       if      (x>maximo) maximo=x;
       else if (x<minimo) minimo=x;
       N++;
       suma+=x;

       fscanf(fh_in," %d",&x);
    }
    media=(float)suma/N;
    fclose(fh_in);
    
    printf("El mínimo es %d\n",minimo);
    printf("El máximo es %d\n",maximo);
    printf("La media es %f\n", media);
    
    system("PAUSE") ;
    return 0 ;
}
