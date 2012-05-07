/*
*ejemplox_75.c
*/
#include <stdio.h>
#include <string.h>

#define TAMBUF 256


void leecadena(const char mensaje[], char cadena[])
{
        char buf[TAMBUF];
        char final[] = "fin";
        int i, pos;
           
        printf("%s: ", mensaje);
        scanf("%s", cadena);
}

void separapalabras(char cadena[])
{
        const char delim[] = " ";
	char *res;
        
        res = strtok(cadena, delim);
	while (res) {
            printf("<%s>\n", res);
	    res = strtok(NULL, delim);
        }
}

    
int main() {
   char cadena[TAMBUF], sinduplicados[TAMBUF];

   leecadena("Introduzca el texto a separar en palabritas", cadena);
   separapalabras(cadena);

   system("PAUSE");	
   return 0;
}
