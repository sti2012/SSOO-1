#include <iostream>

using std::cout;
using std::ostream;

ostream & tab (ostream & os)
{
  return os << '\t';
}

void main ()
{
  cout << 4 << tab << 5;
}
