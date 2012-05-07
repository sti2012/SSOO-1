#include <iostream>
#include <valarray>

using namespace std;

void main ()
{
	valarray<int> x (2, 4);
  
	x = x * 3;

	cout << x.sum () << endl;
}
