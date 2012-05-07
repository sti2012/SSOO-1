//ejemplo7_2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para poder usar strncpy

struct Estructura{
	char    letra;
	long    entero;
	float   real;
	char    cadena1[256];
	char    *cadena2;
	//El lenguaje C trata los arrays y los punteros de la misma forma 
}; //Se termina con ; o se ponen los nombres de las estructuras

int main ()
{                           
	struct Estructura estructura1 = {'a', 23L, 4.5, "Hola", "Estructura"}; // Trata el 23 como long
	struct Estructura estructura2;
	struct Estructura estructura3;

	estructura2 = estructura1; //Asignacion de estructuras completas
	estructura3.letra = 'b'; //Trabajo con el operador punto. El operador punto (dot) es para acceder a los datos de las estructuras
	estructura3.entero = 2345L;
	estructura3.real = 234.678;
	strncpy(estructura3.cadena1, "Cadena1",19); //No usamos strcpy para no crear un programa inseguro
	estructura3.cadena2 = (char *) malloc(128 * sizeof(char)); //Siempre que haya un malloc, tiene que haber un free. Malloc es asignacion automatica en memoria
												//^Para que las posiciones de memoria sean tipo char
	strncpy(estructura3.cadena2, "Cadena2",25); //Arrays de caracteres
	printf("%c\n", estructura3.letra );
	printf("%ld\n", estructura3.entero );
	printf("%f\n", estructura3.real );
	printf("%s\n", estructura3.cadena1 );
	printf("%s\n", estructura3.cadena2 );
	free (estructura3.cadena2);
	system("pause"); //Windows
	return 0;
}
