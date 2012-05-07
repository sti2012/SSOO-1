/*
 * Programa: agenda
 * Modulo  : direcciones
 * Fichero : direcciones.h
 */
#ifndef _DIRECCIONES_H_
#define _DIRECCIONES_H_

/*
 * FICHEROS INCLUDES
 */
#include "util.h"


/*
 * CONSTANTES
 */

#define TAM_MAX    1024


/*
 * TIPOS DE DATOS
 */
typedef struct InfoDir * ListaDir;
typedef struct InfoDir   Dir;

struct InfoDir 
{
    char *   nombre;
    char *   direccion;
    char *   telefono;
    ListaDir resto;
 };


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/* 
 * Función: crearDir()
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve la nueva lista de direcciones (ListaDir)
 *
 * Descripción: 
 *      Crea una lista de direcciones
 */
ListaDir crearDir (void);

/* 
 * Función: destruirDir()
 * 
 * Parámetros de entrada:
 *      ListaDir * datos:   Lista de direcciones a destruir
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Destruye una lista de direcciones
 */

void destruirDir  (ListaDir *datos);
/* 
 * Función: insertarDir()
 * 
 * Parámetros de entrada:
 *      ListaDir * datos:   Lista de direcciones donde insertar
 *      char * nombre: Nombre de la persona
 *      char * direccion: Direccion de la persona
 *      char * telefono: Telefono de la persona
 *      
 * Parámetros de salida:
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripción: 
 *      inserta una nueva direccion
 */
int  insertarDir  (ListaDir *datos, char *nombre, 
                   char *direccion, char *telefono);
/* 
 * Función: borrarDir()
 * 
 * Parámetros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      char * nombre: Nombre de la persona a borrar
 *      
 * Parámetros de salida:
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripción: 
 *      borra una dirección de una lista de direcciones
 */
int  borrarDir    (ListaDir *datos, char *nombre);

/* 
 * Función: numeroDir()
 * 
 * Parámetros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      
 * Parámetros de salida:
 *      Devuelve el numero de direcciones en la lista
 *
 * Descripción: 
 *      calcula el numero de direcciones en la lista
 */
int  numeroDir    (const ListaDir *datos);

/* 
 * Función: consultarDir()
 * 
 * Parámetros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      int posicion: Posición de la direccion a consultar
 *      
 * Parámetros de salida:
 *      char ** nombre: Nombre de la persona 
 *      char ** direccion: Direccion de la persona 
 *      char ** telefono: Telefono de la persona 
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripción: 
 *      consulta una dirección en una lista de direcciones
 */
int  consultarDir (const ListaDir *datos, int posicion, 
                   char **nombre, char **direccion, char **telefono);

/* 
 * Función: consultarDirPorNombre()
 * 
 * Parámetros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      char * nombre: Nombre de la persona a consultar
 *      
 * Parámetros de salida:
 *      int * posicion: Posición de la direccion 
 *      char ** direccion: Direccion de la persona 
 *      char ** telefono: Telefono de la persona 
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripción: 
 *      consulta una dirección en una lista de direcciones
 */
int  consultarDirPorNombre (const ListaDir *datos, char *nombre, 
                            int *pos, char **direccion, char **telefono);
/* 
 * Función: escribirArchivoDir()
 * 
 * Parámetros de entrada:
 *      ListaDir * datos:   Lista de direcciones a escribir 
 *      char * archivo: Nombre del archivo donde se almancenarán
 *      
 * Parámetros de salida:
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripción: 
 *       escribe una lista de direcciones en un archivo
 */
int  escribirArchivoDir (const ListaDir *datos, char *archivo);

/* 
 * Función: escribirArchivoDir()
 * 
 * Parámetros de entrada:
 *      char * archivo: Nombre del archivo donde estan almancenadas
 *      
 * Parámetros de salida:
 *      ListaDir * datos:   Lista de direcciones leida 
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripción: 
 *       lee una lista de direcciones de un archivo
 */
int  leerArchivoDir     (ListaDir *datos, char *archivo);

#endif /* _DIRECCIONES_H_ */
