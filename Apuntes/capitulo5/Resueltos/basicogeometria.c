//basicogeometria.c
#include "basicogeometria.h"

void leerPunto(const char *mensaje, float *x, float *y, float *z){
    printf("%s\n",mensaje);
    scanf(" %f %f %f",x,y,z);
}

float calcularDeterminante(float a11, float a12, float a13,
                           float a21, float a22, float a23){
    return a11*a22+a21*a13+a12*a23-a22*a13-a23*a11-a12*a21;
}

float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2,
                   float x3, float y3, float z3){
    float det1, det2, det3;
    det1=calcularDeterminante(x1,x2,x3,y1,y2,y3);
    det2=calcularDeterminante(y1,y2,y3,z1,z2,z3);
    det3=calcularDeterminante(z1,z2,z3,x1,x2,x3);
    return 0.5*sqrt(det1*det1+det2*det2+det3*det3);
}
