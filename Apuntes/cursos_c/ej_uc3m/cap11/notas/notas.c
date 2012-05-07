/* 
 * Programa:    notas
 * Fichero:     notas.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              Implementación del módulo notas utilizando 
 *              una estructura autoreferenciada
 */



#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include "notas.h"

/* Inicia una lista de notas vacías */
int iniciarListaNotas(ListaNotas *notas)
{
    (*notas) = NULL;
    return (0);
}

/*
 * Función insertarNotas
 */
char *insertarNota (ListaNotas * notas, char *mensaje)
{
    char *copia;
    ListaNotas auxNotas = *(notas);

    /*
     * Añadir una nueva nota
     */
    if (NULL == *(notas)) {
        *(notas) = malloc(sizeof(Nota));
        if (NULL == *(notas)) {
		perror("malloc:");
		return NULL;
	}
        auxNotas = *(notas);
        auxNotas->resto = NULL;
    } else {    
        while (NULL != auxNotas->resto){
            auxNotas = auxNotas->resto;
        }
        auxNotas->resto = malloc(sizeof(Nota));
        if (NULL == *(notas)) {
		perror("malloc:");
		return NULL;
	}
        auxNotas = auxNotas->resto;
        auxNotas->resto = NULL;

    }      
    /*
     *  Inserta una copia.
     */
    copia=malloc(sizeof(mensaje)+1);
    if (NULL == copia) {
		perror("malloc:");
		return NULL;
    }
    strcpy(copia,mensaje);
    auxNotas->notas=copia;
    return copia;
}

/* Visualiza todas las notas */ 
int mostrarNotas(const ListaNotas *notas)
{
    int cont = 0;
    ListaNotas auxNotas = *(notas);
    
    /*
     * Calcular el número de posiciones
     */
    while (NULL != auxNotas) {  
        printf("Nota %d\n", cont);
        printf("---------------\n");
        printf("%s\n", auxNotas->notas);

        auxNotas = auxNotas->resto;
        cont = cont + 1;
    }
    return (cont);

}

/*
 * Función borrarNota
 */
void  borrarNota (ListaNotas * notas, int posicion)
{
    int i;
    ListaNotas auxNotas, auxNotas2;

    if (NULL != *(notas)) {        /* si lista vacia, terminar */
        auxNotas = *(notas);

        if (0 == posicion) {            /* si es la primera posición */
            *(notas) = (*notas)->resto;
            free (auxNotas->notas);
            free (auxNotas);
        } else {                        /* si es otra posición */
            i = 0;
            while ((NULL != auxNotas->resto) && (i < (posicion-1) )) {  
                auxNotas = auxNotas->resto;
                i = i + 1;
            }
            if (NULL != auxNotas->resto) {      /* si esa posición existe */
                auxNotas2 = auxNotas->resto;
                auxNotas->resto = auxNotas->resto->resto;
                free (auxNotas2->notas);
                free (auxNotas2);
            }
        }
    }
}


/*
 * Función destruirNotas
 */
void destruirListaNotas (ListaNotas * notas)
{
    ListaNotas auxNotas = *(notas);

    /*
     *  Libera la memoria de
     *  cada nota
     */
    while (NULL != auxNotas){
        *(notas) = auxNotas->resto;
        free (auxNotas->notas);
        free (auxNotas);
        auxNotas = *(notas);
    }
}

