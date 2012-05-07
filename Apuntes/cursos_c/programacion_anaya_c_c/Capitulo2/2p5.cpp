#include <iostream>
#include <string>

typedef struct {
  std::string ciudad;
  long        distancia;
} Elemento;

typedef struct {
  Elemento elem [3];
  long     maximo;
  long     ultimo;
} DiccionarioConsecutivo;

void main (void)
{
  DiccionarioConsecutivo  plano;
 
  /* Inicializacion de plano */
  plano.maximo = 3;
  plano.ultimo = 0;

  /* Insercion de ciudades */
  printf ("Introduzca ciudad y distancia: ");
  std::cin >> plano.elem [0].ciudad;
  std::cin >> plano.elem [0].distancia;
  plano.ultimo++;

  printf ("Introduzca ciudad y distancia: ");
  std::cin >> plano.elem [1].ciudad;
  std::cin >> plano.elem [1].distancia;
  plano.ultimo++;

  printf ("Introduzca ciudad y distancia: ");
  std::cin >> plano.elem [2].ciudad;
  std::cin >> plano.elem [2].distancia;
  plano.ultimo++;
} 

// Albacete Alicante Almeria Avila Badajoz 
// 246 412 607 111 403 
