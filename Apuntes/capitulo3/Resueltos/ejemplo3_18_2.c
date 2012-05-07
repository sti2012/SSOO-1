//ejemplo3_18_2.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int suma=0, i;
    for (i=10;i<235;++i){
        if (i%2!=0) continue;
        if (i%3!=0) continue;
        suma +=i;
    }
    printf("La suma de los mulltiplos de 2 y 3 entre 10 y 234 es %d\n",suma);
    system("pause");
}
