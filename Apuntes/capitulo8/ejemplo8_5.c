//ejercicio8_5.c
#include<stdio.h>
#include<math.h>

float evaluar (float x);

int main (){
    float inicio, fin, medio, epsilon;
    int cont, iteraciones;

    printf("Introduzca el intervalo, el valor de epsilon "
           "y las iteraciones máximas\n");
    printf("Use el formato:\n");
    printf("Intervalo: [0, 20], epsilon=0.001, iteraciones= 100000\n");
    scanf("Intervalo: [%f, %f], epsilon=%f, iteraciones=%f",
          &inicio, &fin, &epsilon, &iteraciones);
    cont=0;
    medio = inicio;
    //si ambos extremos del intervalo tienen el mismo signo
    if (evaluar(inicio)*evaluar(fin)>0){
        printf ("Hay un número par de raíces en ese intervalo");
        system("pause");
        return 0;
    }
    //mientras no se ejecuten demasiadas iteraciones y
    //no tengamos una aproximación suficientemente buena a la raíz
    while (cont<iteraciones && fabs(evaluar(medio))> epsilon){
        cont++;
        medio=(inicio+fin)/2;
        //si el signo de la función en inicio y en medio es diferente la raíz
        //estará en el intervalo [inicio, medio]
        if ((evaluar(inicio)*evaluar(medio))<0){
            fin=medio;
        }
        //si no estará en el intervalo [medio, fin]
        else{
            inicio=medio;
        }
    }
    if (cont<iteraciones){
        printf("La raíz es %f",medio);
    }
    else{
        printf ("El algoritmo no convergió en el número de iteraciones estipulado");
    }
    system("pause");
    return 0;
}

float evaluar (float x){
    return (exp (1/x)- pow (x,4));
}
