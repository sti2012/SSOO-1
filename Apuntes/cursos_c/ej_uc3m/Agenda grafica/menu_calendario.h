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
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n mostrarCalendarioWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra el widget del calendario
 */
void mostrarCalendarioWidget(void);


/*
 * Funci�n ocultarCalendarioWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Oculta el widget del calendario
 */
void ocultarCalendarioWidget (void);

/*
 * Funci�n mesAnteriorCalendarioWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      establece el widget del calendario al mes anterior
 */
void mesAnteriorCalendarioWidget (void);

/*
 * Funci�n mesSiguienteCalendarioWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      establece el widget del calendario al mes siguiente
 */
void mesSiguienteCalendarioWidget (void);

/*
 * Funci�n anyoAnteriorCalendarioWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      establece el widget del calendario al a�o anterior
 */
void anyoAnteriorCalendarioWidget (void);

/*
 * Funci�n anyoSiguienteCalendarioWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      establece el widget del calendario al a�o siguiente
 */
void anyoSiguienteCalendarioWidget (void);

/*
 * Funci�n calendarioWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Devuelve el widget del calendario (GtkWidget *)
 *
 * Descripci�n: 
 *      Prepara el widget del calendario
 */
GtkWidget *calendarioWidget(void);

#endif /* _MENU_CALENDARIO_H_ */
