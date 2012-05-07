#include <iostream>

using std::cout;
using std::ios_base;

void main () 
{
  cout.setf (ios_base::oct, ios_base::basefield);
  cout << 23;
}
