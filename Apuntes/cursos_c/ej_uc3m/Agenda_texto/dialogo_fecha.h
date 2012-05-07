/*
 * Programa: agenda
 * Modulo  : dialogo_fecha
 * Fichero : dialogo_fecha.h
 */
#ifndef _DIALOG_FECHA_H_
#define _DIALOG_FECHA_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"

/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función dialogo_fecha()
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve la fecha recogida en segundos desde la epoca (time_t)
 *
 * Descripción: 
 *      Recoge una fecha por teclada y la devuelve covertida en segundos 
 *      desde la epoca
 */
time_t dialogo_fecha (void);


#endif /* _DIALOG_FECHA_H_ */
