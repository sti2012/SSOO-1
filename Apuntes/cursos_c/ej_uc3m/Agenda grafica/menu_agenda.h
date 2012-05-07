/*
 * Programa: agenda
 * Modulo  : menu_agenda
 * Fichero : menu_agenda.h
 */

#ifndef _MENU_AGENDA_H_
#define _MENU_AGENDA_H_


/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include "util.h"
#include "menu_agenda_menus.h"
#include "menu_notas.h"
#include "menu_citas.h"
#include "menu_calendario.h"
#include "datos_agenda.h"
#include "fecha.h"

/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función agendaWindow()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Prepara y muestra la pantalla principal de la agenda
 */
void agendaWindow (void);


#endif /* _MENU_AGENDA_H_ */

