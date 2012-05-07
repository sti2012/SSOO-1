/*
 * Programa: agenda
 * Modulo  : datos_agenda
 * Fichero : datos_agenda.c
 */

#define FICHERO_DIR  "direcciones.agd"
#define FICHERO_CITAS  "citas.agd"
#define FICHERO_NOTAS  "notas.agd"


/*
 * FICHEROS INCLUDES
 */
#include "notas.h"
#include "citas.h"
#include "direcciones.h"
#include "datos_agenda.h"


/*
 * VARIABLES GLOBALES
 */
DatosAgenda datosAgenda;

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función iniciarDatosAgenda
 */
void  iniciarDatosAgenda (void)
{
    datosAgenda.notas=crearNotas();
    iniciarListaCitas(&(datosAgenda.citas));
    datosAgenda.direcciones=crearDir();

    datosAgenda.gtk_calendario=NULL;
    datosAgenda.gtk_notas=NULL;
}

/*
 * Función cargarDatosAgenda
 */
void  cargarDatosAgenda (void)
{
    leerArchivoListaCitas(&(datosAgenda.citas),FICHERO_CITAS);
    leerArchivoDir(&(datosAgenda.direcciones),FICHERO_DIR);
    leerArchivoNotas(&(datosAgenda.notas),FICHERO_NOTAS);
}
/*
 * Función finalizarDatosAgenda
 */
void  finalizarDatosAgenda (void)
{


    destruirListaCitas(&(datosAgenda.citas));
    destruirNotas(&(datosAgenda.notas));
    destruirDir(&(datosAgenda.direcciones));

}
/*
 * Función grabarDatosAgenda
 */
void  grabarDatosAgenda (void)
{
    escribirArchivoListaCitas(&(datosAgenda.citas),FICHERO_CITAS);
    escribirArchivoDir(&(datosAgenda.direcciones),FICHERO_DIR);
    escribirArchivoNotas(&(datosAgenda.notas),FICHERO_NOTAS);
}
