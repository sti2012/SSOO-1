//ejemplo5_2.c
#include <stdio.h>

int variableGlobal = 100;

void funcion (int parametro){
    int variableLocal = 10;
    printf("parametro = %i\n",parametro);
    printf("variable  global = %i\n",variableGlobal);
    printf("variable local = %i\n",variableLocal);
}

int main (){
    int variableLocal = 0;
    printf("variable  global = %i\n",variableGlobal);
    printf("variable local = %i\n",variableLocal);
    funcion (8);
    return 0;
}
