/* 
 * Programa:    direcciones
 * Fichero:     direcciones.h
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Implementaci�n del m�dulo direcciones grabando las mismas en un
 *              archivo
 */
#ifndef _DIRECCIONES_H_
#define _DIRECCIONES_H_

/*
 * Ficheros include
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Constantes
 */

#define TAM_MAX    1024


/*
 * Tipos de datos
 */
 typedef struct InfoDir * ListaDir;
 typedef struct InfoDir   Dir;

 struct InfoDir 
 {
	 char *nombre;
         char *direccion;
         char *telefono;
         ListaDir resto;
 };


/*
 * Declaracion de variables (no hay)
 */


/*
 * Macros (no hay)
 */


/*
 * Prototipos de funciones publicas
 */
ListaDir crearDir    (void);
void  destruirDir (ListaDir *datos);
int insertarDir (ListaDir *datos, char *nombre, 
                      char *direccion, char *telefono);
void  borrarDir   (ListaDir *datos, char *nombre);
int   consultarDir (const ListaDir *datos, int posicion, 
                    char **nombre, char **direccion, char **telefono);
int    consultarPorNombre (const ListaDir *datos, char *nombre, 
                           int *pos, char **direccion, char **telefono);
int   numeroDir   (const ListaDir *datos);
int escribirArchivoDir(const ListaDir *datos, char *archivo);
int leerArchivoDir(ListaDir *datos, char *archivo);



/*
 * Prototipos de funciones privadas
 */

#endif /* _DIRECCIONES_H_ */
