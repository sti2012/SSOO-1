//jemplo4_6_2.c
#include <stdio.h>

int main (){
    int i,tam,*lista,j,temp;
    printf("¿Cuántos números seran introducidos?");
    scanf("%d",&tam);
    lista=(int *) malloc(tam*sizeof(int));
    if (lista == NULL){
        printf ("Fallo al reserva memoria");
        return -1;
    }
    for (i=0;i<tam;i++){
        printf("\nDame el número en la posición %d:",i);
        scanf("%d",lista+i);
    }
    //realizamos un número de pasadas igual al número de datos menos uno
    for (j=0;j< tam-1;++j)
        for (i=0 ; i <tam-j-1;++i){
            if (*(lista+i) > *(lista+i+1) ){
                temp=*(lista+i+1);
                *(lista+i+1) = *(lista+i);
                *(lista+i)=temp;//  intercambiamos los jentos
            }
        }
    printf("Lista reordenada:\n");
    for (i=0;i<tam;++i){
        printf("Posición %d, valor %d\n",i,*(lista+i));
    }
    free (lista);
    system("pause");
}
