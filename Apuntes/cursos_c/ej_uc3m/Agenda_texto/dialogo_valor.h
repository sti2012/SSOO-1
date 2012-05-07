/*
 * Programa: agenda
 * Modulo  : dialogo_valor
 * Fichero : dialogo_valor.h
 */
#ifndef _DIALOG_VALOR_H_
#define _DIALOG_VALOR_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función dialogo_valor()
 * 
 * Parámetros de entrada:
 *      char * mensaje: Mensaje que se muestra por pantalla
 *      
 * Parámetros de salida:
 *      char * valor: Valor recogido por el teclado
 *
 * Descripción: 
 *      Muestra un mensaje por pantalla y recoge por teclado un string que 
 *      envia como salida
 */
void  dialogo_valor (char *mensaje, char *valor);


#endif /* _DIALOG_VALOR_H_ */
