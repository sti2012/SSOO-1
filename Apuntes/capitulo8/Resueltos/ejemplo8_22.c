//ejemplo8_22.c
#include <stdio.h>
#include <stdlib.h>

struct Linea{
    int   clave;
    char  texto[256];
    struct Linea *siguienteLinea;
};

int main(){
    FILE *fh_in;
    struct Linea linea;
    struct Linea *ficheroOrdenado=NULL, *lineaAux, *lineaActual;
    int finish;

    fhIn=fopen("ficheroParaOrdenar.txt","r");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo de lectura\n");
        return -1;
    }
    fscanf(fhIn," %d %[^\n]",&linea.clave,linea.texto);
    while (!feof(fhIn)){
        // Crear una nueva celda con la información recién leída
        lineaAux=(struct Linea *) malloc(sizeof(struct Linea));
        lineaAux->clave=linea.clave;
        strcpy(lineaAux->texto,linea.texto);
        lineaAux->siguienteLinea=NULL;
        // Insertarla en el lugar correcto del fichero ya ordenado
        if (ficheroOrdenado==NULL){
            ficheroOrdenado=lineaAux;
        }
        else if (ficheroOrdenado->clave>lineaAux->clave){
            lineaAux->siguienteLinea=ficheroOrdenado;
            ficheroOrdenado=lineaAux;
        }
        else{
            lineaActual=ficheroOrdenado;
            finish=lineaActual->siguienteLinea==NULL;
            if (lineaActual->siguienteLinea!=NULL)
                finish=lineaActual->siguienteLinea->clave>=lineaAux->clave;
            while (!finish){
                lineaActual=lineaActual->siguienteLinea;
                finish=lineaActual->siguienteLinea==NULL;
                if (lineaActual->siguienteLinea!=NULL)
                    finish=lineaActual->siguienteLinea->clave>=lineaAux->clave;
            }
            if (lineaActual->siguienteLinea==NULL){
                lineaActual->siguienteLinea=lineaAux;
            }
            else{
                lineaAux->siguienteLinea=lineaActual->siguienteLinea;
                lineaActual->siguienteLinea=lineaAux;
            }
        }
        // Leer siguiente linea
        fscanf(fhIn," %d %[^\n]",&linea.clave,linea.texto);
    }
    fclose(fhIn);

    lineaActual=ficheroOrdenado;
    while (lineaActual!=NULL){
        printf("%d %s\n",lineaActual->clave,lineaActual->texto);
        lineaActual=lineaActual->siguienteLinea;
    }
    system("PAUSE") ;
    return 0 ;
}
