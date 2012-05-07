//ejemplo8_26.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE* abrirFichero(const char *nombreFichero){
    FILE *fhIn, *fhOut;
    char respuesta;
    fhIn=fopen(nombreFichero,"rb");
    if (fhIn==NULL){
        fhOut=fopen(nombreFichero,"wb");
        return fhOut;
    }
    else{
        fclose(fhIn);
        do{
            printf("El fichero %s existe, ¿desea sobreescribirlo? (s/n):");
            scanf("%c",&respuesta);
            respuesta=tolower(respuesta);
        }
        while (respuesta!='s' && respuesta!='n');
        if (respuesta=='s'){
            fhOut=fopen(nombreFichero,"wb");
            return fhOut;
        }
        else        {
            return NULL;
        }
    }
}

int main(){
    FILE *fhOut=abrirFichero("ficherobinario.dat");
    if (fhOut!=NULL) fclose(fhOut);
    system("PAUSE") ;
    return 0 ;
}
