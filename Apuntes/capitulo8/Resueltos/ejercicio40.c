/*
*ejemplox_40.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 256

char *aMinusculas(const char *cadena);

int main() {
   char cadena[TAM], *res;
   printf("Introduzca una cadena para convertir a minúsculas:\n");
   scanf("%s",cadena);
   res = aMinusculas(cadena);
   printf("La cadena convertida es %s\n", res);
   free(res);
   system("PAUSE");	
  return 0;
}
 
char *aMinusculas(const char *cadena) {
   int i;
   char* retval;
   retval=(char*)malloc(1 + strlen(cadena));
   if (!retval) {
      printf("Hay un error al solicitar memoria\n");
      return NULL;
   }
   strcpy(retval,cadena);
   for (i=0; i<strlen(cadena); ++i)
      if (isupper(retval[i])) {
          retval[i] = tolower(retval[i]);
      }
   return retval;
}  
