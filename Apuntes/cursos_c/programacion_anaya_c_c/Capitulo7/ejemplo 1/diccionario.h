#ifndef DICCIONARIOCONSECUTIVO
#define DICCIONARIOCONSECUTIVO

#define MAX 20

typedef struct {
  char	ciudad [MAX];
  long	distancia;
} Elemento;

typedef struct {
  Elemento  * elem;
  long      maximo;
  long      ultimo;
} DiccionarioConsecutivo; 

int   iniciar  (DiccionarioConsecutivo *, long);
void  terminar (DiccionarioConsecutivo *);
int   insertar (DiccionarioConsecutivo *, char * clave, 
                long valor);
long  buscar   (DiccionarioConsecutivo *, char * clave);
void  listar   (DiccionarioConsecutivo *, long, long);

#endif
