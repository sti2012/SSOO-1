/*
*ejemplox_126.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE* abrirFichero(const char *nombreFichero) {
   FILE *fh_in, *fh_out;
   char respuesta;
   fh_in=fopen(nombreFichero,"rb");
   if (fh_in==NULL) {
       fh_out=fopen(nombreFichero,"wb");
       return fh_out;
   } else {
       fclose(fh_in);
       do {
          printf("El fichero %s existe, ¿desea sobreescribirlo? (s/n):");
          scanf("%c",&respuesta);
          respuesta=tolower(respuesta);
       } while (respuesta!='s' && respuesta!='n');
       if (respuesta=='s') {
          fh_out=fopen(nombreFichero,"wb");
          return fh_out;
       } else {
          return NULL;
       }
   }
}      

int main() {
   FILE *fh_out=abrirFichero("ficherobinario.dat");
   if (fh_out!=NULL) fclose(fh_out);

   system("PAUSE") ;
   return 0 ;
}
