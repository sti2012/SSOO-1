/*
 * Programa: agenda
 * Modulo  : menu_agenda
 * Fichero : menu_agenda.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_agenda.h"

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Función salirAgendaWindow()
 *
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico para pasar datos
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Manejador de evento . Finaliza el bucle gtk_main()
 */
static void salirAgendaWindow()
{
    g_message("Salimos del programa");
    gtk_main_quit();
}


/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función agendaWindow()
 */
void agendaWindow (void)
{
    GtkWidget *ventana;
    GtkWidget *menu;
    GtkWidget *cuerpo;

    GtkWidget *calendario;
    GtkWidget *notas;
    GtkWidget *citas;   
    GtkWidget *global;  

    /* Crear ventana principal de la aplicacion*/
    ventana=gtk_window_new (GTK_WINDOW_TOPLEVEL);
    /* Definir el tamaño */
    gtk_widget_set_usize(ventana,700,400);
    gtk_widget_set_uposition(ventana, 200, 200 );     
    /* 
     * Se asocian las funciones a los eventos. En este caso se cubren los
     * eventos de destrucción y cierre de la ventana principal
     */
    gtk_signal_connect (GTK_OBJECT (ventana), "destroy", 
                        GTK_SIGNAL_FUNC(gtk_widget_destroyed),&ventana); 
    gtk_signal_connect (GTK_OBJECT (ventana), "delete_event", 
                        GTK_SIGNAL_FUNC(salirAgendaWindow), NULL);
    /* Titulo de la ventana */
    gtk_window_set_title (GTK_WINDOW (ventana), "Ventana de citas"); 
    /* Borde de la ventana */
    gtk_container_border_width(GTK_CONTAINER(ventana),2);

    /*-------------------------------------------------------------------*/

    /* 
     * Se crea una nueva caja horizontal de empaquetado no 
     * homogenea en la que se almacenara el cuerpo de la ventana
     */
    cuerpo=gtk_hbox_new(FALSE,0);  
    /* Se almacena el widget notas en la caja de almacenamiento cuerpo */
    notas=notasWidget();      
    gtk_box_pack_start(GTK_BOX(cuerpo), notas, FALSE, FALSE, 0);
    gtk_widget_show (notas);
    /* Se almacena el widget calendario en la caja de almacenamiento cuerpo */
    calendario=calendarioWidget();
    gtk_box_pack_start(GTK_BOX(cuerpo),calendario,FALSE,FALSE,10);
    gtk_widget_show(calendario);
    /* Se almacena el widget citas en la caja de almacenamiento cuerpo */
    citas=citasWidget();      
    gtk_box_pack_start(GTK_BOX(cuerpo),citas,FALSE,FALSE,10); 
    gtk_widget_show(citas);

    /*-------------------------------------------------------------------*/

    /* 
     * Se crea una nueva tabla de empaquetado de 2 filas y 2 columnas no 
     * homogenea 
     */
    global=gtk_table_new(2,2,FALSE);
    /* 
     * Se inserta en la 1 fila de la tabla de almacenamiento global, el menu
     */
    menu=crearMenu(ventana);
    gtk_table_attach(GTK_TABLE(global),menu,0,2,0,1,
                            GTK_FILL|GTK_EXPAND,GTK_FILL,0,0);
    gtk_widget_show(menu); 
    /* 
     * Se inserta en la 2 fila de la tabla de almacenamiento global, el cuerpo 
     */
    gtk_table_attach(GTK_TABLE(global),cuerpo,0,1,1,2,0,0,0,0);
    gtk_widget_show(cuerpo); 
    
    /* El contenedor de la ventana principal almacena ahora la tabla global */
    gtk_container_add(GTK_CONTAINER(ventana),global);  
  
    /* 
     * Se muestra todo dentro de la ventana, tanto las notas, como las posibles
     * citas correspondientes al dia de hoy marcado en el calendario
     */
    listarNotasWidget();
    actualizarCitasWidget();
    gtk_widget_show_all(ventana); 
}


