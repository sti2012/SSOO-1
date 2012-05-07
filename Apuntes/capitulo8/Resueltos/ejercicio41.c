/*
*ejemplox_41.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 40

char *enteroACadena(int entero)
{
   char auxstr[TAM];
   char* retval;
   int i=0, iaux=0;
   int negativo=0;
   /* Considerar el signo del número */
   if (entero<0) {
      negativo=1;
      entero=-entero;
   }
   
   /* Calcular la representación como cadena del valor absoluto,
      empezando por los dígitos menos significativos. */
   do {
      auxstr[iaux++]='0'+entero%10;
      entero/=10;
   } while (entero>0);
   
   /* Dar la vuelta a la representación de forma que los dígitos más
      siginificativos estén a la izquierda. */
   retval=(char*)malloc(iaux+negativo+1);
   if (negativo) retval[i++]='-';
   iaux--;
   while (iaux>=0) retval[i++]=auxstr[iaux--];
   
   /* Terminar la cadena */
   retval[i]='\0';
   return retval;
}  

int main() {
   int N;
   char *res;
   printf("Introduzca un número entero para convertirlo a cadena:\n");
   scanf("%d",&N);
   res = enteroACadena(N);
   printf("La cadena correspondiente es \"%s\"\n", res);
   free(res);
   system("PAUSE");	
   return 0;
}
 
