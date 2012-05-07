/*
 * Programa: agenda
 * Modulo  : menu_citas
 * Fichero : menu_citas.h
 */
#ifndef _MENU_CITAS_H_
#define _MENU_CITAS_H_


/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include "util.h"
#include "citas.h"
#include "dialogo_datos.h"
#include "datos_agenda.h"
#include "dialogo_aviso.h"

/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función insertarCitasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para insertar una cita
 */
void insertarCitasWidget (void);

/*
 * Función eliminarCitasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para eliminar una cita
 */
void eliminarCitasWidget (void);

/*
 * Función actualizarCitasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      actualiza las citas del widget de citas
 */
void actualizarCitasWidget(void);	 

/*
 * Función citasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve el widget de las citas (GtkWidget *)
 *
 * Descripción: 
 *      Prepara el widget de las citas
 */
GtkWidget *citasWidget(void);

/*
 * Función avisarCitaWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana que avisa del cumplimiento de una cita
 */
void avisarCitaWidget(void);



#endif /* _MENU_CITAS_H_ */
