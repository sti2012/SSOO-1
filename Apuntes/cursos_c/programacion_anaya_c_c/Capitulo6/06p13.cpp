#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::setfill;

void main () {
  cout << setw(5) << setfill('#') << 23 << endl;
  cout << setw(5) << 'a' << endl;
  cout << setw(5) << "caballo" << endl;
}
