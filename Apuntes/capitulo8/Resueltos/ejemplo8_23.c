//ejemplo8_23.c
#include <stdio.h>
#include <stdlib.h>
#define TAMANNO_BLOQUE 1024

int main(){
    FILE *fh;
    char bloque[TAMANNO_BLOQUE];
    int i;
    for (i=0; i<TAMANNO_BLOQUE; i++) bloque[i]=0;

    fh=fopen("ficherobinario.dat","r+b");
    if (fh==NULL){
        printf("No puedo abrir el archivo binario\n");
        return 1;
    }
    fseek(fh,0,SEEK_SET);
    fwrite(bloque,sizeof(char),TAMANNO_BLOQUE,fh);
    fclose(fh);
    system("PAUSE") ;
    return 0 ;
}
