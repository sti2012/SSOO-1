/* Crea un programa que nos muestre una tabla ASCII */

#include <stdio.h>

int main()
{
	for (int i = ' '; i < 128; ++i)
	{
		printf("%c ", i);
	}
	return 0;
}