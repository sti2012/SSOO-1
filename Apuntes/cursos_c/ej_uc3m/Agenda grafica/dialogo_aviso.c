/*
 * Programa: agenda
 * Modulo  : dialogo_aviso
 * Fichero : dialogo_aviso.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "dialogo_aviso.h"


/*
 * FUNCIONES PRIVADAS
 */


/*
 * Función cerrarDialogoAviso()
 * 
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico al widget de la ventana de dialogo
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Callback que se ejecuta al activar el boton de confirmación. Su función
 *      es eliminar la ventana de dialogo
 */
 
void cerrarDialogoAviso(GtkWidget *widget, gpointer data)
{
    gtk_grab_remove(GTK_WIDGET(data));
    gtk_widget_destroy(GTK_WIDGET(data));
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función dialogoAviso()
 */
void dialogoAviso(char* mensaje)
{
    GtkWidget *label;
    GtkWidget * boton;
    GtkWidget *dialogo;
  
    /* Crear una ventana de dialogo */
    dialogo=gtk_dialog_new();
    gtk_widget_set_uposition(dialogo, 400, 300 );     

    /* Se establece el manejador de la ventana */
    gtk_signal_connect(GTK_OBJECT(dialogo),"destroy",
                       GTK_SIGNAL_FUNC(cerrarDialogoAviso),
                       (gpointer)dialogo);
    /*
     * Añadir titulo
     */
    gtk_window_set_title(GTK_WINDOW(dialogo),"Aviso");
    gtk_container_border_width(GTK_CONTAINER(dialogo),5);

    /* Crear una etiqueta con el mensaje */
    label=gtk_label_new(mensaje);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogo)->vbox),label,TRUE,TRUE,0);
    gtk_widget_show(label);

    /* Se crea el boton de "OK" */
    boton=gtk_button_new_with_label("Aceptar");

    /* Asociamos el manejador del boton */
    gtk_signal_connect(GTK_OBJECT(boton),"clicked",
                       GTK_SIGNAL_FUNC(cerrarDialogoAviso),
                       (gpointer)dialogo);

    /* Permitir que el boton sea predeterminado */
    GTK_WIDGET_SET_FLAGS(boton,GTK_CAN_DEFAULT);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogo)->action_area),
                       boton,TRUE,TRUE,0);

    /* Hacer que el boton sea predeterminado */
    gtk_widget_grab_default(boton);
    gtk_widget_show(boton);
    gtk_widget_show(dialogo);

    /* Hacer el cuadro de dialogo modal */
    gtk_grab_add(dialogo);

}
