//ejemplo4_5.c
#include <stdlib.h>
#include <stdio.h>

int main (){
    int     *pInt=NULL;
    float   *pFloat=NULL;
    //reservamos memoria para un entero
    pInt = (int *)  malloc(sizeof int);
    //reservamos memoria para 20 datos reales
    pFloat   = (float *)calloc(20,sizeof float);
    if ((pInt==NULL)||(pFloat==NULL))
    {
        printf("No hay memoria\n");
    }
    /* Aquí iría el código que libera la memoria */
}
