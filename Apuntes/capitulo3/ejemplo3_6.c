
#include <stdio.h>
#include <stdlib.h>//para obtener las funciones srand y rand
#include <time.h>//para obtener la función time
//#include <conio.h>
int main(){
    int veces=0;
    int primitiva[6];
    //se inicializar la rutina de generación de números aleatorios
    srand(time(NULL));
   for (veces=0;veces<6;veces++)
    {
    
       primitiva[veces] = rand()% 50 +1; //se genera un número aleatorio entre 0 y 100
      
    }
    printf("los numeros de esta noche son: \n");
    for (veces=0;veces<6;veces++)
    {    
    printf("%d ",primitiva[veces]);
    printf("\n");
   }
    system("pause");
    return 0;
}
