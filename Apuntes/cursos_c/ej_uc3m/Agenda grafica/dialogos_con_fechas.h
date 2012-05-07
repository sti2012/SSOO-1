/*
 * Programa: agenda
 * Modulo  : agenda
 * Fichero : dialogos_con_fechas.h
 */
#ifndef _DIALOGOS_CON_FECHAS_H_
#define _DIALOGOS_CON_FECHAS_H_


/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "fecha.h"
#include "dialogo_aviso.h"


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función dialogoFecha()
 * 
 * Parámetros de entrada:
 *      char * titulo: Titulo de la ventana
 *      char * mensaje: Mensaje a mostrar
 *      void (*fAceptar)(void *,int,int,int,int,int): función a ejecutar al 
 *          pulsar "Aceptar" recibe unos datos fijos (void *) y la fecha 
 *          introducido en la ventana (dia, mes, año, hora, minuto)
 *      void *fAceptarPtr: Datos que se pasan siempre a la función fAceptar
 *      
 * Parámetros de salida:
 *      Devuelve un puntero a la ventana o NULL si hay error
 *
 * Descripción: 
 *      Muestra un ventana gtk con un titulo, un mensaje, una caja para
 *      introducir una fecha (dia, mes, año, hora, minuto)
 *      un botón de confirmación y otro de cancelación. Cuando se pulse el boton
 *      de aceptación ejecutara la función fAceptar enviandola la fecha
 *      introducida, luego finaliza la ventana. Si se pulsa
 *      el boton de cancelación se finaliza la ventana.
 */
GtkWidget* dialogoFecha( char *titulo,char *mensaje,
			 void (*fAceptar)(void *,int,int,int,int,int), 
                         void *fAceptarPtr);
/*
 * Función dialogoCita()
 * 
 * Parámetros de entrada:
 *      char * titulo: Titulo de la ventana
 *      char * mensaje: Mensaje a mostrar
 *      void (*fAceptar)(void *,char *, int,int,int,int,int): función a ejecutar
 *          al pulsar "Aceptar" recibe unos datos fijos (void *) el mensaje
 *          introducido (char *) y la fecha introducida en la ventana 
 *          (dia, mes, año, hora, minuto)
 *      void *fAceptarPtr: Datos que se pasan siempre a la función fAceptar
 *      
 * Parámetros de salida:
 *      Devuelve un puntero a la ventana o NULL si hay error
 *
 * Descripción: 
 *      Muestra un ventana gtk con un titulo, un mensaje, una caja para
 *      introducir un texto y una fecha (dia, mes, año, hora, minuto)
 *      un botón de confirmación y otro de cancelación. Cuando se pulse el boton
 *      de aceptación ejecutara la función fAceptar enviandola el texto y la 
 *      fecha introducida, luego finaliza la ventana. Si se pulsa
 *      el boton de cancelación se finaliza la ventana.
 */
GtkWidget* dialogoCita( char *titulo, char * mensaje, 
		        void (*fAceptar)(void *,char *,int,int,int,int,int),
                        void *fAceptarPtr);

#endif /* _DIALOGOS_CON_FECHAS_H_ */
