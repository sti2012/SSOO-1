#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Cosa {

    static int numeroDeCosas;
    int yo;

  public:
    static Cosa ** cosas;
    // Constructor
    Cosa ()
    {
      if (numeroDeCosas==0) cosas = new Cosa *[10];
      cosas[numeroDeCosas] = this;
      numeroDeCosas++;
      yo = numeroDeCosas;
      cout << "Creando Cosa n£mero " <<
        numeroDeCosas << endl;
    }
    // Destructor
    ~Cosa ()
    {
      cout << "Destruyendo Cosa n£mero " <<
        numeroDeCosas << endl;
      numeroDeCosas--;
      if (numeroDeCosas==0) delete [] cosas;
    }
    // M‚todo ver
    void ver () {
      cout << "Esta es la Cosa n£mero " << yo
        << endl;
    }
    // M‚todo cuantasCosas
    static int cuantasCosas () {
      return numeroDeCosas; }
};

int Cosa::numeroDeCosas = 0;
Cosa ** Cosa::cosas;

void main(void)
{
  Cosa c1, c2, c3, c4;
  for (int i=0; i<Cosa::cuantasCosas(); i++)
    Cosa::cosas[i]->ver();
}
