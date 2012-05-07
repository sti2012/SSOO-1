/* 
 * Programa:    prog14_03
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 14:
 *              Programa de la ventana inicial de la agenda
 */

#include <gtk/gtk.h>

/* Manejador de evento: closeAppWindow */
void closeAppWindow (GtkWidget *widget, gpointer *data)
{
    g_print ("\n Agenda de usuario cerrandose \n");
    gtk_main_quit();
}

/* Manejador de evento: clickButton1 */
void clickButton1()
{
    g_print ("Opcion 1: Acceder a Agenda Electronica\n");
}

/* Manejador de evento: click_botton4*/
void clickButton2()
{
    g_print ("Opcion 2: Salir de la aplicacion\n");
    gtk_main_quit ();
}

int main( int argc,char *argv[])
{
    
    /* GtkWidget es el tipo de almancenamiento para los widgets */
    GtkWidget *window;   
    GtkWidget *title;
    GtkWidget *option1;
    GtkWidget *option2;
    GtkWidget *box;
    
    /* Esto se llama en todas las aplicaciones del GTK. Los argumentos se leen 
     * de la linea de comandos y son filtrados y devueltos a la aplicación.
     */
    gtk_init (&argc, &argv);

    /* Crea una nueva ventana */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    
    /* Crea una caja con botones */
    box = gtk_vbutton_box_new ();

    /* Esto empaqueta la caja en la ventana (un contenedor gtk) */
    gtk_container_add (GTK_CONTAINER (window), box);
    
    /* Crear una nueva etiqueta */
    title = gtk_label_new ("BIENVENIDO A AGENDA ELECTRONICA\n");
    
    gtk_misc_set_alignment (GTK_MISC (title), 0.5, 0);

    /* Empaqueta el título en la caja */
    gtk_box_pack_start (GTK_BOX(box), title, FALSE, FALSE, 0);

    /* Mostrar el título */
    gtk_widget_show (title);
    
    gtk_widget_set_usize (GTK_WIDGET (window), 400, 300);
    gtk_window_set_title (GTK_WINDOW (window), "Agenda Electronica");
  
    /* Define la anchura del borde de la ventana.  */
    gtk_container_border_width (GTK_CONTAINER (window), 60);

    /* Crea cuatro ventanas para las etiquetas */
    option1 = gtk_button_new_with_label ("Acceder a la agenda de usuario.");
    option2 = gtk_button_new_with_label ("Salir de la aplicacion.");
    
    /* Esto empaqueta los cuatro botones en la caja (un contenedor gtk) */
    gtk_container_add (GTK_CONTAINER (box), option1);
    gtk_container_add (GTK_CONTAINER (box), option2);
    
    /* Aquí se conecta el evento "destroy" a un manejador de señal.
     * Este evento se produce cuando se llama a gtk_widget_destroy() en la ventana */
    gtk_signal_connect (GTK_OBJECT (window), "destroy",
		    	GTK_SIGNAL_FUNC(closeAppWindow), NULL);

    /* Conecta el evento "clicked" al manejador de evento clickButton1 */
    gtk_signal_connect (GTK_OBJECT (option1), "clicked",
		    	GTK_SIGNAL_FUNC(clickButton1), NULL);

    /* Conecta el evento "clicked" al manejador de evento clickButton2 */
    gtk_signal_connect (GTK_OBJECT (option2), "clicked",
		    	GTK_SIGNAL_FUNC(clickButton2), NULL);

    /* Muestra los botones */
    gtk_widget_show (option1);
    gtk_widget_show (option2);

    /* y la caja */
    gtk_widget_show (box);

  
    gtk_widget_set_uposition( window, 400, 200 );
    
    /* y la ventana */
    gtk_widget_show (window);

    /* Todas las aplicaciones GTK deben tener un gtk_main(). El control termina 
     * aquí y espera a que ocurran eventos (como una pulsación de tecla o ratón)
     */
    gtk_main ();

    return(0);
}


