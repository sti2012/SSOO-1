//basicogeometria.h
#ifndef __BASICOGEOMETRIA_H
#define __BASICOGEOMETRIA_H
void leerPunto(const char *mensaje, float *x, float *y, float *z);
float calcularDeterminante(float a11, float a12, float a13,
                           float a21, float a22, float a23);
float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2,
                   float x3, float y3, float z3);
#endif
