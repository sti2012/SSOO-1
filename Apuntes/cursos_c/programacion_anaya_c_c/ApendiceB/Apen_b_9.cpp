#include <iostream>
#include <string>
using namespace std;

void main () 
{
	string s = "catarata";

	int i = s.find ("ta");	
	int j = s.rfind ("ta");

	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
}
