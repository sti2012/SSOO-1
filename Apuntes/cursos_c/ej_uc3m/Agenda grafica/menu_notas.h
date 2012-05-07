/*
 * Programa: agenda
 * Modulo  : menu_notas
 * Fichero : menu_notas.h
 */
#ifndef _MENU_NOTAS_H_
#define _MENU_NOTAS_H_


/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include "util.h"
#include "notas.h"
#include "dialogo_datos.h"
#include "datos_agenda.h"
#include "dialogo_aviso.h"

/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función listarNotasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *     lista las notas en el widget de notas
 */
void listarNotasWidget   (void);

/*
 * Función insertarNotasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para insertar una nota
 */
void insertarNotasWidget (void);

/*
 * Función borrarNotasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      muestra la ventana para eliminar una nota
 */
void borrarNotasWidget   (void);

/*
 * Función destruirNotasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      destruye las notas y sale del programa
 */
void destruirNotasWidget (void);

/*
 * Función notasWidget()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve el widget de las notas (GtkWidget *)
 *
 * Descripción: 
 *      Prepara el widget de las notas
 */
GtkWidget *notasWidget(void);


#endif /* _MENU_NOTAS_H_ */
