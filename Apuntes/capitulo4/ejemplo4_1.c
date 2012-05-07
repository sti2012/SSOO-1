//ejemplo4_1.c
#include <stdio.h>

int main (){
    int entero=3;
    int entero2;
    int *pEntero;
    int *pEntero2;
    //pEntero se inicializa con la dirección de memoria de entero
    pEntero=&entero;
    //entero2 se inicializa con el contenido de la posición
    //de memoria apuntada por pEntero
    entero2=*pEntero;
    //pEntero2 se inicializa con la dirección de memoria de entero2
    pEntero2=&entero2;
    printf("\n entero=%d &entero=%p pEntero=%p *pEntero=%d",
           entero,&entero,pEntero,*pEntero);
    printf("\n entero2=%d &entero2=%p pEntero2=%p *pEntero2=%d",
           entero2,&entero2,pEntero2,*pEntero2);
}
