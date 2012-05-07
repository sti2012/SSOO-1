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
 * FUNCIONES P�BLICAS
 */

/*
 * Funci�n iniciarDatosAgenda
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
 * Funci�n cargarDatosAgenda
 */
void  cargarDatosAgenda (void)
{
    leerArchivoListaCitas(&(datosAgenda.citas),FICHERO_CITAS);
    leerArchivoDir(&(datosAgenda.direcciones),FICHERO_DIR);
    leerArchivoNotas(&(datosAgenda.notas),FICHERO_NOTAS);
}
/*
 * Funci�n finalizarDatosAgenda
 */
void  finalizarDatosAgenda (void)
{


    destruirListaCitas(&(datosAgenda.citas));
    destruirNotas(&(datosAgenda.notas));
    destruirDir(&(datosAgenda.direcciones));

}
/*
 * Funci�n grabarDatosAgenda
 */
void  grabarDatosAgenda (void)
{
    escribirArchivoListaCitas(&(datosAgenda.citas),FICHERO_CITAS);
    escribirArchivoDir(&(datosAgenda.direcciones),FICHERO_DIR);
    escribirArchivoNotas(&(datosAgenda.notas),FICHERO_NOTAS);
}
