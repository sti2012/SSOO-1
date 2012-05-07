/*
 * Programa: agenda
 * Modulo  : menu_agenda
 * Fichero : menu_agenda_menus.h
 */
#ifndef _MENU_AGENDA_MENUS_H_
#define _MENU_AGENDA_MENUS_H_


/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include "util.h"
#include "menu_notas.h"
#include "menu_calendario.h"
#include "menu_citas.h"
#include "menu_direcciones.h"

/*
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n crearMenu()
 *
 * Par�metros de entrada:
 *      GtkWidget *window: ventana donde se incluira el menu
 *      
 * Par�metros de salida:
 *      Devuelve el widget del menu
 *
 * Descripci�n: 
 *      Crea el widget del menu de la ventana principal de la agenda y lo
 *      devuelve para que sea incluido en dicha ventana
 */
GtkWidget* crearMenu(GtkWidget *window);


#endif /* _MENU_AGENDA_MENUS_H_ */

