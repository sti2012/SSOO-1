#include <iostream>

using std::cout;
using std::endl;
using std::ios_base;
using std::ios_base::fmtflags;
using std::ios_base::oct;
using std::ios_base::showbase;

void main () 
{
  fmtflags viejo = cout.flags ();

  fmtflags nuevo = oct | showbase;
  cout.flags (nuevo);
  cout << 23 << endl;

  cout.flags (viejo);
  cout << 23;
}
