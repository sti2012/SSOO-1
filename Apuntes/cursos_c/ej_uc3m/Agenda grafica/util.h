/*
 * Programa: agenda
 * Modulo  : util
 * Fichero : util.h
 */
#ifndef _UTIL_H_
#define _UTIL_H_


/*
 * FICHEROS INCLUDES
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función stringDup()
 * 
 * Parámetros de entrada:
 *      char * mensaje: Mensaje a copiar
 *      
 * Parámetros de salida:
 *      Devuelve un nuevo string copiado del original (char *)
 *
 * Descripción: 
 *      Reserva espacio en memoria dinamica y copia el mensaje en él
 */
char *stringDup (char *mensaje) ;

/*
 * Función cTime()
 * 
 * Parámetros de entrada:
 *      time_t * ahora: fecha y hora en formato time_t
 *      
 * Parámetros de salida:
 *      Devuelve un string que contiene la fecha y hora en un formato de
 *      texto
 *
 * Descripción: 
 *      Convierte la fecha introducida en formato time_t a un string que 
 *      contiene la fecha y hora actual en un formato de texto 
 */
char *cTime (time_t *ahora);


#endif /* _UTIL_H_ */
