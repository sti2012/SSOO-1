/*
*ejemplox_42.c
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 240

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

char *realACadena(double x)
{
   char* parteEntera;
   char* retval;
   char  parteDecimal[TAM];
   int iaux=0;
   /* Convertir la parte entera */
   parteEntera=enteroACadena((int)x);
   
   /* Convertir la parte decimal */
   if (x<0) x=-x;
   x-=(int)x;
   if (x==0.0) return parteEntera;
   do {
      x*=10;
      parteDecimal[iaux++]='0'+(int)x;
      x-=(int)x;
   } while (x!=0.0);
   parteDecimal[iaux]='\0';
   
   /* Concatenar la parte entera con la decimal */
   retval=(char*) malloc(strlen(parteEntera)+1+strlen(parteDecimal)+1);
   strcpy(retval,parteEntera);
   strcat(retval,".");
   strcat(retval,parteDecimal);
   free(parteEntera);
   free(parteDecimal);
   return retval;
}

int main() {
   double x;
   char *res;
   printf("Introduzca un número real para convertirlo a cadena:\n");
   scanf("%lf",&x);
   res = realACadena(x);
   printf("La cadena correspondiente es \"%s\"\n", res);
   system("PAUSE");	
   return 0;
}
 
