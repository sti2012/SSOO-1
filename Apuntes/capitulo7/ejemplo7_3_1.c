//ejemplo7_3_1.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Coord{
    float x;
    float y;
    float z;
}Punto;

int main (){
    Punto* puntoA;
    Punto* puntoB;

    puntoA = (Punto*) malloc(sizeof(Punto));
    puntoB = (Punto*) malloc(sizeof(Punto));
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
    printf("\nIntroduzca la coordenada x del segundo punto: ");
    scanf("%f", &(puntoB->x));
    printf("Introduzca la coordenada y del segundo punto: ");
    scanf("%f", &(puntoB->y));
    printf("Introduzca la coordenada z del segundo punto: ");
    scanf("%f", &(puntoB->z));
    if (puntoA == puntoB){
        printf("Los dos puntos son iguales\n");
    }
    else{
        printf("Los dos puntos son distintos\n");
    }
    free (puntoA);
    free (puntoB);
    system("pause");
    return 0;
}
