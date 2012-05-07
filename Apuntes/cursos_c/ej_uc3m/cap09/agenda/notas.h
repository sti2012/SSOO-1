/* 
 * Programa:    prog09_10
 * Fichero:     notas.h
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 9:
 *              Implementación del módulo notas utilizando 
 *              un array de cadenas de caracteres.
 */


#ifndef NOTAS_H
#define NOTAS_H

#include <stdio.h>


/* 
 * Archivo notas.h
 * incluye la definición de tipos y declaración de prototipos
 */
#define MAX_TAM_NOTA    1024  /* tamaño máximo de una nota */
#define MAX_NOTAS       1000  /* número máximo de notas  */ 

/* definición del tipo ListaNotas */
typedef char  *ListaNotas[MAX_NOTAS];



 /* 
  * Declaración de los prototipos 
  * Las funciones devuelven 0 si se ejecutan con éxito 
  * y -1 en caso de error
  */

/* Inicia una lista de notas vacías */
int iniciarListaNotas(ListaNotas l);

/* Inserta una nueva nota */
int insertarNota(ListaNotas l, char *nota);

/* Visualiza todas las notas */ 
int mostrarNotas(const ListaNotas l);

/* Borra la nota situada en la posición lógica nota */
int borrarNota (ListaNotas l, int nota);

/* Destruye la lista de notas */
int destruirListaNotas(ListaNotas l);

#endif


