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
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n dialogoFecha()
 * 
 * Par�metros de entrada:
 *      char * titulo: Titulo de la ventana
 *      char * mensaje: Mensaje a mostrar
 *      void (*fAceptar)(void *,int,int,int,int,int): funci�n a ejecutar al 
 *          pulsar "Aceptar" recibe unos datos fijos (void *) y la fecha 
 *          introducido en la ventana (dia, mes, a�o, hora, minuto)
 *      void *fAceptarPtr: Datos que se pasan siempre a la funci�n fAceptar
 *      
 * Par�metros de salida:
 *      Devuelve un puntero a la ventana o NULL si hay error
 *
 * Descripci�n: 
 *      Muestra un ventana gtk con un titulo, un mensaje, una caja para
 *      introducir una fecha (dia, mes, a�o, hora, minuto)
 *      un bot�n de confirmaci�n y otro de cancelaci�n. Cuando se pulse el boton
 *      de aceptaci�n ejecutara la funci�n fAceptar enviandola la fecha
 *      introducida, luego finaliza la ventana. Si se pulsa
 *      el boton de cancelaci�n se finaliza la ventana.
 */
GtkWidget* dialogoFecha( char *titulo,char *mensaje,
			 void (*fAceptar)(void *,int,int,int,int,int), 
                         void *fAceptarPtr);
/*
 * Funci�n dialogoCita()
 * 
 * Par�metros de entrada:
 *      char * titulo: Titulo de la ventana
 *      char * mensaje: Mensaje a mostrar
 *      void (*fAceptar)(void *,char *, int,int,int,int,int): funci�n a ejecutar
 *          al pulsar "Aceptar" recibe unos datos fijos (void *) el mensaje
 *          introducido (char *) y la fecha introducida en la ventana 
 *          (dia, mes, a�o, hora, minuto)
 *      void *fAceptarPtr: Datos que se pasan siempre a la funci�n fAceptar
 *      
 * Par�metros de salida:
 *      Devuelve un puntero a la ventana o NULL si hay error
 *
 * Descripci�n: 
 *      Muestra un ventana gtk con un titulo, un mensaje, una caja para
 *      introducir un texto y una fecha (dia, mes, a�o, hora, minuto)
 *      un bot�n de confirmaci�n y otro de cancelaci�n. Cuando se pulse el boton
 *      de aceptaci�n ejecutara la funci�n fAceptar enviandola el texto y la 
 *      fecha introducida, luego finaliza la ventana. Si se pulsa
 *      el boton de cancelaci�n se finaliza la ventana.
 */
GtkWidget* dialogoCita( char *titulo, char * mensaje, 
		        void (*fAceptar)(void *,char *,int,int,int,int,int),
                        void *fAceptarPtr);

#endif /* _DIALOGOS_CON_FECHAS_H_ */
