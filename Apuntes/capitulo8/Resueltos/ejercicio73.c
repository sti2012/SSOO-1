/*
*ejemplox_73.c
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

void eliminaduplicados(char cadena[], char nueva[])
{
        int i;
        
        strcpy(nueva, "");
        for (i=0; i<strlen(cadena); i++) {
            if (strchr(nueva, cadena[i]) == NULL) {
              strncat(nueva, cadena+i, 1);
            }
        }
}

    
int main() {
   char cadena[TAMBUF], sinduplicados[TAMBUF];

   leecadena("Introduzca la cadena para eliminar duplicados", cadena, TAMBUF);
   eliminaduplicados(cadena, sinduplicados);
   printf("La cadena sin duplicados es '%s'\n", sinduplicados);

   system("PAUSE");	
   return 0;
}
