#include <stdio.h>
int main()
{
	typedef struct
	{
		short level;
		unsigned flags;//estado del archivo: lectura, binario
		char fd;
		unsigned char hold;
		short bsize;
		unsigned char *buffer, *curp;
		unsigned istemp;
		short token;
	}FILE;
	return 0;
}