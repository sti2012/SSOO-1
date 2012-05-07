//ejercicio5_7.c
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int imprimeMenu ();

int main (){
    int opcion;
    float x1, x2, x3, y1, y2, y3
    //se ejecutará hasta que el usuario indique que desea salir del programa
    while (1){
        //obtenemos la operación a realizar
        opcion = imprimeMenu();
        if (opcion == 5){
            //salimos del main y, por tanto, termina el programa
            return 0;
        }
        printf ("Introduzca el primer vector: ");
        scanf ("%f %f %f", &x1, &x2, &x3);
        printf ("Introduzca el segundo vector: ");
        scanf ("%f %f %f", &y1, &y2, &y3);
        //realizamos la operación correspondiente
        switch (opcion){
        case 1:{
            productoEscalar(x1, x2, x3, y1, y2, y3);
            break;
        }
        case 2:{
            productoVectorial(x1, x2, x3, y1, y2, y3);
            break;
        }
        case 3:{
            sumaVectorial(x1, x2, x3, y1, y2, y3);
            break;
        }
        case 4:{
            restaVectorial(x1, x2, x3, y1, y2, y3);
            break;
        }
      }
    }
    system("pause");
    return 0;
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
