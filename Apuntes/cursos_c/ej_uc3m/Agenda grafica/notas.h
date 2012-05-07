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
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/* 
 * Función: crearNotas()
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve la lista de notas creada (ListaNotas)
 *
 * Descripción: 
 *      Crea la lista de notas
 */
ListaNotas crearNotas    (void);

/* 
 * Función: destruirNotas()
 * 
 * Parámetros de entrada:
 *      ListaNotas * notas: Lista de notas a destruir
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Destruye la lista de notas
 */
void    destruirNotas (ListaNotas * notas);

/* 
 * Función: insertarNotas()
 * 
 * Parámetros de entrada:
 *      ListaNotas * notas: Lista de notas donde insertar 
 *      char * mensaje: nota a insertar 
 *      
 * Parámetros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      inserta una nota en la lista de notas
 */
int     insertarNotas (ListaNotas * notas, char * mensaje);

/* 
 * Función: borrarNotas()
 * 
 * Parámetros de entrada:
 *      ListaNotas * notas: Lista de notas donde borrar 
 *      int posicion: posición de la nota a borrar 
 *      
 * Parámetros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      borra una nota de la lista de notas
 */
int     borrarNotas   (ListaNotas * notas, int posicion);

/* 
 * Función: consultarNotas()
 * 
 * Parámetros de entrada:
 *      ListaNotas * notas: Lista de notas donde consultar
 *      int posicion: posición de la nota a consultar 
 *      
 * Parámetros de salida:
 *      Devuelve la nota si ha ido bien (char *), NULL en caso contrario
 *
 * Descripción: 
 *      consulta una nota de la lista de notas
 */
char *  consultarNotas (const ListaNotas * notas, int posicion);

/* 
 * Función: numeroNotas()
 * 
 * Parámetros de entrada:
 *      ListaNotas * notas: Lista de notas  
 *      
 * Parámetros de salida:
 *      Devuelve el numero de notas de la lista
 *
 * Descripción: 
 *      Calcula el numero de notas de la lista
 */
int     numeroNotas   (const ListaNotas * notas);

/* 
 * Función: escribirArchivoNotas()
 * 
 * Parámetros de entrada:
 *      listaNotas * notas: Lista con las notas
 *      char * archivo: Nombre del archivo donde escribir
 *      
 * Parámetros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Vuelca las notas en un fichero 
 */
int     escribirArchivoNotas(const ListaNotas * notas, char * archivo);

/* 
 * Función: leerArchivoNotas()
 * 
 * Parámetros de entrada:
 *      listaNotas * notas: Lista con las notas
 *      char * archivo: Nombre del archivo donde leer
 *      
 * Parámetros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Recoge las notas de un fichero
 */
int     leerArchivoNotas(ListaNotas * notas, char * archivo);


#endif /* _NOTAS_H_ */
