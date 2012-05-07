#include <fstream>
#include <iostream>
#define MAX 20

using std::cout;
using std::endl;
using std::ifstream;
using std::ios_base;

struct Elemento {
  char   ciudad [MAX];
  long	 distancia;
};

int main()
{
   Elemento   x;
   ifstream   f ("datos.bin", ios_base::binary);

   if (!f)
   {
     cout << "No se pudo abrir el archivo"
          << endl;
     return 1;
   }

   f.read ((char *) &x, sizeof x);
   cout << x.ciudad << " : " << x.distancia << endl;
   
   f.close ();
   return 0;
}
