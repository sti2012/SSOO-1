/*
*ejemplox_48.c
*/
#include <stdio.h>
#include <stdlib.h>

void introducirDatos(char* diaComienzo, int* horaComienzo,
   int* minutosComienzo, int* duracionMinutos)
{
   int valida=0;
   do {
      const char dias[] = "LMXJVSD";
      int i; 
      printf("Introduzca el día de comienzo de la llamada: ");
      scanf(" %c",diaComienzo);
      for (i=0; i<7; i++) {
          if (*diaComienzo == dias[i]) {
              valida=1;
              break;
          }
      }
      if (!valida) {
          printf("El día introducido no es válido\n");
      }
   } while (!valida);

   valida=0;
   do {
      printf("Introduzca la hora de comienzo de la llamada: ");
      scanf(" %d",horaComienzo);
      if (*horaComienzo>=0 && *horaComienzo<=23) valida=1;
      else printf("La hora introducida no es válida\n");
   } while (!valida);

   valida=0;
   do {
      printf("Introduzca el minuto de comienzo de la llamada: ");
      scanf(" %d",minutosComienzo);
      if (*minutosComienzo>=0 && *minutosComienzo<=59) valida=1;
      else printf("Los minutos introducidos no son válidos\n");
   } while (!valida);

   valida=0;
   do {
      printf("Introduzca la duración en minutos de la llamada: ");
      scanf(" %d",duracionMinutos);
      if (*duracionMinutos>=0) valida=1;
      else printf("La duración introducida no es válida\n");
   } while (!valida);
}

long int convertirHoraComienzo(char diaComienzo, int horaComienzo,
      int minutosComienzo) {
   long int minutoAbsoluto=0;
   switch (diaComienzo) {
      case 'L': break;
      case 'M': minutoAbsoluto+=  24*60; break;
      case 'X': minutoAbsoluto+=2*24*60; break;
      case 'J': minutoAbsoluto+=3*24*60; break;
      case 'V': minutoAbsoluto+=4*24*60; break;
      case 'S': minutoAbsoluto+=5*24*60; break;
      case 'D': minutoAbsoluto+=6*24*60; break;
   }
   minutoAbsoluto+=horaComienzo*60;
   minutoAbsoluto+=minutosComienzo;
   return minutoAbsoluto;
}

float calcularCoste(long int comienzoAbsoluto, int duracionMinutos)
{
   long int limiteFranja[12]={
                 0, /* Lunes   0'00 */
              8*60, /* Lunes,  8'00 */
             16*60, /* Lunes, 16'00 */
       24*60+ 8*60, /* Martes,  8'00 */
       24*60+16*60, /* Martes, 16'00 */
     2*24*60+ 8*60, /* Miércoles,  8'00 */
     2*24*60+16*60, /* Miércoles, 16'00 */
     3*24*60+ 8*60, /* Jueves,     8'00 */
     3*24*60+16*60, /* Jueves,    16'00 */
     4*24*60+ 8*60, /* Viernes,    8'00 */
     4*24*60+16*60, /* Viernes,   16'00 */
     7*24*60        /* Domingo,   24'00 */
   };
   float costeFranja[11]={
              0.03, /* Lunes   0'00 */
              0.12, /* Lunes,  8'00 */
              0.03, /* Lunes, 16'00 */
              0.12, /* Martes,  8'00 */
              0.03, /* Martes, 16'00 */
              0.12, /* Miércoles,  8'00 */
              0.03, /* Miércoles, 16'00 */
              0.12, /* Jueves,     8'00 */
              0.03, /* Jueves,    16'00 */
              0.12, /* Viernes,    8'00 */
              0.03  /* Viernes,   16'00 */
   };
   int franjaHoraria, maximoMinutos;
   long int nuevoComienzoAbsoluto;
   
   if (duracionMinutos==0) return 0;
 
   // Encontrar la franja horaria del comienzo de la llamada
   franjaHoraria=0;
   while (comienzoAbsoluto>=limiteFranja[franjaHoraria+1])
      ++franjaHoraria;
   
   // Calcular el número de minutos desde el comienzo de la llamada
   // hasta el final de la franja
   maximoMinutos=limiteFranja[franjaHoraria+1]-comienzoAbsoluto;
   
   // Si la llamada dura menos que el máximo de minutos dentro de la franja
   if (duracionMinutos<maximoMinutos)
      return duracionMinutos*costeFranja[franjaHoraria];
   
   // Si la llamada dura más que el máximo de minutos dentro de la franja
   // calcular el coste dentro de la franja y sumar el coste del resto de
   // la llamada
   nuevoComienzoAbsoluto=limiteFranja[franjaHoraria+1];
   if (nuevoComienzoAbsoluto==7*24*60) // Domingo 24'00 = Lunes 0'00
       nuevoComienzoAbsoluto=0;
   return duracionMinutos*costeFranja[franjaHoraria]+
      calcularCoste(nuevoComienzoAbsoluto, duracionMinutos-maximoMinutos);  
}

int main()
{
   char diaComienzo;
   int horaComienzo, minutosComienzo, duracionMinutos, comienzoAbsoluto;
   float coste;
   // Leer los datos de entrada
   introducirDatos(&diaComienzo, &horaComienzo, &minutosComienzo,
      &duracionMinutos);
   
   // Calcular en qué minuto de la semana comenzó la llamada
   comienzoAbsoluto=convertirHoraComienzo(diaComienzo, horaComienzo,
      minutosComienzo);
   
   // Calcular el coste de la llamada
   coste=calcularCoste(comienzoAbsoluto,duracionMinutos);
   printf("El coste de la llamada es %f euros\n",coste);
   system("PAUSE");	
  return 0;
}
