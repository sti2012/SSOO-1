//ejemplo5_17.c
#include <stdio.h>
#include <stdlib.h>

void leerPunto(const char *mensaje, float *x, float *y, float *z){
    printf("%s\n",mensaje);
    scanf(" %f %f %f",x,y,z);
}

void calcularVectorDirector(float x1, float y1, float z1,
             float x2, float y2, float z2, float *ux, float *uy, float *uz){
    *ux=x2-x1;
    *uy=y2-y1;
    *uz=z2-z1;
}

int main(){
    float x1,y1,z1,x2,y2,z2,ux,uy,uz;
    leerPunto("Introduzca el primer punto:",&x1,&y1,&z1);
    leerPunto("Introduzca el segundo punto:",&x2,&y2,&z2);
    calcularVectorDirector(x1,y1,z1,x2,y2,z2,&ux,&uy,&uz);
    printf("La recta pasa por el punto (%f,%f,%f)\n"
           "y su vector director es (%f,%f,%f)\n",x1,y1,z1,ux,uy,uz);
    system("PAUSE");
    return 0;
}
