//ejercicio6_8.c
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int imprimeMenu ();

int main (){
    int opcion;
    float vector1[3], vector2[3];
    float* resultado;
    //el bucle se ejecutará hasta que el usuario
    //indique que desea salir del programa
    while (1){
        //obtenemos la operación a realizar
        opcion = imprimeMenu();
        if (opcion == 5){
            //salimos del main y, por tanto, termina el programa
            return 0;
        }
        printf ("Introduzca el primer vector: ");
        scanf ("%f %f %f", &vector1[0], &vector1[1], &vector1[2]);
        printf ("Introduzca el segundo vector: ");
        scanf ("%f %f %f", &vector2[0], &vector2[1], &vector2[2]);
        //realizamos la operación correspondiente
        switch (opcion){
        case 1:{
            float producto = productoEscalar(vector1, vector2);
            printf ("El resultado es %f",resultado);
            break;
        }
        case 2:{
            resultado = productoVectorial(vector1, vector2);
            printf ("El resultado es (%f, %f, %f",
                    resultado[0], resultado[1], resultado[2]);
            break;
        }
        case 3:{
            resultado = sumaVectorial(vector1, vector2);
            printf ("El resultado es (%f, %f, %f",
                    resultado[0], resultado[1], resultado[2]);
            break;
        }
        case 4:{
            resultado = restaVectorial(vector1, vector2);
            printf ("El resultado es (%f, %f, %f",
                    resultado[0], resultado[1], resultado[2]);
            break;
        }

      }
    }

    system("pause");
}

int imprimeMenu (){
    int opcion;
    printf("\t1.Calcular el producto escalar\n");
    printf("\t2.Calcular el producto vectorial\n");
    printf("\t3.Calcular la suma vectorial\n");
    printf("\t4.Calcular la resta vectorial\n");
    printf("\t5.Salir\n");
    scanf (" %i", &opcion);
    return opcion;
}
