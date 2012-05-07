/* 
 * Programa:    notas
 * Fichero:     notas.h
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 11:
 *              Implementaci�n del m�dulo notas utilizando 
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

#define NOTA_MAX    1024        /* tama�o m�ximo de una nota */

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

/* Inicia una lista de notas vac�as */
int iniciarListaNotas(ListaNotas *notas);

/* Inserta una nueva nota */
char *insertarNota (ListaNotas * notas, char *mensaje);

/* Visualiza todas las notas */ 
int mostrarNotas(const ListaNotas *notas);

/* Borra la nota situada en la posici�n l�gica nota */
void  borrarNota (ListaNotas * notas, int posicion);

/* Destruye la lista de notas */
void destruirListaNotas (ListaNotas * notas);

#endif


