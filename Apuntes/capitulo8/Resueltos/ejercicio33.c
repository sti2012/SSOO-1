/*
*ejemplox_33.c
*/
#include <stdio.h>
#include <stdlib.h>

float metrosapies(float metros){
  return metros/0.3048;
}

float piesametros(float pies){
  return pies*0.3048;
}

void convertirLongitud(){
  int eleccion;
  float cantidad;

  printf("Introduzca la cantidad -> ");
  scanf(" %f",&cantidad);

  do {
    printf("Si la cantidad introducida son metros, teclee un 1\n"
           "Si la cantidad introducida son pies, teclee un 2\n");
    scanf(" %d",&eleccion);
  } while (eleccion!=1 && eleccion!=2);
  if (eleccion==1) {
     printf("%f metros son %f pies\n",cantidad,metrosapies(cantidad));
  }
  else 
  {
     printf("%f pies son %f metros\n",cantidad,piesametros(cantidad));
  }
}

float kilosalibras(float kilos){
  return kilos*2.2046;
}

float librasakilos(float libras){
  return libras/2.2046;
}

void convertirPeso(){
  int eleccion;
  float cantidad;

  printf("Introduzca la cantidad -> ");
  scanf(" %f",&cantidad);

  do {
    printf("Si la cantidad introducida son kilos, teclee un 1\n"
           "Si la cantidad introducida son libras, teclee un 2\n");
    scanf(" %d",&eleccion);
  } while (eleccion!=1 && eleccion!=2);
  if (eleccion==1) {
     printf("%f kilos son %f libras\n",cantidad,kilosalibras(cantidad));
  }
  else 
  {
     printf("%f kilos son %f libras\n",cantidad,librasakilos(cantidad));
  }
}

int main()
{
  int eleccion;
  do{
    printf(" Si desea convertir unidades de longitud, teclee un 1\n");
    printf(" Si desea convertir unidades de peso, teclee un 2\n");
    scanf(" %d",&eleccion);
  } while (eleccion!=1 && eleccion!=2);
  if (eleccion==1) convertirLongitud();
  else convertirPeso();
  system("PAUSE");	
  return 0;
}
