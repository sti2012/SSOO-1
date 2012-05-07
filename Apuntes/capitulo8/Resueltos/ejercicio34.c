/*
*ejemplox_34.c
*/
#include <stdio.h>
#include <stdlib.h>

float calcularArea(float a, float b, float c) {
        float s;
        s=(a+b+c)/2;
        float aux=s*(s-a)*(s-b)*(s-c);
        if (aux>0) return sqrt(aux);
        else return -1;
}

int main()    {
       float a, b, c, area;
       printf("Introduzca los lados del triángulo deseado (a b c):\n");
       scanf(" %f %f %f",&a,&b,&c);
       area=calcularArea(a,b,c);
       if (area<0) printf("No existe ningún triángulo con los lados dados\n");
       else printf("El área del triángulo es: %f\n",area);
  system("PAUSE");	
  return 0;
}

