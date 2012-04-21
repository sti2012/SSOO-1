// Funciona, pero
// Si en vez de un numero se introduce un caracter se produce un bucle infinito.
// No estoy seguro si las operaciones de la circunferencia son correctas.

/* Ejercicio 16.1  (ejercicio13.2.4c)
     Modificar la solución al ejercicio 13.2 que utilizaba funciones,
     incluyendo una sentencia switch para evaluar la opción introducida por
     el usuario. Hacer que el programa muestre un mensaje de error si la
     opción elegida no es ninguna de las del menú.
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416

int main()
{
  int opcion;
  do
  {
    printf("\n1. Calcular area rectangulo.\n2. Calcular area del triangulo.\n3. Calcular area del circulo.\n4. Calcular longitud de la circunferencia.\n5. Salir.\n");
    printf("\nSelecciona el numero de menu [1-5]: ");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:{
          float lado;
          float area;
          int continuar;
          char respuesta;
    
          continuar = 1;
    
          while (continuar == 1)
          {
             printf("\nIntroduce lado del cuadrado: ");
             scanf("%f", &lado);
             area = lado*lado;
             printf("\nEl area del cuadrado es %.2f.\n", area);
             printf("Desea continuar [S/N]?");
             scanf("\n%c", &respuesta);
             if (respuesta == 'N' || respuesta == 'n')
               continuar = 0;
          }
          break;}
    
    case 2:{
          float base;
          float altura;
          float area;
          int continuar;
          char respuesta;
    
          continuar = 1;
    
          while (continuar == 1)
          {
             printf("\nIntroduce base del triangulo: ");
             scanf("%f", &base);
             printf("\nIntroduce altura del triangulo: ");
             scanf("%f", &altura);
             area = (base*altura)/2;
             printf("\nEl area del triangulo es %.2f.\n", area);
             printf("Desea continuar [S/N]?");
             scanf("\n%c", &respuesta);
             if (respuesta == 'N' || respuesta == 'n')
               continuar = 0;
          }
          break;}

    case 3:{
          float radio;
          float area;
          int continuar;
          char respuesta;
    
          continuar = 1;
    
          while (continuar == 1)
          {
             printf("\nIntroduce radio de la circunferencia: ");
             scanf("%f", &radio);
             area = 2*PI*pow(radio,2);
             printf("\nEl area de la circunferencia es %.2f.\n", area);
             printf("Desea continuar [S/N]?");
             scanf("\n%c", &respuesta);
             if (respuesta == 'N' || respuesta == 'n')
               continuar = 0;
          }
          break;}

    case 4:{
          float radio;
          float area;
          int continuar;
          char respuesta;
    
          continuar = 1;
    
          while (continuar == 1)
          {
             printf("\nIntroduce radio de la circunferencia: ");
             scanf("%f", &radio);
             area = 2*PI*radio;
             printf("\nLa longitud de la circunferencia es %.2f.\n", area);
             printf("Desea continuar [S/N]?");
             scanf("\n%c", &respuesta);
             if (respuesta == 'N' || respuesta == 'n')
               continuar = 0;
          }
          break;}

    case 5:{
          printf("\n* Saliendo *\n");
          break;}

    default:{
          printf("\n* Ha habido un error. Selecciona un numero de menu *\n");}
    }
  } while (opcion != 5);
  return 0;
}