#ifndef DDICCIO
#define DDICCIO

#include <string>
using std::string;

struct Capital {
   string  ciudad;
   long    distancia;
};

// Declaracion de la clase Diccionario

class Diccionario {
    virtual Capital * pActual ()=0;
  public:
    long buscar (string clave);
    void listar (long a, long b);
    virtual void empezar()=0;
    virtual int fin()=0;
    virtual void sucesor()=0;
};

#endif
