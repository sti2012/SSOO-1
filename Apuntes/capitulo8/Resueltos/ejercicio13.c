/*
*ejemplox_13.c
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, j, productoAB, A, B;
  
  for (i=0; i<=10; ++i) {
      // Solicitar la pareja de n�meros
      printf("Introduzca primer n�mero de la pareja:");
      scanf(" %d",&A);
      printf("Introduzca segundo n�mero de la pareja:");
      scanf(" %d",&B);
      
      // Calcular producto
      productoAB=0;
      for (j=0; j<B; ++j) {
          productoAB+=A;
      }
      
      // Mostrar resultado
      printf("El producto de %d por %d es %d\n",A,B,productoAB);
  }
  system("pause");	
}
