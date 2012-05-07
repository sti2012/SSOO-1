#ifndef DICCIONARIOCONSECUTIVO
#define DICCIONARIOCONSECUTIVO

#include <string>

using std::string;

struct Elemento {
	string ciudad;
	long   distancia;
};

struct DiccionarioConsecutivo {
	Elemento  * elem;
	long      maximo;
	long      ultimo;
};

void  iniciar  (DiccionarioConsecutivo *, long);
void  terminar (DiccionarioConsecutivo *);
void  insertar (DiccionarioConsecutivo *, string, long);
long  buscar   (DiccionarioConsecutivo *, string);
void  listar   (DiccionarioConsecutivo *, long, long);

#endif
