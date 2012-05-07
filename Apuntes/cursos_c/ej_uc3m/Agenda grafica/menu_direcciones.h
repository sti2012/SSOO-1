/*
 * Programa: agenda
 * Modulo  : menu_direcciones
 * Fichero : menu_direcciones.h
 */
#ifndef _MENU_DIRECCIONES_H_
#define _MENU_DIRECCIONES_H_

/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "direcciones.h"
#include "datos_agenda.h"
#include "dialogo_aviso.h"

/*
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n listarDireccionWindow()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para listar las direcciones
 */
void listarDireccionWindow (void);

/*
 * Funci�n insertarDireccionDialogo()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para insertar una direccion
 */
void insertarDireccionDialogo (void);

/*
 * Funci�n borrarDireccionDialogo()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para borrar una direccion
 */
void borrarDireccionDialogo (void);

/*
 * Funci�n consultarNombreDialogo()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para consultar una direccion
 */
void consultarNombreDialogo (void);


#endif /* _MENU_DIRECCIONES_H_ */
