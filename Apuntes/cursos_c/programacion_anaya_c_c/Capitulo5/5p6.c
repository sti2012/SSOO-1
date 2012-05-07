#include <stdio.h>
#include <stdlib.h>

double media (double * datos, long dim)
{
	long   i;
	double res;

	for (i=0, res=0.0; i<dim; i++)
		res += datos[i];
	return res/dim;
}

void main (int argc, char *argv[])
{
	long    i;
	double  *grupo;

	/* reserva de memoria para grupo  */
	grupo = (double *)
		malloc ((argc-1) * sizeof(double));

	/* las cadenas se transforman a punto flotante  */
	for (i=0; i<argc-1; i++)
		grupo[i] = atof(argv[i+1]);

	printf ("Media = %lf\n", media (grupo, argc-1));

	/* se libera la memoria de grupo */
	free (grupo);
}