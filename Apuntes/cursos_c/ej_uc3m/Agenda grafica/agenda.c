/*
 * Programa: agenda
 * Modulo  : principal
 * Fichero : agenda.c
 */

/*
 * FICHEROS INCLUDES
 */
#include <gtk/gtk.h>
#include "menu_intro.h"
#include "datos_agenda.h"


/* 
 * Función: main()
 * 
 * Parámetros de entrada:
 *      int argc:  numero de parametros en la linea de comandos, se usa para
 *          iniciar la libreria de gtk
 *      char * argv[]: parametros de la linea de comandos, se usa para
 *          iniciar la libreria de gtk
 *      
 * Parámetros de salida:
 *      Devuelve un 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Programa principal inicia y carga los datos de la agenda, inicia la 
 *      ventana de inicio y comienza el bucle infinito de gtk. Cuando este 
 *      termina graba y destruye los datos de la agenda.
 */
int main( int argc,char *argv[] )
{
    
    /* Esto se llama en todas las aplicaciones del GTK. Los argumentos se leen 
     * de la linea de comandos y son filtrados y devueltos a la aplicación.
     */
    gtk_init (&argc, &argv);

    /* iniciación de las estructuras de datos y lectura de los ficheros */
    iniciarDatosAgenda();
    cargarDatosAgenda();

    /* Creación del componente que introduce la agenda.
     * Él se encargará de crear los demás componentes.
     */
    introWindow();

    /* Todas las aplicaciones GTK deben tener un gtk_main(). El control termina 
     * aquí y espera a que ocurran eventos (como una pulsación de tecla o ratón)
     */
    gtk_main ();
    
    /* finalización de las estructuras de datos y escritura de los ficheros */
    grabarDatosAgenda();
    finalizarDatosAgenda();

    return(0);
}

