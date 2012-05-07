#include <iostream>

using std::cout;
using std::endl;

void main () {
  cout.width (5);
  cout.fill ('#');
  cout << 23 << endl;
  cout.width (5);
  cout << 'a' << endl;
  cout.width (5);
  cout << "caballo" << endl;
}  
