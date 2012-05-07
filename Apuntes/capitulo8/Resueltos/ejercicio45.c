/*
*ejemplox_45.c
*/
#include <stdio.h>
#include <stdlib.h>

int digitoN(int x, int N) {
   int contador=0;
   if (x<=0) return -1;
   while (x>0 && contador!=N) {
      x=x/10;
      ++contador;
   }
   if (contador==N && x>0) return x%10;
   else return -1;
}

int main()
{
   int x, N, digito;
   printf("Introduzca un n�mero entero positivo:\n");
   scanf(" %d",&x);
   printf("�Qu� d�gito desea conocer?\n");
   scanf(" %d",&N);
   digito=digitoN(x,N);
   if (digito==-1)
      printf("El d�gito solicitado no existe\n");
   else
      printf("El d�gito solicitado es %d\n",digito);
  system("PAUSE");	
  return 0;
}
