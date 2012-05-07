/* 
 * Programa:    prog14_01
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 14:
 *              Programa principal de la agenda de usuario gráfica
 */


#include <gtk/gtk.h>

/* Manejador de señal : closeAppWindow */
void closeAppWindow (GtkWidget *widget, gpointer *data)
{
    g_print ("\n Agenda de usuario cerrandose \n");
    gtk_main_quit();
}

int main(int argc,char *argv[])
{
    
    /* Definición de widgets para la ventana principal y el título */
    GtkWidget *window;   
    
    /* 
     * Esta llamada es obligatoria en todos las aplicaciones que usan GTK.
     * Lee los argumentos de la linea de comandos de ejecución del programa y 
     * se los pasa a la aplicación. 
     * Además de eso, inicia los parámetros de la biblioteca gráfica.
     */
    gtk_init (&argc, &argv);

    /* 
     * Creación de una ventana para la aplicación. Es su ventana padre.
     * De ella dependerán las otras que se  arranquen.
     * Todavía no es visible.
     */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* Configuración de opciones del widget  */    
    gtk_widget_set_usize (GTK_WIDGET (window), 400, 300);
    gtk_window_set_title (GTK_WINDOW (window), "Agenda Electronica");

    /* 
     *   ..... más código de configuración   
     */

    /* 
     * Conexión de los eventos. 
     * Como ejemplo, sólo se muestra la conexión del evento 
     * "destroy" al manejador de señales. Este evento se produce cuando 
     * se llama a closeAppWindow() sobre la ventana.
     */
    gtk_signal_connect (GTK_OBJECT (window), "destroy",
		    	GTK_SIGNAL_FUNC(closeAppWindow), NULL);

    /* 
     *   ..... más código de eventos   
     */

    
    /* Definición de la esquina superior izquierda de la ventana */
    gtk_widget_set_uposition( window, 400, 200 );
    /* Hace visible la ventana principal */    
    gtk_widget_show (window);

    /* 
     * Todas las aplicaciones que usen GTK deben tener esta llamada. 
     * Mediante esta llamada, la aplicación cede el control hasta que ocurra 
     * un evento (como una pulsación de ratón, por ejemplo).
     */
    gtk_main ();

    /* Salida del programa con estado OK */																												                             
    return(0);
}
