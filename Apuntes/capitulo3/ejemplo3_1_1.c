//ejemplo3_1_1.c
#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, raiz1, raiz2, discriminante;

    printf("Introduzca los coeficientes de la ecuaci�n");
    //lectura de tres datos reales, los coeficientes de la ecuaci�n
    scanf("%f%f%f",&a,&b,&c);
    if (a = 0)
        printf("No se trata de una ecuaci�n de segundo grado");
    else{
        discriminante = pow(b,2)-4*a*c;
        if (discriminante < 0 )
            printf ("La ecuaci�n no tiene ra�ces reales");
        else
            discriminante = sqrt (discriminante);
        raiz1 = ((-b) + discriminante)/(2*a);
        raiz2 = ((-b) - discriminante)/(2*a);
        printf ("Las ra�ces son %f y %f", raiz1, raiz2);
    }
    system("pause");
}
