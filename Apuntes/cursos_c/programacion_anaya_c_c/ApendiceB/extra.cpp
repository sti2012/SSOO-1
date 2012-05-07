#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T> T mediana (vector<T> v)
{
  typedef vector<T>::size_type VS;

  VS dim = v.size ();

  if (!dim)
    throw domain_error ("Vector sin elementos");

  sort (v.begin (), v.end ());

  VS medio = dim / 2;

  if (medio % 2 == 0)
    return (v [medio] + v [medio-1]) / 2;
  else
    return v [medio];
}

void main ()
{
  try
  {
    vector<int> v;

#ifdef CACA
  v.push_back (2);
  v.push_back (3);
  v.push_back (5);
  v.push_back (5);
#endif

  cout << mediana (v) << endl;
  }
  catch (domain_error c)
  {
    cout << c.what ();
  }
}