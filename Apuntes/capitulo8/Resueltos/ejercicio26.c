/*
*ejemplox_26.c
*/
#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones 
int  introducirHora();
int  conversionHoraria(int x);
void impresionHoraria(int x, int y);

int main(int argc, char *argv[])
{
  int hora24=0,hora12=0;
  
  printf("Conversión horaria de 24 horas a 12 horas\n");
  
  hora24 = introducirHora();
  hora12 = conversionHoraria(hora24);
  impresionHoraria(hora24,hora12);
  
  system("PAUSE");	
  return 0;
}
 
int introducirHora()
{
  int hora=0;
  int horaValida;
  do // bucle de para comprobar que la hora introducida es correcta
  {
   horaValida=1;
   printf("Introduzca la hora por pantalla en formato 24 horas \n"
          "Ejemplo 14:45 se introducira 1445 \n");
   scanf(" %d",&hora); 
    if (hora/100<1 || hora/100>24)
      {
       printf("Hora introducida no valida\n");
       horaValida=0;
      }  
    else if ( (hora %100)>59 )
     {
      printf("Minutos introducidos no validos\n");
      horaValida=0;
      }         
   } while (!horaValida); 
   return hora;
}

int conversionHoraria(int x) {
   int hora12=0;
   if (x/100>12) {
     // Las horas a partir de las 12:00 se codifican como un número
     // positivo
     hora12 = (x/100-12)*100+x%100;
   }
   else if (x/100<=12) {
     // Las horas hasta las 12:00 se codifican como un número negativo
     hora12 = -x;
   }
   return hora12; 
}   

void impresionHoraria (int x, int y) {
  if (y<0)
  {
    printf("La hora en formato 24 horas es: %d:%d\n",x/100,x%100);
    printf("La hora en formato 12 horas es: %d:%d AM\n",-y/100,-y%100);
  }
  else if ( y > 0)
  { 
    printf("La hora en formato 24 horas es: %d\n",x);
    printf("La hora en formato 12 horas es: %d:%d PM\n",y/100,y%100);
  }
}       
