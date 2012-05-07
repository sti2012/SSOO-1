//ejemplo5_21.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double aproximacionExp(double x){
    double x2=x*x;
    double x3=x2*x;
    double x4=x3*x;
    return 1+x+x2/2+x3/6+x4/24;
}

double calcularError(double x){
    double error=exp(x)-aproximacionExp(x);
    if (error>=0) return error;
    else return -error;
}

void calcularRango(double epsilon, double* x0, double* xF){
    double xstep=0.001, error;
    int fin;
    // Calcular límite izquierdo
    *x0=0;
    fin=0;
    do{
        error=calcularError(*x0-xstep);
        if (error<epsilon) (*x0)-=xstep;
        else fin=1;
    }
    while (!fin);
    // Calcular límite derecho
    *xF=0;
    fin=0;
    do{
        error=calcularError(*xF+xstep);
        if (error<epsilon) (*xF)+=xstep;
        else fin=1;
    }
    while (!fin);
}

int main(){
    double epsilon, x0, xF;
    printf("Introduzca epsilon:");
    scanf(" %lf",&epsilon);
    calcularRango(epsilon, &x0, &xF);
    printf("El rango en el que la aproximación tiene un error menor que %f\n"
           "es [%f,%f]\n",epsilon,x0,xF);
    system("PAUSE");
    return 0;
}
