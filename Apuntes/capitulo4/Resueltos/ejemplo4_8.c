//ejercicio4_8
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (){

    int* vector;
    int numeroEliminado, numeroElementos,i,j;
    printf("Introduce el número de elementos: ");
    scanf("%d",&numeroElementos);
    //Reservo memoria dinámicamente para los elementos.
    vector = (int* )malloc(sizeof(int)*numeroElementos);
    if (vector == NULL){
        printf("\aERROR. No hay suficiente espacio.\n");
        return 1;
    }

    srand(time(NULL));
    for (i=0;i<numeroElementos;i++){
        *(vector+i) =(rand()% 10);
    }

    printf("VECTOR:\n\n");
    for (i=0;i<numeroElementos;i++){
        printf("%d ",*(vector+i));
    }
    printf("\n");

    do{
        printf("\nIntroduce el número a borrar: ");
        scanf("%d",&numeroEliminado);
        //si no es el código de salida
        if (numeroEliminado!= 10){
            for (i=0;i<numeroElementos;i++){
                if (*(vector+i) ==numeroEliminado){
                    for (j=i;j<numeroElementos;j++){
                        *(vector+j) =*(vector+j+1);
                    }
                    i--;//Seguimos en el mismo lugar, pues he eliminado uno.
                    numeroElementos--;
                }
            }
            //Reajustamos la memoria.
            vector=(int*) realloc(vector,sizeof(int)*numeroElementos);
            //es poco probable que suceda un error porque estamos pidiendo
            //menos memoria dinámica de la que actualmente tenemos
            //pero es bueno curarse en salud
            if (vector == NULL){
                printf("\aERROR. No hay suficiente espacio.\n");
                return 1;
            }

            printf("VECTOR:\n\n");
            for (i=0;i<numeroElementos;i++){
                printf("%d ",*(vector+i));
            }
            printf("\n");
        }
        //mientras no introduzca el código de salida y queden elementos
    }
    while ((numeroEliminado!= 10)&&(numeroElementos!=0));
    free (vector);
    system("pause");
}

