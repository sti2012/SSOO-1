#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Nivel0 {
  public:
    Nivel0 () {
      cout << "Constructor de nivel 0" << endl;
    }
    ~Nivel0 () {
      cout << "Destructor de nivel 0" << endl;
    }
};

class Nivel1 : public Nivel0 {
  public:
    Nivel1 () {
      cout << "Constructor de nivel 1") << endl;
    }
    ~Nivel1 () {
      cout << "Destructor de nivel 1" << endl;
    }
};

class Nivel2 : public Nivel1 {
  public:
    Nivel2 () {
      cout << "Constructor de nivel 2") << endl;
    }
    ~Nivel2 () {
      cout << "Destructor de nivel 2" << endl;
    }
};

void main(void)
{
  Nivel2 v;
}
