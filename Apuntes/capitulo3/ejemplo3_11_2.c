//ejemplo3_11_2.c
#include <stdio.h>
#include <time.h>

int main(){
    int secreto, numero, salir;
    srand(time(NULL));
    secreto=rand()% 1000 + 1;
    printf("\nAdivine el número secreto."
           " Para salir, introduzca el numero 0\n\n");
    salir=0;
    do{
        printf("\nIntroduzca un número del 1 al 1000:  ");
        scanf("%d",&numero);
        if (numero==0){
            salir=1;
        }
        else{
            if (numero!=secreto){
                printf("Ese no es el número secreto. ");
                if (secreto>numero){
                    printf("El número secreto es mayor.\n");
                }
                else{
                    printf("El número secreto es menor.\n");
                }
            }
            else printf(" Has acertado ! \n");
        }
    }//mientras no acierte o indique que quiere salir
    while (numero!=secreto && !salir);
    system("pause");
}
