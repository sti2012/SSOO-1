// Funciona, pero
// No se como comprobar que no se ha insertado un numero.

/* Ejercicio 14.3.  (valorAbsoluto.c)
    codifica una función que devuelva el valor absoluto del número
    entero pasado como parámetro a dicha función. Comprueba que
    la función funciona correctamente para los valores: 13, -2, -1000,
    0, 23.
*/

#include <stdio.h>
#include <stdlib.h>

int absoluto(float x)
{
  float y;
  if (x >= 0)
  {
    y = x;
    return y;
  }
  else if (x < 0)
  {
    y = x*(-1);
    return y;
  }

/*  else 
  {
    y = -1;
    return y;
  }*/

}

int main()
{
  float numero;
  float resultado;
  printf("Escribe un numero: ");
  scanf("%f", &numero);
  resultado = absoluto(numero);
  printf("El valor absoluto de %.f es %.f\n", numero, resultado);

/*  if (resultado != -1)
  {
    printf("El valor absoluto de %.f es %.f\n", numero, resultado);
  }
  else if (resultado == 0 && numero != 0)
  {
    printf("Ha habido un error. Inserta un numero");
  }*/

  return 0;
}