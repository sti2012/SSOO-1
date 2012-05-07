//ejemplo4_3.c
#include <stdio.h>
#include <stdio.h>
int main (){
    long long dato = 0xFFFFFFFF00000000;
    long long* pLongLong;
    int* pInt;
    void* pVoid;

    pLongLong = &dato;
    pVoid = pLongLong;
    pInt = (int*)pVoid;
    //imprimimos los tres punteros
    printf("La dirección almacenada en pLongLong es  = %p\n",pLongLong);
    printf("La dirección almacenada en pVoid es = %p\n",pVoid);
    printf("La dirección almacenada en pInt es = %p\n",pInt);
    //veremos que el dato es 0
    printf("El dato  referenciado por pInt es   = %x\n",*pInt);
    pInt++;
    printf("La dirección almacenada en pInt es = %p\n",pInt);
    //veremos que el dato es 0xFFFFFFFF
    printf("El dato  referenciado por pInt es   = %x\n",*pInt);
    system("PAUSE");
    return 0;
}
