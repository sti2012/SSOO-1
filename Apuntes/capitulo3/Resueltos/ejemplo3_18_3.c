//ejemplo3_18_3.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int suma=0, i=10;
    do{
        if (i%2!=0){
            i++;
            continue;
        }
        if (i%3!=0){
            i++;
            continue;
        }
        suma +=i;
        i++;
        if (i>234) break;
    }
    while (1);
    printf("La suma de los mulltiplos de 2 y 3 entre 10 y 234 es %d\n",suma);
    system("pause");
}
