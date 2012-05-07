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
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función listarDireccionWindow()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para listar las direcciones
 */
void listarDireccionWindow (void);

/*
 * Función insertarDireccionDialogo()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para insertar una direccion
 */
void insertarDireccionDialogo (void);

/*
 * Función borrarDireccionDialogo()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para borrar una direccion
 */
void borrarDireccionDialogo (void);

/*
 * Función consultarNombreDialogo()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para consultar una direccion
 */
void consultarNombreDialogo (void);


#endif /* _MENU_DIRECCIONES_H_ */
