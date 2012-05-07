#include <fstream>

using std::ofstream;
using std::endl;

void main () {
  ofstream p;

  p.open ("otro.txt");

  p << "Albacete " << 246 << endl;
  p << "Alicante " << 412 << endl;
  p << "Almeria" << 607;

  p.close ();
}
