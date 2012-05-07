/*
 * Programa: agenda
 * Modulo  : menu_agenda
 * Fichero : menu_agenda.h
 */
#ifndef _MENU_AGENDA_H_
#define _MENU_AGENDA_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"
#include "citas.h"
#include "menu_calendario.h"
#include "menu_citas.h"
#include "menu_notas.h"
#include "menu_direcciones.h"


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función menuAgenda()
 *
 * Parámetros de entrada:
 *      ListaNotas * notas: Lista de notas global de la agenda
 *      ListaCitas * citas: Lista de citas global de la agenda
 *      ListaDir * datos: Lista de direcciones global de la agenda
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Muestra el menu principal de la agenda     
 */
void  menuAgenda (ListaNotas *notas, ListaCitas *citas, ListaDir *datos);


#endif /* _MENU_AGENDA_H_ */

