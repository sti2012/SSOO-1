/*
Realiza un programa que pida los nombres y apellidos y los muestre con Don.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> //para frases

int main ()
{
	char nombre[80];
	char don[87] = "Sr. D. " ;
	
//	system("clear"); para windows
	
	printf("Dime un nombre y apelidos: ");
	fgets(nombre,80,stdin) ;
	
	strcat(don, nombre) ; //añade a la cadena don el nombre
	
	printf("\n\nHola %s", don) ;
	return 0;
}
