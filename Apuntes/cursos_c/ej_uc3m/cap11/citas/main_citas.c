/* 
 * Programa:    citas
 * Fichero:     main_citas.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              incluye un simple programa para uso de la implementación 
 *              del módulo citas
 */


#include "citas.h"


int main ( void )
{
   ListaCitas citas;
   Cita *cita;

   iniciarListaCitas(&citas);
   cita=nuevaCita("Euro",1,1,2002,12,30,1);
   insertarCitas(&citas,cita);

   destruirListaCitas(&citas);
   return (0);
}

