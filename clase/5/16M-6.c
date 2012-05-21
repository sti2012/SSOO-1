/* Realiza un programa que nos indique cuantas palabras aparecen en un archivo */ 

#include <stdio.h>
#include <string.h>
int main()
{
	FILE *desc;
	desc = fopen("./16M-6.txt", "r");
	char palabra[1000] = *desc;
	int total;
	printf("test2\n");
	printf("%s", palabra[1000]);
    while(scanf(desc, "%s") != EOF) /* no fin de archivo */
    {
    	printf("test\n");
        /* se compara la palabra leída con "lector" */
        if (strcmp(desc, "lector") == 0)
            total++;
    }
    printf("El número total de veces que aparece lector es %d\n",
            total);
	return 0;

}



	/*int leidos;
	float cantidad;
	char unidad[15], elemento[21];
	do
	{
		leidos = fscanf(stdin, "cantidad: %f %14s de %20s\n", 
					  &cantidad, unidad, elemento);
		if (3 != leidos) {
			fscanf(stdin, "%*[^\n]");
			fscanf(stdin,"\n");
		}
	}while(!feof(stdin) && !ferror(stdin));
	*/
	/*
	char palabra[128];
	int total = 0;

	while (scanf("%s",palabra) != EOF)
	{
		if(strcmp(palabra, "lector") == 0)
			total++;
	}
	printf("El numero total de veces que aparece lector es %d\n", total);
	*/
