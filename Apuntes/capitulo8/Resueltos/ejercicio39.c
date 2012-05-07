/*
*ejemplox_39.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 256

int contarVocales(const char *cadena);

int main() {
   char cadena[TAM];
   printf("Introduzca una palabra para contar sus vocales:\n");
   scanf("%s",cadena);
   printf("El numero de vocales de la palabra es %d\n",
      contarVocales(cadena));
  system("PAUSE");	
  return 0;
}
 
int contarVocales(const char *cadena) {
   int contador=0;
   char vocales[]={'a','e','i','o','u'};
   int i=0, j;
   while (cadena[i]!='\0') {
      for (j=0; j<5; ++j)
        if (tolower(cadena[i])==vocales[j])
           ++contador;
      ++i;
   }
   return contador;
}  
