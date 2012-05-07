//ejemplo5_5.c
#include<stdio.h>

//variable global, accesible a todos las funciones
int variableGlobal;
void funcion();

int main (){
    variableGlobal = 1;
    funcion();
    funcion();
    funcion();
    funcion();
    printf("\n Valor final de variableGlobal= %d\n",variableGlobal);
    system("pause");
    return 0;
}

void funcion(){
    //la inicialización sólo se realiza la primera vez
    static int variableStatic=1;
    //es equivalente a int variableAuto= 0;
    //la inicialización se realiza cada vez que se llama a la función
    auto int variableAuto= 0;
    variableGlobal=variableGlobal++;
    //para todas las llamadas el valor resultante será 1
    variableAuto++;
    printf("\nLlamada %d: variableGlobal= %d, variableAuto=%d ",
           variableStatic,variableGlobal,variableAuto);
    //el valor se conserva de llamada a llamada
    variableStatic++;
}
