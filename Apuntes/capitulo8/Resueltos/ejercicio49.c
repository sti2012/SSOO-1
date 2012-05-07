/*
*ejemplox_49.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 40
#define ROM 13

char* enRomano(int n){
    char romano[ROM][3]=
       {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int arabigo[ROM]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int i;
    char auxstr[TAM]="";
    char* retval;
    for (i=ROM; i>=0 ; --i) {
        while (n>=arabigo[i]) {
            n-=arabigo[i];
            strcat(auxstr,romano[i]);
        }
    }
    retval=(char*) malloc(strlen(auxstr)+1);
    strcpy(retval, auxstr);
    return retval;
}

int main() {
   int n;
   char *res;
   printf("Introduzca un año para escribirlo en números romanos:\n");
   scanf("%d",&n);
   res = enRomano(n);
   printf("El año %d en números romanos se escribe %s\n",n,res);
   free(res);
   system("PAUSE");	
   return 0;
}
