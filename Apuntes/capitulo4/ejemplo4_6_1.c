//ejemplo4_6_1.c
#include <stdio.h>
#include <stdlib.h>
int main (){
    int i,tam,*lista,j,temp;
    printf("�Cu�ntos n�meros ser�n introducidos?");
    scanf("%d",&tam);
    lista=(int *) malloc(tam*sizeof(int));
    for (i=0;i<tam;i++){
        printf("\nIntroduzca el n�mero en la posici�n %d:",i);
        scanf("%d",lista+i);
    }
    //realizamos un n�mero de pasadas igual al n�mero de datos menos uno
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
        printf("Posici�n %d, valor %d\n",i,*(lista+i));
    }
    free(lista);
    system("pause");
}
