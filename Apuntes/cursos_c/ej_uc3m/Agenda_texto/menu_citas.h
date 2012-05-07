/*
 * Programa: agenda
 * Modulo  : menu_citas
 * Fichero : menu_citas.h
 */
#ifndef _MENU_CITAS_H_
#define _MENU_CITAS_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"
#include "citas.h"
#include "dialogo_fecha.h"
#include "dialogo_valor.h"


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función menuCitas()
 *
 * Parámetros de entrada:
 *      ListaCitas * citas: Lista de citas global de la agenda
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Muestra el menu de las citas de la agenda     
 */
void menuCitas (ListaCitas *citas) ;

/*
 * Función avisarMenuCita()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Muestra el mensaje de aviso cuando se cumple una cita
 */
void avisarMenuCita (void);


#endif /* _MENU_CITAS_H_ */
