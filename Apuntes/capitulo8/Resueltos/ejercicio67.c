/*
*ejemplox_67.c
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

    
int main() {
   char cadena[TAMBUF], sinespacios[TAMBUF];

   leecadena("Introduzca la cadena para eliminar espacios", cadena, TAMBUF);
   eliminaespacios(cadena, sinespacios);
   printf("La cadena sin espacios es '%s'\n", sinespacios);

   system("PAUSE");	
   return 0;
}
