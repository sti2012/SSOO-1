/*
 * Programa: agenda
 * Modulo  : dialogo_datos
 * Fichero : dialogo_datos.h
 */
#ifndef _DIALOGO_DATOS_H_
#define _DIALOGO_DATOS_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"
#include <gtk/gtk.h>
#include "dialogo_aviso.h"


/*
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n dialogDatos()
 * 
 * Par�metros de entrada:
 *      char * titulo: Titulo de la ventana
 *      char * mensaje: Mensaje a mostrar
 *      void (*fAceptar)(void *, char *): funci�n a ejecutar al pulsar "Aceptar"
 *          recibe unos datos fijos (void *) y el texto introducido en la
 *          ventana (char *)
 *      void *fAceptarPtr: Datos que se pasan siempre a la funci�n fAceptar
 *      
 * Par�metros de salida:
 *      Devuelve un puntero a la ventana o NULL si hay error
 *
 * Descripci�n: 
 *      Muestra un ventana gtk con un titulo, un mensaje, una caja de texto, 
 *      un bot�n de confirmaci�n y otro de cancelaci�n. Cuando se pulse el boton
 *      de aceptaci�n ejecutara la funci�n fAceptar enviandola el texto
 *      introducido en la caja de texto, luego finaliza la ventana. Si se pulsa
 *      el boton de cancelaci�n se finaliza la ventana.
 */
GtkWidget* dialogoDatos ( char *titulo, char * mensaje, 
		          void (*fAceptar)(void *, char *), 
			  void *fAceptarPtr ) ;


#endif /* _DIALOGO_DATOS_H_ */
