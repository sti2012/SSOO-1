/*
*ejemplox_115.c
*/

#include <stdio.h>
#include <stdlib.h>

struct Propietario {
   char  nombre[256];
   int   planta;
   char  letraPiso;
   float importe;
};

int contarVecinos(char *nombreFichero) {
   char linea[1024];
   int nVecinos=0;
   FILE *fh_in;

   fh_in=fopen(nombreFichero,"r");
   if (fh_in==NULL) {
       printf("No puedo abrir el archivo %s\n",nombreFichero);
       return -1;
   }

   fscanf(fh_in," %[^\n]",linea);
   while (!feof(fh_in)) {
      nVecinos++;
      fscanf(fh_in," %[^\n]",linea);
   }
   fclose(fh_in);
   return nVecinos;
}    

struct Propietario * leerComunidad(char *nombreFichero, int *nVecinos) {
   FILE *fh_in;
   struct Propietario *comunidad=NULL;
   int i;
   *nVecinos=contarVecinos(nombreFichero);
   if (*nVecinos<0) {
      printf("Hay un problema al leer el fichero %s",nombreFichero);
      return NULL;
   }
   
   comunidad=(struct Propietario *)
      malloc((*nVecinos)*sizeof(struct Propietario));
   if (comunidad==NULL) {
      printf("No se puede solicitar memoria");
      return NULL;
   }
   
   fh_in=fopen(nombreFichero,"r");
   if (fh_in==NULL) {
       printf("No puedo abrir el archivo %s\n",nombreFichero);
       free(comunidad);
       return NULL;
   }

   for (i=0; i<*nVecinos; i++) {
      int nLeidos=fscanf(fh_in," %[^1-9] %d %c %f",comunidad[i].nombre,
         &comunidad[i].planta, &comunidad[i].letraPiso,
         &comunidad[i].importe);
      if (nLeidos!=4) {
         printf("Hay un problema al leer el vecino %d\n",i);
         free(comunidad);
         return NULL;
      }
   } 
   
   fclose(fh_in);
   return comunidad;
}

void calcularTotalPorPlantas(struct Propietario *comunidad, int nVecinos) {
   float totalPorPlanta[100];
   int i;
   for (i=0; i<100; i++) totalPorPlanta[i]=0;
   
   for (i=0; i<nVecinos; i++)
      totalPorPlanta[comunidad[i].planta]+=comunidad[i].importe;
   
   for (i=0; i<100; i++)
      if (totalPorPlanta[i]!=0)
         printf("El importe de la planta %d es %f\n",i,totalPorPlanta[i]);
}

int main() {
    int nVecinos;
    struct Propietario *comunidad=leerComunidad("comunidad.txt",&nVecinos);
    if (comunidad!=NULL) {
       calcularTotalPorPlantas(comunidad,nVecinos);
    }
    system("PAUSE") ;
    return 0 ;
}
