/*
*ejemplox_70.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAMBUF 60


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

int buscasubcadena(const char *cadena, const char *subcadena)
{
    int i, j, lsub, encontrada;

    lsub = strlen(subcadena);
    for (i=0; i<strlen(cadena)-lsub+1; i++) {
        encontrada = 1;
        for (j=0; j<lsub; j++) {
            if (cadena[i+j] != subcadena[j]) {
                encontrada = 0;
                break;
            }
        }
        if (encontrada) {
            return i;
        }
    }
    return -1;
}

int main()
{
   char cadena[TAMBUF], subcadena[TAMBUF];
   int pos;

   leecadena("Introduzca la cadena original", cadena, TAMBUF);
   leecadena("Introduzca la cadena a buscar en la anterior", subcadena, TAMBUF);
   pos = buscasubcadena(cadena, subcadena);

   if (pos == -1) {
       printf("La subcadena '%s' no se encuentra en la cadena '%s'.\n", subcadena, cadena);
   } else {
       printf("La subcadena '%s' est� en la posici�n %d.\n", subcadena, pos);
   }

   system("PAUSE");	
   return 0;
}
