/*
*ejemplox_43.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 40

int enteroValido(const char* cadena)
{
  int i=0;
  if (cadena[0]=='-') {
      i=1;
}
  while (cadena[i]!='\0') {
    if (!isdigit(cadena[i])) {
        return 0;
    }
    i++;
  }
  return 1;
}

int main() {
   char str[TAM];
   printf("Introduzca una cadena para ver si es un entero:\n");
   scanf("%s", str);
   if (!enteroValido(str)) printf("La cadena correspondiente no es un entero\n");
   else printf("La cadena correspondiente es un entero\n");
   system("PAUSE");	
   return 0;
}
 
