/* 
 * Programa:    prog09_10
 * Fichero:     notas.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Implementación del módulo notas utilizando 
 *              un array de cadenas de caracteres.
 */


#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include "notas.h"

/* Inicia una lista de notas vacías */
int iniciarListaNotas(ListaNotas l)
{
    int j;
  
    for (j = 0; j < MAX_NOTAS; j++)
        l[j] = NULL;
    return(0);
}

/* Inserta una nueva nota */
int insertarNota(ListaNotas l, char *nota)
{
    int j = 0;

    /* se recorre la lista hasta encontrar un hueco */
    while ((j < MAX_NOTAS) && (l[j] != NULL))
        j++;

    /* Si hay un hueco libre, j debe ser menor que MAX_NOTAS */
    if (j < MAX_NOTAS) {
        l[j] = (char *)malloc(MAX_TAM_NOTA * sizeof(char));
        strcpy(l[j], nota);
        return(0);
    }
    else
        return(-1);  /* no hay hueco */
}

/* Visualiza todas las notas */ 
int mostrarNotas(const ListaNotas l)
{
    int j = 0;
    int numNotas = 1;  /* contabiliza el número de notas */

    /* se recorre todo el array y se imprime cada nota */
    for(j = 0; j < MAX_NOTAS; j++)
        if (l[j] != NULL) {
            printf("Nota %d\n", numNotas);
            printf("---------------\n");
            printf("%s\n", l[j]);
            numNotas ++;
        }
    return(0);
}

/* Borrar la nota  situada en la posición lógica nota  */
int borrarNota(ListaNotas l, int nota)
{
    int j;
    int num_nota = 1;

    for (j = 0; j < MAX_NOTAS; j++) 
        if (l[j] != NULL)  {
            if(num_nota == nota)
                break;  /* se encontró */
            else
                num_nota ++;
        }
    
    /* si j es manor que MAX_NOTAS, se encontró la nota */
    if (j < MAX_NOTAS) {
         free(l[j]); /* se borra la nota liberando la memoria */
                     /* la posición queda libre para otra nota */
         l[j] = NULL;
         return(0);
    }
    else
        return(-1);   /* La nota no se encontró */
}


/* Destruye la lista de notas */
int destruirListaNotas(ListaNotas l)
{
    int j;

    for(j = 0; j < MAX_NOTAS; j++)
        free(l[j]);
    return(0);
}

