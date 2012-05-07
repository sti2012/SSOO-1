#include "diccionario.h"

void main () 
{
	DiccionarioConsecutivo	 plano;

	iniciar  (&plano, 5);

	insertar (&plano, "Albacete", 246);
	insertar (&plano, "Caceres", 299);
	insertar (&plano, "Malaga", 542);
	insertar (&plano, "Palencia", 239);
	insertar (&plano, "Toledo", 70);

	listar (&plano, 200, 300);
	terminar (&plano);
}