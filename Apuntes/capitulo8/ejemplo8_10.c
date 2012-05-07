//ejercicio8_10.c
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define TAMANOBLOQUE 20

int main (){
    char cadena[MAX];
    char nombreFEntrada[MAX], nombreFSalida[MAX];
    int tamano = TAMANOBLOQUE;
    FILE *fEntrada,*fSalida;

    printf("\nIntroduzca el nombre del archivo a copiar: ");
    gets(nombreFEntrada);
    if ((fEntrada=fopen(nombreFEntrada,"rb"))==NULL){
        printf("\n No se encuentra el fichero a copiar");
        exit(-1);
    }
    printf("\nIntroduzca el nombre del archivo copia: ");
    gets(nombreFSalida);

    //comprobamos si existe el fichero destino
    if ((fSalida=fopen(nombreFSalida,"r")) != NULL){
        printf("\n El fichero destino ya existe");
        fclose(fSalida);
        exit(-1);
    }
    //si no existe el fichero destino lo creamos
    if ((fSalida=fopen(nombreFSalida,"wb"))== NULL){
        printf("\n No se puede crear el fichero destino");
        exit(-1);
    }
//mientras el número de bytes leídos sea TAMANOBLOQUE puede quedar archivo por copiar
    while (tamano== TAMANOBLOQUE){
        //leemos TAMANOBLOQUE bytes
        tamano=fread(cadena,1,TAMANOBLOQUE,fEntrada);
        //y almacenamos en tamano el número de bytes que se ha leído realmente
        fwrite(cadena, 1, tamano,fSalida);
    }
    fflush(fSalida);
    fclose(fEntrada);
    fclose(fSalida);
    printf ("Copia concluida con éxito");
    system("pause");
    return 0;
}

