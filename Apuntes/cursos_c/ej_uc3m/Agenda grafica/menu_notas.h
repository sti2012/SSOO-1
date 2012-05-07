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
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n listarNotasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *     lista las notas en el widget de notas
 */
void listarNotasWidget   (void);

/*
 * Funci�n insertarNotasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para insertar una nota
 */
void insertarNotasWidget (void);

/*
 * Funci�n borrarNotasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      muestra la ventana para eliminar una nota
 */
void borrarNotasWidget   (void);

/*
 * Funci�n destruirNotasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      destruye las notas y sale del programa
 */
void destruirNotasWidget (void);

/*
 * Funci�n notasWidget()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Devuelve el widget de las notas (GtkWidget *)
 *
 * Descripci�n: 
 *      Prepara el widget de las notas
 */
GtkWidget *notasWidget(void);


#endif /* _MENU_NOTAS_H_ */
