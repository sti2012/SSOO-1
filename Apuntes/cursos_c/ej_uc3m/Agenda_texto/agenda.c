/*
 * Programa: agenda
 * Modulo  : principal
 * Fichero : agenda.c
 */


/*
 * FICHEROS INCLUDES
 */
#include "notas.h"
#include "citas.h"
#include "direcciones.h"
#include "menu_agenda.h"

/*
 * CONSTANTES
 */

#define FICHERO_DIR  "direcciones.agd"
#define FICHERO_CITAS  "citas.agd"
#define FICHERO_NOTAS  "notas.agd"



/* 
 * Función: main()
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve un 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Programa principal inicia y carga los datos de la agenda, muestra el 
 *      menu principal de la agenda. Cuando este termina graba y destruye 
 *      los datos de la agenda.
 */
int main (void)
{
    ListaNotas notas;
    ListaCitas citas;
    ListaDir datos;

    /* inicia las notas, direcciones y citas */
    notas=crearNotas();
    iniciarListaCitas(&citas);
    datos=crearDir();

    /* carga de un archivo las notas, direcciones y citas */
    leerArchivoListaCitas(&citas,FICHERO_CITAS);
    leerArchivoDir(&datos,FICHERO_DIR);
    leerArchivoNotas(&notas,FICHERO_NOTAS);

    /* ejecuta el menu principal de la agenda */
    menuAgenda(&notas,&citas,&datos);

    /* graba en un archivo las notas, direcciones y citas */
    escribirArchivoListaCitas(&citas,FICHERO_CITAS);
    escribirArchivoDir(&datos,FICHERO_DIR);
    escribirArchivoNotas(&notas,FICHERO_NOTAS);

    /* destruye las notas, direcciones y citas */
    destruirListaCitas(&citas);
    destruirNotas(&notas);
    destruirDir(&datos);

    return (0);
}
