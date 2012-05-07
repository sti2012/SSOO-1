#include <iostream>

using std::cout;
using std::endl;

void main () 
{
  char cad [] = "una cadena";

  for (char * p = cad; *p; p++);
 
  cout << p-cad << endl;
}
