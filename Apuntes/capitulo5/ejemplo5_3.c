//ejemplo5_3.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int evaluar (int);

int main (){
    int x;
    srand(time(NULL));
    x = rand()%101;
    printf("La función 4x^2 + 3x + 5 en el punto %i vale %i \n",x,evaluar(x));
    return 0;
}

int evaluar(int x){
    x = 4*x*x + 3*x +5;
    return x;
}

