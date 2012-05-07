/*
 * Programa: agenda
 * Modulo  : dialogo_datos
 * Fichero : dialogo_datos.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "dialogo_datos.h"

/*
 * TIPOS DE DATOS 
 */
struct datosDialogo
{
    GtkWidget *window;   
    GtkWidget *valor;
    void (*funcion)(void *, char *);
    void *datos;
};

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función aceptarDialogoDatos()
 * 
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico a una estructura de tipo 
 *          struct datosDialogo
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Callback que se ejecuta al activar el boton de confirmación. Su función
 *      es ejecutar la función de Callback para almacenar los datos introducidos
 *      (dicha función esta en struct datosDialogo) y luego eliminar la ventana
 *      de dialogo
 */
void aceptarDialogoDatos (GtkWidget *widget, gpointer data)
{
    struct datosDialogo *conector;
    char *texto;

    conector=(struct datosDialogo *)data;
    texto=gtk_entry_get_text(GTK_ENTRY(conector->valor));
    if (0 != strcmp(texto,"")) {
        conector->funcion(conector->datos,texto);
        gtk_grab_remove(conector->window);
        gtk_widget_destroy (conector->window); 
    } else {
        dialogoAviso("Debe introducir un valor");
    }
}

/*
 * Función cancelarDialogoDatos()
 * 
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico a una estructura de tipo 
 *          struct datosDialogo
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Callback que se ejecuta al activar el boton de cancelación. Su función
 *      eliminar la ventana de dialogo
 */
void cancelarDialogoDatos (GtkWidget *widget, gpointer data)
{
    struct datosDialogo *conector;

    conector=(struct datosDialogo *)data;
    gtk_grab_remove(conector->window);
    gtk_widget_destroy (conector->window); 
}                             

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función dialogoDatos()
 */
GtkWidget* dialogoDatos (char *titulo, char * mensaje, 
                         void (*fAceptar)(void *, char *), void *fAceptarPtr)
{
    /* valor y fAceptar */
    struct datosDialogo *conector;

    /* GtkWidget is the storage type for widgets */  
    GtkWidget *window;   
    GtkWidget *valor;
    GtkWidget *label1;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *vbox;
    GtkWidget *hbox1;
    
    /* 
     * Parámetro a evento
     */  
    conector=malloc(sizeof(struct datosDialogo));
    if (NULL == conector) {
        perror("malloc:");
        return NULL;
    }

    /* 
     * Dialog
     */  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 300, 125);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), titulo);
    gtk_container_border_width (GTK_CONTAINER (window), 10);

    /*
     * Dieposici´on de Label y Entry.
     */
    vbox = gtk_vbox_new(TRUE, 5);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    
    /* 
     * Label 
     */       
    label1 = gtk_label_new (mensaje);
    gtk_misc_set_alignment (GTK_MISC(label1), 0, 1);
    gtk_box_pack_start (GTK_BOX(vbox), label1, TRUE, TRUE, 0);
    gtk_widget_show (label1);
    
    /* 
     * Entry
     */
    valor = gtk_entry_new();
    gtk_entry_set_text (GTK_ENTRY (valor), "");
    gtk_box_pack_start (GTK_BOX(vbox), valor, FALSE, FALSE, 0);
    gtk_widget_show (valor);
    
    /* 
     * Dieposici´on de OK y Cancel
     */
    hbox1 = gtk_hbox_new(FALSE, 40);
    gtk_box_pack_start (GTK_BOX(vbox), hbox1, FALSE, FALSE, 0);   

    /* 
     * OK y Cancel
     */
    button1 = gtk_button_new_with_label ("Aceptar");
    button2 = gtk_button_new_with_label ("Cancelar");
    gtk_container_add (GTK_CONTAINER (hbox1), button1); 
    gtk_container_add (GTK_CONTAINER (hbox1), button2); 
    gtk_widget_show (button1);
    gtk_widget_show (button2);
    
    /* 
     * Eventos
     */
    conector->valor=valor;
    conector->funcion=fAceptar;
    conector->datos=fAceptarPtr;
    conector->window=window;
    gtk_signal_connect(GTK_OBJECT(button1), "clicked",
                       GTK_SIGNAL_FUNC(aceptarDialogoDatos), conector);
    gtk_signal_connect(GTK_OBJECT(button2), "clicked",
                       GTK_SIGNAL_FUNC(cancelarDialogoDatos), conector);       
    
    /* 
     * Mostrar
     */
    gtk_widget_show (hbox1);
    gtk_widget_show (vbox);
    gtk_widget_set_uposition( window, 300, 300 );   
    gtk_grab_add(window);
    gtk_widget_show (window);

    return window;
} 

