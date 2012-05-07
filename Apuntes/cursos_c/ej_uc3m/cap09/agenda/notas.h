/* 
 * Programa:    prog09_10
 * Fichero:     notas.h
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 9:
 *              Implementaci�n del m�dulo notas utilizando 
 *              un array de cadenas de caracteres.
 */


#ifndef NOTAS_H
#define NOTAS_H

#include <stdio.h>


/* 
 * Archivo notas.h
 * incluye la definici�n de tipos y declaraci�n de prototipos
 */
#define MAX_TAM_NOTA    1024  /* tama�o m�ximo de una nota */
#define MAX_NOTAS       1000  /* n�mero m�ximo de notas  */ 

/* definici�n del tipo ListaNotas */
typedef char  *ListaNotas[MAX_NOTAS];



 /* 
  * Declaraci�n de los prototipos 
  * Las funciones devuelven 0 si se ejecutan con �xito 
  * y -1 en caso de error
  */

/* Inicia una lista de notas vac�as */
int iniciarListaNotas(ListaNotas l);

/* Inserta una nueva nota */
int insertarNota(ListaNotas l, char *nota);

/* Visualiza todas las notas */ 
int mostrarNotas(const ListaNotas l);

/* Borra la nota situada en la posici�n l�gica nota */
int borrarNota (ListaNotas l, int nota);

/* Destruye la lista de notas */
int destruirListaNotas(ListaNotas l);

#endif


