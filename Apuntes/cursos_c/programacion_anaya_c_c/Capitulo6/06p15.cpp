#include <iostream>

using std::cout;
using std::endl;
using std::scientific;
using std::fixed;

void main () {
  cout << 1234.56789 << endl;
  cout << scientific << 1234.56789 << endl;
  cout << fixed << 1234.56789 << endl;
}
