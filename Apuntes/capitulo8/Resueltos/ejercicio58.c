/*
*ejemplox_58.c
*/
#include <stdio.h>
#include <string.h>

#define TAMBUF 256


void leecadena(const char mensaje[], char cadena[], int maxlong)
{
        char buf[TAMBUF];
        char final[] = "fin";
        int i, pos;
           
        printf("%s: ", mensaje);
        fgets(cadena, maxlong, stdin);
        pos = strlen(cadena) - 1;
        if (cadena[pos] == '\n') {
           cadena[pos] = 0;  /* eliminar el newline */
        }
}

void eliminaespacios(char cadena[], char nueva[])
{
        int i;
        
        strcpy(nueva, "");
        for (i=0; i<strlen(cadena); i++) {
            if (cadena[i] != ' ') {
              strncat(nueva, cadena+i, 1);
            }
        }
}

int compruebapalindromo(char cadena[])
{
        int len = strlen(cadena);
        int i;
        
        for (i=0; i<len/2; i++) {
            if (cadena[i] != cadena[len-(i+1)]) {
                  return 0;
            }
        }
        return 1;
}
    
int main() {
   char cadena[TAMBUF], sinespacios[TAMBUF];
   int res;
   
   leecadena("Introduzca la cadena para ver si es palíndromo (los espacios no cuentan)", cadena, TAMBUF);
   eliminaespacios(cadena, sinespacios);
   res = compruebapalindromo(sinespacios);
   if (res) {
      printf("La cadena '%s' es palíndromo\n", sinespacios);
   } else {
      printf("La cadena '%s' no es palíndromo\n", sinespacios);
   }

   system("PAUSE");	
   return 0;
}
