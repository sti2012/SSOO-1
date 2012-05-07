#ifndef DICCIONARIOCONSECUTIVO
#define DICCIONARIOCONSECUTIVO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct {
	char   ciudad [MAX];
	long   distancia;
} Elemento;

typedef struct {
	Elemento  * elem;
	long      maximo;
	long      ultimo;
} DiccionarioConsecutivo; 

int  iniciar  (DiccionarioConsecutivo *, long);
void terminar (DiccionarioConsecutivo *);
int  insertar (DiccionarioConsecutivo *, 
	           char *, long);
long buscar   (DiccionarioConsecutivo *, char *);
void listar   (DiccionarioConsecutivo *, long, long);

#endif