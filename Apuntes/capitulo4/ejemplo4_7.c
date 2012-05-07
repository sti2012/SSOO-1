//ejercicio4_7
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CRECIMIENTO 2

int main (){
    int tam=CRECIMIENTO, i, num, numeroElementos=0;

    int* lista=(int*) malloc(tam*sizeof(int));
    //si ha habido un problema reservando memoria detenemos la ejecución
    if (lista == NULL){
        printf("\aERROR. No hay suficiente espacio.\n");
        exit(0);//terminamos la ejecución del programa
    }
    do{
        printf("\n Introduzca el siguiente número (-1 para salir):");
        scanf("%d",&num);
        if (num != -1){//si no es el código de salida
            //si es necesario, reservamos más espacio
            if (numeroElementos >= tam){
                lista = realloc (lista, (numeroElementos + CRECIMIENTO)*
                    sizeof (int));
                if (lista == NULL){
                    printf("\aERROR. No hay suficiente espacio.\n");
                    //terminamos la ejecución del programa
                    exit(0);
                }
                tam = tam + CRECIMIENTO;
            }
            *(lista + numeroElementos) = num;
            numeroElementos++;
        }
    }
    while (num != -1);

    for (i=0;i<numeroElementos;++i){
        printf("Posición %d, valor %d\n",i,*(lista+i));
    }
    free (lista);
    system("pause");
}
