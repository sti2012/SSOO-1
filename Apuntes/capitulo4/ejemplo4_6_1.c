//ejemplo4_6_1.c
#include <stdio.h>
#include <stdlib.h>
int main (){
    int i,tam,*lista,j,temp;
    printf("¿Cuántos números serán introducidos?");
    scanf("%d",&tam);
    lista=(int *) malloc(tam*sizeof(int));
    for (i=0;i<tam;i++){
        printf("\nIntroduzca el número en la posición %d:",i);
        scanf("%d",lista+i);
    }
    //realizamos un número de pasadas igual al número de datos menos uno
    for (j=0;j< tam-1;++j)
        for (i=0 ; i <tam-j-1;++i){
            if (*(lista+i) > *(lista+i+1) ){
                temp=*(lista+i+1);//  intercambiamos los elementos
                *(lista+i+1) = *(lista+i);
                *(lista+i)=temp;
            }
        }
    printf("Lista reordenada:\n");
    for (i=0;i<tam;++i){
        printf("Posición %d, valor %d\n",i,*(lista+i));
    }
    free(lista);
    system("pause");
}
