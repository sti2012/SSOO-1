#include <stdio.h>
#include <string.h>
struct persona
{
	char nombre[50];
	long telefono;
}
void mostrar_persona(struct persona p);
struct persona leer_persona();
int main(int argc, char const *argv[])
{
	struct persona p1;
	p1 = leer_persona();
	mostrar_persona( p1 );
	return 0;
}
void mostrar_persona(struct persona p)
{
	printf ("Nombre: %s\n", p.nombre);
	printf ("Telefono: %ld\n", p.telefono);
}
struct persona leer_persona()
{
	struct persona temp;
	printf ("Nombre? \n");
	gets (temp.nombre);
	printf ("Telefono? \n");
	return temp;
}
