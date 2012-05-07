/*
 * Programa: agenda
 * Modulo  : menu_notas
 * Fichero : menu_notas.h
 */
#ifndef _MENU_NOTAS_H_
#define _MENU_NOTAS_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"
#include "notas.h"


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función menuNotas()
 *
 * Parámetros de entrada:
 *      ListaNotas * notas: Lista de notas global de la agenda
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Muestra el menu de las notas de la agenda     
 */
void menuNotas (ListaNotas *notas) ;


#endif /* _MENU_NOTAS_H_ */
