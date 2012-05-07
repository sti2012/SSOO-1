//ejemplo6_2_2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 3
#define COL 2

int matrizA[FIL][COL],matrizB[FIL][COL],matrizC[FIL][COL];
//array cuyas posiciones serán machacadas
int matrizAMachacar[3];
int fila,columna;

int main (){
    //antes de almacenar ningún dato
    printf ("matrizAMachacar: ");
    for (fila=0;fila<3;fila++){
        printf ("%d\t", matrizAMachacar[fila]);
    }
    printf ("\n\n");

    srand(time(NULL));
    //inicialización de las matrices operandos
    for (fila=1;fila<=FIL;fila++){
        for (columna=1;columna<=COL;columna++){
            matrizA[fila][columna]=rand()% 101;
            printf("\nIntroduzca el elemento matrizB(%d,%d) ",fila,columna);
            scanf("%d",&matrizB[fila][columna]);
        }
    }
    //bucles anidados que realizan la suma
    for (fila=1;fila<=FIL;fila++){
        for (columna=1;columna<=COL;columna++){
            matrizC[fila][columna]=matrizA[fila][columna]+matrizB[fila][columna];
        }
    }
    //esta sentencia borra la consola
    system("cls");
    //después de almacenar los datos
    printf ("matrizAMachacar: ");
    for (fila=0;fila<3;fila++){
        printf ("%d\t", matrizAMachacar[fila]);
    }
    printf ("\n\n");
    //imprimimos las dos matrices y el resultado de la suma
    printf("matrizA\n\n");
    for (fila=1;fila<=FIL;fila++){
        for (columna=1;columna<=COL;columna++){
            printf("%d\t",matrizA[fila][columna]);
        }
        printf("\n");
    }
    printf("\nmatrizB\n\n");
    for (fila=1;fila<=FIL;fila++){
        for (columna=1;columna<=COL;columna++){
            printf("%d\t",matrizB[fila][columna]);
        }
        printf("\n");
    }
    printf("\nmatrizC\n\n");
    for (fila=1;fila<=FIL;fila++){
        for (columna=1;columna<=COL;columna++){
            printf("%d\t",matrizC[fila][columna]);
        }
        printf("\n");
    }
    system("pause");
}
