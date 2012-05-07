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
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/* 
 * Funci�n: crearDir()
 * 
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Devuelve la nueva lista de direcciones (ListaDir)
 *
 * Descripci�n: 
 *      Crea una lista de direcciones
 */
ListaDir crearDir (void);

/* 
 * Funci�n: destruirDir()
 * 
 * Par�metros de entrada:
 *      ListaDir * datos:   Lista de direcciones a destruir
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Destruye una lista de direcciones
 */

void destruirDir  (ListaDir *datos);
/* 
 * Funci�n: insertarDir()
 * 
 * Par�metros de entrada:
 *      ListaDir * datos:   Lista de direcciones donde insertar
 *      char * nombre: Nombre de la persona
 *      char * direccion: Direccion de la persona
 *      char * telefono: Telefono de la persona
 *      
 * Par�metros de salida:
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripci�n: 
 *      inserta una nueva direccion
 */
int  insertarDir  (ListaDir *datos, char *nombre, 
                   char *direccion, char *telefono);
/* 
 * Funci�n: borrarDir()
 * 
 * Par�metros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      char * nombre: Nombre de la persona a borrar
 *      
 * Par�metros de salida:
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripci�n: 
 *      borra una direcci�n de una lista de direcciones
 */
int  borrarDir    (ListaDir *datos, char *nombre);

/* 
 * Funci�n: numeroDir()
 * 
 * Par�metros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      
 * Par�metros de salida:
 *      Devuelve el numero de direcciones en la lista
 *
 * Descripci�n: 
 *      calcula el numero de direcciones en la lista
 */
int  numeroDir    (const ListaDir *datos);

/* 
 * Funci�n: consultarDir()
 * 
 * Par�metros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      int posicion: Posici�n de la direccion a consultar
 *      
 * Par�metros de salida:
 *      char ** nombre: Nombre de la persona 
 *      char ** direccion: Direccion de la persona 
 *      char ** telefono: Telefono de la persona 
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripci�n: 
 *      consulta una direcci�n en una lista de direcciones
 */
int  consultarDir (const ListaDir *datos, int posicion, 
                   char **nombre, char **direccion, char **telefono);

/* 
 * Funci�n: consultarDirPorNombre()
 * 
 * Par�metros de entrada:
 *      ListaDir * datos:   Lista de direcciones de donde borrar 
 *      char * nombre: Nombre de la persona a consultar
 *      
 * Par�metros de salida:
 *      int * posicion: Posici�n de la direccion 
 *      char ** direccion: Direccion de la persona 
 *      char ** telefono: Telefono de la persona 
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripci�n: 
 *      consulta una direcci�n en una lista de direcciones
 */
int  consultarDirPorNombre (const ListaDir *datos, char *nombre, 
                            int *pos, char **direccion, char **telefono);
/* 
 * Funci�n: escribirArchivoDir()
 * 
 * Par�metros de entrada:
 *      ListaDir * datos:   Lista de direcciones a escribir 
 *      char * archivo: Nombre del archivo donde se almancenar�n
 *      
 * Par�metros de salida:
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripci�n: 
 *       escribe una lista de direcciones en un archivo
 */
int  escribirArchivoDir (const ListaDir *datos, char *archivo);

/* 
 * Funci�n: escribirArchivoDir()
 * 
 * Par�metros de entrada:
 *      char * archivo: Nombre del archivo donde estan almancenadas
 *      
 * Par�metros de salida:
 *      ListaDir * datos:   Lista de direcciones leida 
 *      Devuelve un 0 si correcto, -1 si error
 *
 * Descripci�n: 
 *       lee una lista de direcciones de un archivo
 */
int  leerArchivoDir     (ListaDir *datos, char *archivo);

#endif /* _DIRECCIONES_H_ */
