/*
 * Programa: agenda
 * Modulo  : menu_calendario
 * Fichero : menu_calendario.h
 */
#ifndef _MENU_CALENDARIO_H_
#define _MENU_CALENDARIO_H_


/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include "util.h"
#include "fecha.h"
#include "dialogo_datos.h"
#include "datos_agenda.h"
#include "menu_citas.h"

/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función mostrarCalendarioWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra el widget del calendario
 */
void mostrarCalendarioWidget(void);


/*
 * Función ocultarCalendarioWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Oculta el widget del calendario
 */
void ocultarCalendarioWidget (void);

/*
 * Función mesAnteriorCalendarioWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      establece el widget del calendario al mes anterior
 */
void mesAnteriorCalendarioWidget (void);

/*
 * Función mesSiguienteCalendarioWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      establece el widget del calendario al mes siguiente
 */
void mesSiguienteCalendarioWidget (void);

/*
 * Función anyoAnteriorCalendarioWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      establece el widget del calendario al año anterior
 */
void anyoAnteriorCalendarioWidget (void);

/*
 * Función anyoSiguienteCalendarioWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      establece el widget del calendario al año siguiente
 */
void anyoSiguienteCalendarioWidget (void);

/*
 * Función calendarioWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve el widget del calendario (GtkWidget *)
 *
 * Descripción: 
 *      Prepara el widget del calendario
 */
GtkWidget *calendarioWidget(void);

#endif /* _MENU_CALENDARIO_H_ */
