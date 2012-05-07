/*
 * Programa: agenda
 * Modulo  : datos
 * Fichero : datos_agenda.h
 */
#ifndef _DATOS_AGENDA_H_
#define _DATOS_AGENDA_H_


/*
 * FICHEROS INCLUDES 
 */
#include <gtk/gtk.h>
#include "util.h"
#include "notas.h"
#include "citas.h"
#include "direcciones.h"


/*
 * TIPOS DE DATOS
 */
typedef struct _DatosAgenda DatosAgenda;

struct _DatosAgenda
{
    ListaNotas  notas;
    ListaCitas  citas;
    ListaDir  direcciones;
    GtkWidget *gtk_calendario;
    GtkWidget *gtk_notas;
    GtkWidget *gtk_citas[4];
};


/*
 * VARIABLES GLOBALES EXPORTADAS
 */
extern DatosAgenda datosAgenda;


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/*
 * Función iniciarDatosAgenda
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Inicia los datos propios de la variable global "datosagenda" 
 *      (notas, citas y direcciones)
 */
void  iniciarDatosAgenda (void);

/*
 * Función finalizarDatosAgenda
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Destruye los datos propios de la variable global "datosagenda" 
 *      (notas, citas y direcciones)
 */
void  finalizarDatosAgenda (void);

/*
 * Función cargarDatosAgenda
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Carga desde un archivo predefinido los datos propios de la variable 
 *      global "datosagenda" (notas, citas y direcciones)
 */
void  cargarDatosAgenda (void);
 
/*
 * Función grabarDatosAgenda
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Graba en un archivo predefinido los datos propios de la variable 
 *      global "datosagenda" (notas, citas y direcciones)
 */
void  grabarDatosAgenda (void);       

#endif /* _DATOS_AGENDA_H_ */

