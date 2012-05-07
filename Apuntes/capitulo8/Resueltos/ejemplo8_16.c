//ejemplo8_16.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, N=0, suma=0, maximo, minimo;
    float media;
    FILE* fhIn;

    fhIn=fopen("numeros.txt","r");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo numeros.txt\n");
        system ("PAUSE") ;
        return 1;
    }

    fscanf(fhIn," %d",&x);
    maximo=minimo=x;
    while (!feof(fhIn)){
        if      (x>maximo) maximo=x;
        else if (x<minimo) minimo=x;
        N++;
        suma+=x;
        fscanf(fhIn," %d",&x);
    }
    media=(float)suma/N;
    fclose(fhIn);
    printf("El mínimo es %d\n",minimo);
    printf("El máximo es %d\n",maximo);
    printf("La media es %f\n", media);
    system("PAUSE") ;
    return 0 ;
}
