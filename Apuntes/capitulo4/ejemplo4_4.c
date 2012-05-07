//ejemplo4_4.c
#include <stdio.h>

int main (){
    const int constante= 10;
    int entero=3;
    int *pEntero;
    //puntero constante
    int * const pEntero2 = &entero;
    //puntero a constante
    const int* pEntero3 = &constante;
    //puntero constante a constante
    const int const* pEntero4 = &constante;
    pEntero=&entero;
    *pEntero= 10;
    //pEntero2=& constante; ilegal
    *pEntero2= 10;
    pEntero3= &entero;
    //*pEntero3= 10; ilegal
    //pEntero4= &constante; ilegal
    //*pEntero4= 10; ilegal
}
