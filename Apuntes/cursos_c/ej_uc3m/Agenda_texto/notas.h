/*
 * Programa: agenda
 * Modulo  : notas
 * Fichero : notas.h
 */

#ifndef _NOTAS_H_
#define _NOTAS_H_

/*
 * FICHEROS INCLUDES
 */
#include "util.h"


/*
 * CONSTANTES
 */

#define NOTA_MAX    1024


/*
 * TIPOS DE DATOS
 */
typedef struct InfoNota * ListaNotas;
typedef struct InfoNota   Nota;

struct InfoNota 
{
    char *     notas;
    ListaNotas resto;
};


/*
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/* 
 * Funci�n: crearNotas()
 * 
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Devuelve la lista de notas creada (ListaNotas)
 *
 * Descripci�n: 
 *      Crea la lista de notas
 */
ListaNotas crearNotas    (void);

/* 
 * Funci�n: destruirNotas()
 * 
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas a destruir
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Destruye la lista de notas
 */
void    destruirNotas (ListaNotas * notas);

/* 
 * Funci�n: insertarNotas()
 * 
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas donde insertar 
 *      char * mensaje: nota a insertar 
 *      
 * Par�metros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      inserta una nota en la lista de notas
 */
int     insertarNotas (ListaNotas * notas, char * mensaje);

/* 
 * Funci�n: borrarNotas()
 * 
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas donde borrar 
 *      int posicion: posici�n de la nota a borrar 
 *      
 * Par�metros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      borra una nota de la lista de notas
 */
int     borrarNotas   (ListaNotas * notas, int posicion);

/* 
 * Funci�n: consultarNotas()
 * 
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas donde consultar
 *      int posicion: posici�n de la nota a consultar 
 *      
 * Par�metros de salida:
 *      Devuelve la nota si ha ido bien (char *), NULL en caso contrario
 *
 * Descripci�n: 
 *      consulta una nota de la lista de notas
 */
char *  consultarNotas (const ListaNotas * notas, int posicion);

/* 
 * Funci�n: numeroNotas()
 * 
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas  
 *      
 * Par�metros de salida:
 *      Devuelve el numero de notas de la lista
 *
 * Descripci�n: 
 *      Calcula el numero de notas de la lista
 */
int     numeroNotas   (const ListaNotas * notas);

/* 
 * Funci�n: escribirArchivoNotas()
 * 
 * Par�metros de entrada:
 *      listaNotas * notas: Lista con las notas
 *      char * archivo: Nombre del archivo donde escribir
 *      
 * Par�metros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      Vuelca las notas en un fichero 
 */
int     escribirArchivoNotas(const ListaNotas * notas, char * archivo);

/* 
 * Funci�n: leerArchivoNotas()
 * 
 * Par�metros de entrada:
 *      listaNotas * notas: Lista con las notas
 *      char * archivo: Nombre del archivo donde leer
 *      
 * Par�metros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      Recoge las notas de un fichero
 */
int     leerArchivoNotas(ListaNotas * notas, char * archivo);


#endif /* _NOTAS_H_ */
