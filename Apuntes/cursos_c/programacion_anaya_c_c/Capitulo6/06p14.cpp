#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::left;
using std::internal;

void main () {
  cout << setw(5) << setfill ('#') << -23 << endl;
  cout << setw(5) << left << -23 << endl;
  cout << setw(5) << internal << -23 << endl;
}
