//ejemplo8_24.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fhOut;
    int i;

    fhOut=fopen("ficherobinario.dat","wb");
    if (fhOut==NULL){
        printf("No puedo abrir el archivo binario\n");
        return 1;
    }
    for (i=0; i<=255; i++){
        char c=(char) i;
        fwrite(&c,sizeof(char),1,fhOut);
    }
    fclose(fhOut);
    system("PAUSE") ;
    return 0 ;
}
