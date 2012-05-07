//ejemplo8_25.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fhIn;
    char c;

    fhIn=fopen("ficherobinario.dat","rb");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo binario\n");
        return 1;
    }
    fseek(fhIn,40,SEEK_SET);
    fread(&c,sizeof(char),1,fhIn);
    printf("El carácter leído es %d %c\n",c,c);
    fclose(fhIn);
    system("PAUSE") ;
    return 0 ;
}
