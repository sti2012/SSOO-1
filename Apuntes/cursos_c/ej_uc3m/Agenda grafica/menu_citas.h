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
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n insertarCitasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para insertar una cita
 */
void insertarCitasWidget (void);

/*
 * Funci�n eliminarCitasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para eliminar una cita
 */
void eliminarCitasWidget (void);

/*
 * Funci�n actualizarCitasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      actualiza las citas del widget de citas
 */
void actualizarCitasWidget(void);	 

/*
 * Funci�n citasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Devuelve el widget de las citas (GtkWidget *)
 *
 * Descripci�n: 
 *      Prepara el widget de las citas
 */
GtkWidget *citasWidget(void);

/*
 * Funci�n avisarCitaWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana que avisa del cumplimiento de una cita
 */
void avisarCitaWidget(void);



#endif /* _MENU_CITAS_H_ */
