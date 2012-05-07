/*
*ejemplox_125.c
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fh_out;
   int i;

   fh_out=fopen("ficherobinario.dat","wb");
   if (fh_out==NULL) {
       printf("No puedo abrir el archivo binario\n");
       return 1;
   }

   for (i=0; i<=255; i++) {
      char c=(char) i;
      fwrite(&c,sizeof(char),1,fh_out);
   }
   fclose(fh_out);

   system("PAUSE") ;
   return 0 ;
}
