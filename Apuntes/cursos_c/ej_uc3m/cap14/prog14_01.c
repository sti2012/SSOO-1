/* 
 * Programa:    prog14_01
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 14:
 *              Programa principal de la agenda de usuario gr�fica
 */


#include <gtk/gtk.h>

/* Manejador de se�al : closeAppWindow */
void closeAppWindow (GtkWidget *widget, gpointer *data)
{
    g_print ("\n Agenda de usuario cerrandose \n");
    gtk_main_quit();
}

int main(int argc,char *argv[])
{
    
    /* Definici�n de widgets para la ventana principal y el t�tulo */
    GtkWidget *window;   
    
    /* 
     * Esta llamada es obligatoria en todos las aplicaciones que usan GTK.
     * Lee los argumentos de la linea de comandos de ejecuci�n del programa y 
     * se los pasa a la aplicaci�n. 
     * Adem�s de eso, inicia los par�metros de la biblioteca gr�fica.
     */
    gtk_init (&argc, &argv);

    /* 
     * Creaci�n de una ventana para la aplicaci�n. Es su ventana padre.
     * De ella depender�n las otras que se  arranquen.
     * Todav�a no es visible.
     */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* Configuraci�n de opciones del widget  */    
    gtk_widget_set_usize (GTK_WIDGET (window), 400, 300);
    gtk_window_set_title (GTK_WINDOW (window), "Agenda Electronica");

    /* 
     *   ..... m�s c�digo de configuraci�n   
     */

    /* 
     * Conexi�n de los eventos. 
     * Como ejemplo, s�lo se muestra la conexi�n del evento 
     * "destroy" al manejador de se�ales. Este evento se produce cuando 
     * se llama a closeAppWindow() sobre la ventana.
     */
    gtk_signal_connect (GTK_OBJECT (window), "destroy",
		    	GTK_SIGNAL_FUNC(closeAppWindow), NULL);

    /* 
     *   ..... m�s c�digo de eventos   
     */

    
    /* Definici�n de la esquina superior izquierda de la ventana */
    gtk_widget_set_uposition( window, 400, 200 );
    /* Hace visible la ventana principal */    
    gtk_widget_show (window);

    /* 
     * Todas las aplicaciones que usen GTK deben tener esta llamada. 
     * Mediante esta llamada, la aplicaci�n cede el control hasta que ocurra 
     * un evento (como una pulsaci�n de rat�n, por ejemplo).
     */
    gtk_main ();

    /* Salida del programa con estado OK */																												                             
    return(0);
}
