#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

template <class C>
class Pila {
  C *datos;
  int cuantos;
  int llenos;
public:
  Pila (int n) {
    // Crea una pila de tama¤o n
    llenos = 0;
    cuantos = n;
    datos = new C[n];
  }
  ~Pila () {
    /* Destruye la pila y devuelve
       el espacio de los datos */
    delete[] datos;
  }
  void push (C dato) throw (int) {
    // Introduce un dato en la pila
    // Comprueba si la pila est  llena
    if (llenos==cuantos) throw 1;
    datos[llenos++] = dato;
  }
  C pop () throw (int) {
    // Saca un dato de la pila
    // Comprueba si la pila est  vac¡a
    if (llenos==0) throw -1;
    return datos[--llenos];
  }
};

void main () {
  Pila<int> p(3);
  try {
    for (;;) {
      cout << "Escriba un n£mero para meterlo en la pila: ";
      cin >> n;
      p.push(n);
    }
  } catch (int n) {
    cout << "La pila ha rebosado" << endl;
  }
  try {
    cout << "Ahora vamos a sacar los valores
             de la pila" << endl;
    for (;;) cout << p.pop() << endl;
  } catch (int n) {
    cout << "La pila est  vac¡a" << endl;
  }
  cout << "Escriba 0 para terminar" << endl;
  cin >> n;
}
