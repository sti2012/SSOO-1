#include <stdio.h>

void main (int argc, char *argv[], char *envp[])
{
	long i;

	for (i=0; envp[i]; i++)
		printf ("%s\n", envp[i]);
}