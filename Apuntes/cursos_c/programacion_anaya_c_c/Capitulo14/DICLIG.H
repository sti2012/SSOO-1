#ifndef DDICLIG
#define DDICLIG

#include "diccio.h"
#include "lista.h"

// Declaracion de la clase DiccionarioLigado

class DiccionarioLigado : public Diccionario {

    Lista<Capital> lista;

    Capital * pActual () {
      return lista.extraer();
    }

  public:

    void empezar() {
      lista.empezar();
    }

    int fin() {
      return lista.fin();
    }

    void sucesor() {
      lista.sucesor();
    }

    int insertar (string clave, long valor);
};

#endif
