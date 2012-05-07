//ejemplo3_20.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    float x, y;
    int i;
    for (i=-10; i<=10; ++i){
        x=0.5*(float)i;
        y=(x*x)+1;
        printf("Para i=%d, x es %f, y el polinomio vale %f\n",i,x,y);
    }
    system("pause");
}
