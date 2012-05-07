#ifndef DLISTA
#define DLISTA

template <class C>
class Lista;

// Declaraci¢n de una plantilla para la clase Elemento
template <class C>
class Elemento {
  C dato;
  Elemento<C> * siguiente;
  friend class Lista<C>;
public:
  Elemento (C dato) {
    this->dato = dato;
    this->siguiente = NULL;
  }
};

// Declaraci¢n de una plantilla para la clase Lista
template <class C>
class Lista {
  Elemento<C> * primero;
  Elemento<C> * actual;
  Elemento<C> * previo;
public:
  Lista ( )
  {
    primero = NULL;
    actual  = NULL;
    previo  = NULL;
  }

  ~Lista ();

  void empezar() {
    actual = primero;
    previo = NULL;
  }

  int fin() {
    return actual == NULL;
  }

  void sucesor() {
    previo = actual;
    actual = actual->siguiente;
  }

  C *extraer () {
    return &actual->dato;
  }

  void agregar (C *dato);
  void agregarUnico (C *dato);
};

template <class C> Lista<C>::~Lista () {
previo = primero;
while (previo) {
  actual = previo->siguiente;
  delete previo;
  previo = actual;
}
}

template <class C>
void Lista<C>::agregar (C *dato) {
// Busca el £ltimo elemento
for (empezar(); !fin(); sucesor());
actual = new Elemento<C>(*dato);
if (previo) previo->siguiente = actual;
else primero = actual;
}

class Repetido {
public:
  string mensaje;
  Repetido (string m) {
    mensaje = m;
  }
};

template <class C>
void Lista<C>::agregarUnico (C *dato)
{
// Comprueba si el dato est  en la lista
for (empezar(); !fin(); sucesor())
  if (dato->igual(extraer()))
    break;
if (fin()) {
  actual = new Elemento<C>(*dato);
  if (previo) previo->siguiente = actual;
  else primero = actual;
}
else throw Repetido(dato->clave());
}

#endif
