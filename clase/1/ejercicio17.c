//Tamaño en memoria
#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[])
{
	int a;
	short b;
	char c;
	float d;
	double e;
	long f;
	long double g;
	long int h;
	short int i;
	unsigned long int j;
	unsigned short int k;
	unsigned int l;

	printf("El espacio en memoria de int es %d\n", sizeof(a)); //4
	printf("El espacio en memoria de short es %d\n", sizeof(b)); //2
	printf("El espacio en memoria de char es %d\n", sizeof(c)); //1
	printf("El espacio en memoria de float es %d\n", sizeof(d)); //4
	printf("El espacio en memoria de double es %d\n", sizeof(e)); //8
	printf("El espacio en memoria de long es %d\n", sizeof(f)); //4
	printf("El espacio en memoria de long double es %d\n", sizeof(g)); //12
	printf("El espacio en memoria de long int es %d\n", sizeof(h)); //4
	printf("El espacio en memoria de short int es %d\n", sizeof(i)); //2
	printf("El espacio en memoria de unsigned long int es %d\n", sizeof(j)); //4
	printf("El espacio en memoria de unsigned short int es %d\n", sizeof(k)); //2
	printf("El espacio en memoria de unsigned int es %d\n", sizeof(l)); //4

	return 0;

}