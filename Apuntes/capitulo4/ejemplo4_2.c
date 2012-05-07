//ejemplo4_2.c
#include <stdio.h>
#include <stdlib.h>
int main (){
    int entero=3;
    int *pEntero;
    pEntero=&entero;
    printf("\n *pEntero=%d entero=%d ",*pEntero,entero);
    *pEntero=0; // Modificamos el contenido de entero
    printf("\n*pEntero=%d entero=%d\n",*pEntero,entero);
    system("PAUSE");
           return 0;
}
