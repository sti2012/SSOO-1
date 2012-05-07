/*
*ejemplox_46.c
*/
#include <stdio.h>
#include <stdlib.h>

long int factorial(int n) {
     if (n==0 || n==1) return 1;
     else return n*factorial(n-1);
}

long int combinatorio(int n, int m) {
  if (m>n) return -1;
  else return factorial(n)/(factorial(m)*factorial(n-m));
}

int main()
{
   int n, m;
   long int nm;
   printf("Introduzca n y m:\n");
   scanf(" %d %d",&n, &m);
   nm=combinatorio(n,m);
   if (nm==-1) printf("m es mayor que n, no existe el número combinatorio\n");
   else printf("El número combinatorio (n,m) es %ld\n",nm);
   system("PAUSE");	
  return 0;
}
