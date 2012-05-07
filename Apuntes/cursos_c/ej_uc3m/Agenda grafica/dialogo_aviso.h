/*
 * Programa: agenda
 * Modulo  : dialogo_aviso
 * Fichero : dialogo_aviso.h
 */
#ifndef _DIALOGO_AVISO_H_
#define _DIALOGO_AVISO_H_


/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función dialogoAviso()
 * 
 * Parámetros de entrada:
 *      char * mensaje: Mensaje a mostrar
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Muestra un ventana gtk con el mensaje y un botón de confirmación
 */
void dialogoAviso(char* mensaje);


#endif /* _DIALOGO_AVISO_H_ */
