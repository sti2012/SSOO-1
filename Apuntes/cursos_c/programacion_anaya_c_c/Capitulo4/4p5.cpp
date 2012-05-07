#include <iostream>

using std::cout;
using std::endl;

int main (void)
{
	char *ciudades[] = 
	  {"Albacete", "Alicante", "Almeria", "Avila",
	   "Badajoz", "Barcelona", "Bilbao", "Burgos",
	   "Caceres", "Cadiz", "Castellon", "Ciudad_Real",
	   "Cordoba", "Coruna", "Cuenca", "Gerona", "Granada",
	   "Guadalajara", "Huelva", "Huesca", "Jaen", "Leon",
	   "Lerida", "Logrono", "Lugo", "Malaga", "Murcia",
	   "Orense", "Oviedo", "Palencia", "Pamplona",
	   "Pontevedra", 	"Salamanca", "San_Sebastian",
	   "Santander", "Segovia", "Sevilla",	 "Soria",
	   "Tarragona", "Teruel", "Toledo", "Valencia",
	   "Valladolid", "Vitoria", "Zamora", "Zaragoza"};

	long distancias[] = 
	  {246, 412, 607, 111, 403, 621, 395, 239,	299, 654, 
	   414, 200, 402, 602, 165, 725, 432, 56, 636, 392, 335,
	   325, 466, 333, 507, 542, 388, 531, 444, 239, 411, 649, 
	   211, 468, 398, 88, 542, 277, 559, 315, 70, 350, 193, 
	   353, 249, 322};

	for (int i=0; i<46; i++)
		if (distancias [i] <= 300 && distancias [i] >= 200)
			cout << ciudades [i] << endl;

	return 0;
}
