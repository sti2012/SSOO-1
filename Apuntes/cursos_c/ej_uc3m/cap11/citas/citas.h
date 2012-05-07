/* 
 * Programa:    citas
 * Fichero:     citas.h
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              Implementación del módulo citas utilizando 
 *              una estructura autoreferenciada
 */

#ifndef _CITAS_H_
#define _CITAS_H_

/*
 * Ficheros include
 */
#include <time.h>


/*
 * Constantes
 */

#define CITA_MAX    1024


/*
 * Tipos de datos
 */

typedef struct InfoCita * ListaCitas;
typedef struct InfoCita   Cita;

struct InfoCita
{
	 char       *  motivo;
	 time_t        cuando;
         int           cumplida;

	 ListaCitas    resto;
};

/*
 * Declaracion de variables (no hay)
 */


/*
 * Macros (no hay)
 */


/*
 * Prototipos de funciones publicas
 */

/* Crea una nueva cita */
Cita *  nuevaCita (char *motivo,
                   int dia, int mes, int anyo,
		   int hora, int minuto, int segundo);

/* Destruye una cita */
void    destruirCita       (Cita *cita);

/* Inicia la lista de citas */
void    iniciarListaCitas  (ListaCitas *citas);

/* Destruye la lista de citas */
void    destruirListaCitas (ListaCitas *citas);

/* Devuelve la primera cita */
Cita *      primeraCita    (ListaCitas  citas);

/* Devuelve el resto de citas */
ListaCitas  restoCitas     (ListaCitas  citas);

/* Inserta una nueva cita */
void        insertarCitas  (ListaCitas *citas, Cita *cita);

/* Borra una cita de la lista */
void        borrarCitas    (ListaCitas *citas, Cita *cita);

/* Calcula el número de citas  */
int numeroCitas (ListaCitas citas);

/*
 * Prototipos de funciones privadas
 */

/* 
 * Manejador a ejecutar para avisar de una cita inminente 
 * */
void citaAvisar (int senyal);

/* 
 * Activa una alarma asociada a la momento de producirse la cita 
 */
int activarAlarma (Cita *cita);

#endif /* _CITAS_H_ */

