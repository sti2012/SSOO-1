#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char car='a';
	char saludo[20];
	int x=10;
	char *pcar; // solo declaracion
	int *px=&x; //declaracion e inicializacion
	char *psaludo; 
	pcar=&car; // el puntero pcar apunta a la direccion donde esta almacenada la variable car
	psaludo=saludo;

	printf("SALUDAME\n");
	//scanf("%[^\n]", &saludo);
	fgets(saludo,20,stdin);
	printf("%s\n", saludo);

	printf("x vale %d esta en direccion %p\n", *px, &x);
	printf("x vale %d esta en direccion %p\n", x, px);

	printf("car vale %c esta en direccion %p\n", *pcar, &car);
	printf("car vale %c esta en direccion %p\n", car, pcar);

	printf("la primera letra es %c esta en direccion %p\n", *psaludo[0],&psaludo[0]);
	printf("la segunda letra es %c esta en direccion %p\n", *psaludo,psaludo);
	printf("la tercera letra es %c esta en direccion %p\n", *psaludo[1],&psaludo[2]);

	return 0;
}
/*xterm -e "cd ~/Escritorio/SSOO-1;git push origin master""|less"


#!/bin/bash
git push -u origin master



			object.command = ['xterm','-e','git', 'status','-hold']