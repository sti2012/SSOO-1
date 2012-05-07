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
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/*
 * Funci�n menuCitas()
 *
 * Par�metros de entrada:
 *      ListaCitas * citas: Lista de citas global de la agenda
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Muestra el menu de las citas de la agenda     
 */
void menuCitas (ListaCitas *citas) ;

/*
 * Funci�n avisarMenuCita()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Muestra el mensaje de aviso cuando se cumple una cita
 */
void avisarMenuCita (void);


#endif /* _MENU_CITAS_H_ */
