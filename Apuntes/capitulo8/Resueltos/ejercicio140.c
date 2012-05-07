/*
*ejemplox_140.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128
#define INC 4

char **leeLineas(int *leidas);
void destruyeLineas(char *lineas[], int leidas);
void imprimeAlReves(char *lineas[], int leidas);

int main()
{
    char **lineas = NULL;
    int leidas = 0;
    
    lineas = leeLineas(&leidas);

    printf("Las líneas que ha introducido en orden inverso son:\n");
    imprimeAlReves(lineas, leidas);
    
    destruyeLineas(lineas, leidas);
    
    system("PAUSE");	
    return 0;
}
 

char **leeLineas(int *leidas)
{
    char lectura[MAX];
    char *linea;
    char **lineas = NULL;
    unsigned int asignadas=0;

    printf("Introduzca lineas de texto (máximo %d caracteres). ", MAX);
    printf("Para terminar teclee 'fin'\n");

    *leidas = 0;
    scanf("%s", lectura);
    while (strcmp(lectura, "fin") != 0) {
          
   linea = malloc(strlen(lectura) + 1);
	if (linea == NULL) {
	    printf("Error en la asignación de memoria!\n");
	    exit(0);
	}
	strcpy(linea, lectura);

	if (asignadas <= *leidas) {
        asignadas += INC;
	    lineas = (char **)realloc(lineas, asignadas * sizeof(char *));
	    if (lineas == NULL) {
		printf("Error en la asignación de memoria!\n");
		exit(0);
	    }
	}
	lineas[(*leidas)++] = linea;
	scanf("%s", lectura);
    }
    return lineas;
}  

void destruyeLineas(char *lineas[], int leidas)
{
    int i;

    for (i=0; i < leidas; i++) {
	free(lineas[i]);
    }
    free(lineas);
}
 
void imprimeAlReves(char *lineas[], int leidas)
{
    int i;

    for(i=leidas; i>0; i--) {
        printf("Linea %d: <%s>\n", i, lineas[i-1]);
    }
}
