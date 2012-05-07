//ejercicio8_5.c
#include<stdio.h>
#include<math.h>

float evaluar (float x);

int main (){
    float inicio, fin, medio, epsilon;
    int cont, iteraciones;

    printf("Introduzca el intervalo, el valor de epsilon "
           "y las iteraciones m�ximas\n");
    printf("Use el formato:\n");
    printf("Intervalo: [0, 20], epsilon=0.001, iteraciones= 100000\n");
    scanf("Intervalo: [%f, %f], epsilon=%f, iteraciones=%f",
          &inicio, &fin, &epsilon, &iteraciones);
    cont=0;
    medio = inicio;
    //si ambos extremos del intervalo tienen el mismo signo
    if (evaluar(inicio)*evaluar(fin)>0){
        printf ("Hay un n�mero par de ra�ces en ese intervalo");
        system("pause");
        return 0;
    }
    //mientras no se ejecuten demasiadas iteraciones y
    //no tengamos una aproximaci�n suficientemente buena a la ra�z
    while (cont<iteraciones && fabs(evaluar(medio))> epsilon){
        cont++;
        medio=(inicio+fin)/2;
        //si el signo de la funci�n en inicio y en medio es diferente la ra�z
        //estar� en el intervalo [inicio, medio]
        if ((evaluar(inicio)*evaluar(medio))<0){
            fin=medio;
        }
        //si no estar� en el intervalo [medio, fin]
        else{
            inicio=medio;
        }
    }
    if (cont<iteraciones){
        printf("La ra�z es %f",medio);
    }
    else{
        printf ("El algoritmo no convergi� en el n�mero de iteraciones estipulado");
    }
    system("pause");
    return 0;
}

float evaluar (float x){
    return (exp (1/x)- pow (x,4));
}
