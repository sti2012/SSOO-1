//ejemplo5_9.c
#include <stdio.h>

#define bucle for (lineas=1; lineas <=n; lineas++) {  \
   for (cont=1;cont <= n-lineas;cont++) \
    putchar(' ');    \
   for (cont=1;cont <= 2*lineas-1 ;cont++) \
    putchar('*');    \
   printf("\n");     \
  }

main(){
    int cont, lineas, n;

    printf("numero de lineas = ");
    scanf("%d",&n);
    printf("\n");
    bucle;
    system("pause");
}
