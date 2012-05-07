#ifndef DDICCON
#define DDICCON

#include "diccio.h"

// Declaraci¢n de la clase DiccionarioConsecutivo

class DiccionarioConsecutivo : public Diccionario {

    Capital     * elem;
    long        maximo;
    long        ultimo;
    int         actual;

    Capital * pActual () {
      return &elem[actual];
    }

  public:

    DiccionarioConsecutivo (long n=100)
    {
      elem = new Capital [n];
      maximo = n;
      ultimo = 0;
    }

    ~DiccionarioConsecutivo ()
    {
      delete [] elem;
    }

    void empezar() {
      actual = 0;
    }

    int fin() {
      return actual == ultimo;
    }

    void sucesor() {
      actual++;
    }

    int insertar (string clave, long valor);
};

#endif
