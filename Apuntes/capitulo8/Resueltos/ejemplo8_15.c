//ejemplo8_15.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    char linea[1024];
    FILE* fhIn;

    // Apertura del archivo
    fhIn=fopen("quijote.txt","r");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo quijote.txt\n");
        system ("PAUSE") ;
        return 1;
    }
    fscanf(fhIn," %[^\n]",linea);
    while (!feof(fhIn)){
        printf("%s\n",linea);
        fscanf(fhIn," %[^\n]",linea);
    }
    fclose(fhIn);
    system("PAUSE") ;
    return 0 ;
}
