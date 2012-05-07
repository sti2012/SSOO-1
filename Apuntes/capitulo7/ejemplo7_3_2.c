//ejemplo7_3_2.c
#include <stdio.h>
#include <stdlib.h>

typedef struct cord{
    float x;
    float y;
    float z;
}punto;

int main (){
    punto *puntoA, *puntoB;

    puntoA = (punto *) malloc(sizeof(punto));
    puntoB = (punto *) malloc(sizeof(punto));
    if ((puntoA == NULL) || (puntoB == NULL)){
        printf("No hay memoria suficiente\n");
        return(-1);
    }

    printf("Introduzca la coordenada x del primer punto: ");
    scanf("%f", &(puntoA->x));
    printf("Introduzca la coordenada y del primer punto: ");
    scanf("%f", &(puntoA->y));
    printf("Introduzca la coordenada z del primer punto: ");
    scanf("%f", &(puntoA->z));
    printf("Introduzca la coordenada x del segundo punto: ");
    scanf("%f", &(puntoB->x));
    printf("Introduzca la coordenada y del segundo punto: ");
    scanf("%f", &(puntoB->y));
    printf("Introduzca la coordenada z del segundo punto: ");
    scanf("%f", &(puntoB->z));
    if ((puntoA->x == puntoB->x) && (puntoA->y == puntoB->y)
            && (puntoA->z== puntoB->z)){
        printf("Los dos puntos son iguales\n");
    }
    else{
        printf("Los dos puntos son distintos\n");
    }
    free (puntoA);
    free (puntoB);
    system("pause");
}
