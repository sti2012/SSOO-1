/*
*ejemplox_30.c
*/
#include <stdio.h>
#include <stdlib.h>

int pedirNumeroDeComensales (){
   int N;
   printf("Introduzca el número de personas para el cual se va a cocinar:\n");
   scanf(" %d",&N);
   return N;
}

void calcularIngredientes (int N){
   printf("Los ingredientes necesarios para %d personas son:\n"
          "%f huevos\n"
          "%f kilos de harina\n"
          "%f kilos de azúcar\n"
          "%f sobres de levadura\n",
          N,4.0/4*N,0.5/4*N,0.25/4*N,(float)1/4*N);
}

int main()
{
  calcularIngredientes(pedirNumeroDeComensales());
  system("PAUSE");	
}
