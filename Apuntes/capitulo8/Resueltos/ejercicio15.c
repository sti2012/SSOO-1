/*
*ejemplox_10.c
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int suma=0, i;
  for (i=10;i<235;++i)
   {
     if ( i%2==0 && i%3==0) {
       suma +=i;
       }
   }
    printf("La suma de los mulltiplos de 2 y 3 entre 10 y 234 es %d\n",suma);
    system("pause");
}
