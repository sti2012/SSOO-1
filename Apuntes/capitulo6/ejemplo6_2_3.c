//ejemplo6_2_3.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 3
#define COL 2

int matrizA[FIL][COL],matrizB[FIL][COL],matrizC[FIL][COL];
int fila,columna;

int main (){
    srand(time(NULL));
    //inicialización de las matrices operandos
    for (fila=0;fila<FIL;fila++){
        for (columna=0;columna<COL;columna++){
            matrizA[fila][columna]=rand()%101;
            printf("\nIntroduzca el elemento matrizB(%d,%d) ",fila,columna);
            scanf("%d",&matrizB[fila][columna]);
        }
    }
    //bucles anidados que realizan la suma
    for (fila=0;fila<FIL;fila++){
        for (columna=0;columna<COL;columna++){
            matrizC[fila][columna]=matrizA[fila][columna]+matrizB[fila][columna];
        }
    }
    //imprimimos las dos matrices y el resultado de la suma
    system("cls");
    printf("matrizA\n\n");
    for (fila=0;fila<FIL;fila++){
        for (columna=0;columna<COL;columna++){
            printf("%d\t",matrizA[fila][columna]);
        }
        printf("\n");
    }
    printf("\nmatrizB\n\n");
    for (fila=0;fila<FIL;fila++)
    {
        for (columna=0;columna<COL;columna++)
        {
            printf("%d\t",matrizB[fila][columna]);
        }
        printf("\n");
    }
    printf("\nmatrizC\n\n");
    for (fila=0;fila<FIL;fila++){
        for (columna=0;columna<COL;columna++){
            printf("%d\t",matrizC[fila][columna]);
        }
        printf("\n");
    }
    system("pause");
}
