/*
 * Programa: agenda
 * Modulo  : menu_intro
 * Fichero : menu_intro.c
 */

/*
 * FICHEROS INCLUDES 
 */
#include "menu_intro.h"

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Función closeIntroWindow()
 *
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico para pasar datos
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Manejador del evento cerra ventana. Finaliza el bucle gtk_main()
 */
void closeIntroWindow (GtkWidget *widget, gpointer *data)
{
    g_print ("\n Agenda de usuario cerrandose \n");
    gtk_main_quit();
}

/*
 * Función clickBoton1IntroWindow()
 *
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico para pasar el widget de la ventana
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Manejador del evento pulsar boton 1. Arranca la ventana de la agenda
 */
void clickBoton1IntroWindow(GtkWidget *widget, gpointer *data)
{
    GtkWidget *ventana;

    ventana=(GtkWidget *)data;
    g_print ("Opcion 1: Acceder a Agenda Electronica\n");
    gtk_widget_hide(ventana);
    agendaWindow();
}

/*
 * Función clickBotons2IntroWindow()
 *
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico para pasar datos
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Manejador del evento pulsar boton 2. Finaliza el bucle gtk_main()
 */

/* Manejador de evento: introWindow_click_botton2 */
void clickBoton2IntroWindow()
{
    g_print ("Opcion 2: Salir de la aplicacion\n");
    gtk_main_quit ();
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función introWindow()
 */
void introWindow (void)
{
    /* GtkWidget es el tipo de almancenamiento para los widgets */
    GtkWidget *window;   
    GtkWidget *title;
    GtkWidget *option1;
    GtkWidget *option2;
    GtkWidget *box;
    
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
    
    /* 
     * Aquí se conecta el evento "destroy" a un manejador de señal.
     * Este evento se produce cuando se llama a gtk_widget_destroy() 
     * en la ventana 
     */
    gtk_signal_connect (GTK_OBJECT (window), "destroy",
                        GTK_SIGNAL_FUNC(closeIntroWindow), NULL);

    /* 
     * Conecta el evento "clicked" al manejador de evento 
     * clickBoton1IntroWindow 
     */
    gtk_signal_connect (GTK_OBJECT (option1), "clicked",
                        GTK_SIGNAL_FUNC(clickBoton1IntroWindow), 
                        (gpointer)window);

    /* 
     * Conecta el evento "clicked" al manejador de evento 
     * clickBoton2IntroWindow 
     */
    gtk_signal_connect (GTK_OBJECT (option2), "clicked",
                        GTK_SIGNAL_FUNC(clickBoton2IntroWindow), NULL);

    /* Muestra los botones */
    gtk_widget_show (option1);
    gtk_widget_show (option2);

    /* y la caja */
    gtk_widget_show (box);

    gtk_widget_set_uposition( window, 350, 200 );
    
    /* y la ventana */
    gtk_widget_show (window);
}


