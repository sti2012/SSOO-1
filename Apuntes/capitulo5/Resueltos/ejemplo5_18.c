//ejemplo5_18.c
#include <stdio.h>
#include <stdlib.h>
#include "basicogeometria.h"

int estanAlineados(float x1, float y1, float z1, float x2, float y2, float z2,
                   float x3, float y3, float z3){
    float area=calcularArea(x1,y1,z1,x2,y2,z2,x3,y3,z3);
    return (area==0);
}

int main(){
    float x1,y1,z1,x2,y2,z2,x3,y3,z3;
    leerPunto("Introduzca el primer punto:",&x1,&y1,&z1);
    leerPunto("Introduzca el segundo punto:",&x2,&y2,&z2);
    leerPunto("Introduzca el tercer punto:",&x3,&y3,&z3);
    if (estanAlineados(x1,y1,z1,x2,y2,z2,x3,y3,z3)){
        printf("Los puntos sí están alineados\n");
    }
    else{
        printf("Los puntos no están alineados\n");
    }
    system("PAUSE");
    return 0;
}
