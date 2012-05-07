#include <stdio.h>

void main (void) 
{
	long    i;
	double  euros;

	printf ("pesetas euros\n");
	for (i=1; i<10; i++) 
	{
		euros = 1000 * i / 166.386;
		printf ("%5d %5.0lf\n", 1000 * i, euros);
	}
}