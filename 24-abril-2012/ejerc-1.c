/*
		Hacer un programa que:                                     
	    a) Lea una secuencia de 20 valores numericos reales y los almacene en una tabla de nombre 'numeros'.              
	    b) Muestra en pantalla cual es el valor maximo, asi  como la 
	    posicion que ocupa en la tabla. En caso de aparecer repetido 
	    el valor maximo se muestra el de menor indice.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
	    {
	    	printf("Escribe 20 numeros reales:\n");
	    	int numeros[20];
	    	int *pnumeros=numeros;
	    	for (int i = 0; i < 20; ++i)
	    	{
	    		printf("%d.-",i+1);
	    		
	    		//fgets(*pnumeros,20,stdin);
	    	}
	    	printf("%d\n",numeros);
	    	return 0;
	    }	    