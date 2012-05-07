/* 
 * Programa:    citas
 * Fichero:     main_citas.c
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 11:
 *              incluye un simple programa para uso de la implementaci�n 
 *              del m�dulo citas
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

