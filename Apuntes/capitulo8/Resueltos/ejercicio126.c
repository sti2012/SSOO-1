/*
*ejemplox_126.c
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fh_in;
   char c;

   fh_in=fopen("ficherobinario.dat","rb");
   if (fh_in==NULL) {
       printf("No puedo abrir el archivo binario\n");
       return 1;
   }

   fseek(fh_in,40,SEEK_SET);
   fread(&c,sizeof(char),1,fh_in);
   printf("El carácter leído es %d %c\n",c,c);
   fclose(fh_in);

   system("PAUSE") ;
   return 0 ;
}
