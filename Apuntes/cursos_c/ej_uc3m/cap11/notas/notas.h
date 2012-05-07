/* 
 * Programa:    notas
 * Fichero:     notas.h
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              Implementación del módulo notas utilizando 
 *              una estructura autoreferenciada
 */


/*
 * Fichero : notas.h
 */


#ifndef NOTAS_H
#define NOTAS_H

/*
 * Ficheros include
 */
#include <stdio.h>

/*
 * Constantes
 */

#define NOTA_MAX    1024        /* tamaño máximo de una nota */

/*
 * Tipos de datos
 */

 typedef struct InfoNota * ListaNotas;
 typedef struct InfoNota   Nota;

 struct InfoNota 
 {
	 char *notas;
         ListaNotas resto;
 };



/*
 * Prototipos de funciones publicas
 */

/* Inicia una lista de notas vacías */
int iniciarListaNotas(ListaNotas *notas);

/* Inserta una nueva nota */
char *insertarNota (ListaNotas * notas, char *mensaje);

/* Visualiza todas las notas */ 
int mostrarNotas(const ListaNotas *notas);

/* Borra la nota situada en la posición lógica nota */
void  borrarNota (ListaNotas * notas, int posicion);

/* Destruye la lista de notas */
void destruirListaNotas (ListaNotas * notas);

#endif


