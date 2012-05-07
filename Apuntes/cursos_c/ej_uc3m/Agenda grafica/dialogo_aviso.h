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
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n dialogoAviso()
 * 
 * Par�metros de entrada:
 *      char * mensaje: Mensaje a mostrar
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Muestra un ventana gtk con el mensaje y un bot�n de confirmaci�n
 */
void dialogoAviso(char* mensaje);


#endif /* _DIALOGO_AVISO_H_ */
