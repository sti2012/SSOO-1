//ejemplo8_19.c
#include <stdio.h>
#include <stdlib.h>

struct Propietario{
    char  nombre[256];
    int   planta;
    char  letraPiso;
    float importe;
};

int contarVecinos(char *nombreFichero){
    char linea[1024];
    int nVecinos=0;
    FILE *fhIn;

    fhIn=fopen(nombreFichero,"r");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo %s\n",nombreFichero);
        return -1;
    }
    fscanf(fhIn," %[^\n]",linea);
    while (!feof(fhIn)){
        nVecinos++;
        fscanf(fhIn," %[^\n]",linea);
    }
    fclose(fhIn);
    return nVecinos;
}

struct Propietario * leerComunidad(char *nombreFichero, int *nVecinos){
    FILE *fhIn;
    struct Propietario *comunidad=NULL;
    int i;
    *nVecinos=contarVecinos(nombreFichero);
    if (*nVecinos<0){
        printf("Hay un problema al leer el fichero %s",nombreFichero);
        return NULL;
    }

    comunidad=(struct Propietario *)
              malloc((*nVecinos)*sizeof(struct Propietario));
    if (comunidad==NULL){
        printf("No se puede solicitar memoria");
        return NULL;
    }
    fhIn=fopen(nombreFichero,"r");
    if (fhIn==NULL){
        printf("No puedo abrir el archivo %s\n",nombreFichero);
        free(comunidad);
        return NULL;
    }
    for (i=0; i<*nVecinos; i++){
        int nLeidos=fscanf(fhIn," %[^1-9] %d %c %f",comunidad[i].nombre,
            &comunidad[i].planta, &comunidad[i].letraPiso,&comunidad[i].importe);
        if (nLeidos!=4){
            printf("Hay un problema al leer el vecino %d\n",i);
            free(comunidad);
            return NULL;
        }
    }
    fclose(fhIn);
    return comunidad;
}

void calcularTotalPorPlantas(struct Propietario *comunidad, int nVecinos){
    float totalPorPlanta[100];
    int i;

    for (i=0; i<100; i++) totalPorPlanta[i]=0;
    for (i=0; i<nVecinos; i++)
        totalPorPlanta[comunidad[i].planta]+=comunidad[i].importe;
    for (i=0; i<100; i++)
        if (totalPorPlanta[i]!=0)
            printf("El importe de la planta %d es %f\n",i,totalPorPlanta[i]);
}

int main(){
    int nVecinos;
    struct Propietario *comunidad=leerComunidad("comunidad.txt",&nVecinos);
    if (comunidad!=NULL){
        calcularTotalPorPlantas(comunidad,nVecinos);
    }
    system("PAUSE") ;
    return 0 ;
}
