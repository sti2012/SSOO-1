/*
 * Programa: agenda
 * Modulo  : menu_direcciones
 * Fichero : menu_direcciones.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_direcciones.h"
#include "util.h"

/* 
 * TIPOS DE DATOS 
 */

#define NUM_LETRAS 28

enum OperacionDir {INSERTAR, BORRAR, CONSULTAR};

struct datosDir{
    GtkWidget* window;
    enum OperacionDir operacion;
    GtkWidget* nombre;
    GtkWidget* direccion;
    GtkWidget* telefono;
};

typedef struct datosDir DatosDir;


/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función mostrarConsultaWindow()
 *
 * Parámetros de entrada:
 *      char * dir[3]: nombre direccion y telefono a mostrar
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Mostrar en la pantalla una única consulta
 */
void mostrarConsultaWindow(char* dir[3])
{
    GtkWidget *datos;
    GtkWidget *window;
  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 300, 300);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), "Libro de direcciones");
    gtk_container_border_width (GTK_CONTAINER (window), 10);    
    gtk_widget_set_uposition( window, 300, 300 );   
  
    datos=gtk_clist_new(3);
    gtk_clist_set_column_title(GTK_CLIST(datos),0,"Nombre");    
    gtk_clist_set_column_title(GTK_CLIST(datos),1,"Direccion");
    gtk_clist_set_column_title(GTK_CLIST(datos),2,"Telefono");
    gtk_clist_column_titles_show(GTK_CLIST(datos));
    gtk_clist_set_column_width(GTK_CLIST(datos),0,100);
    gtk_clist_set_column_width(GTK_CLIST(datos),1,100);
    gtk_clist_set_column_width(GTK_CLIST(datos),2,50);          
    gtk_container_add (GTK_CONTAINER (window), datos); 
    gtk_clist_append(GTK_CLIST(datos),dir);   
    gtk_widget_show(datos);
    gtk_grab_add(window);
    gtk_widget_show(window);
} 

/*
 * Función AceptarDireccionDialogo()
 *
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico a una estructura de tipo 
 *          struct datosDir
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Manejados de la opcion de aceptar para las ventanas de
 *      inserción consulta y borrado de direcciones
 */

void AceptarDireccionDialogo(GtkWidget *widget, gpointer data)
{
    DatosDir *conector;
    gchar *nombre, *direccion, *telefono;
    char *datos[3];
    int aux,pos,error;
  
    conector=(DatosDir*)data;
    switch (conector->operacion) {

    case INSERTAR:  
        nombre=gtk_entry_get_text(GTK_ENTRY(conector->nombre));
        direccion=gtk_entry_get_text(GTK_ENTRY(conector->direccion));
        telefono=gtk_entry_get_text(GTK_ENTRY(conector->telefono));
        if (0 != strcmp(nombre,"")) {
            error=insertarDir((&datosAgenda.direcciones),nombre,
                               direccion,telefono);
            if (0 == error) {
                dialogoAviso("Direccion insertada");
            } else {
                dialogoAviso("No se pudo insertar la direccion");
            }
            gtk_grab_remove(conector->window);
            gtk_widget_destroy (conector->window); 
        } else {
            dialogoAviso("El campo nombre no debe tener valor nulo");
        }
        break;
        
    case BORRAR:    
        nombre=gtk_entry_get_text(GTK_ENTRY(conector->nombre));
        if (0 != strcmp(nombre,"")) {
            error=borrarDir((&datosAgenda.direcciones),nombre);      
            gtk_grab_remove(conector->window);
            gtk_widget_destroy (conector->window); 
            if (0 == error) {
                dialogoAviso("Direccion eliminada");
            } else {
                dialogoAviso("El nombre introducido no estaba en el libro de direcciones");
            }
        } else {
            dialogoAviso("Debe introducir un nombre");
        }
        break;

    case CONSULTAR:
        nombre=gtk_entry_get_text(GTK_ENTRY(conector->nombre));
        if (0 != strcmp(nombre,"")) {
            direccion=(char *)malloc(256);
            telefono=(char *)malloc(256);
            aux = consultarDirPorNombre((&datosAgenda.direcciones),nombre,
                                        &pos,&direccion,&telefono);
            datos[0]=stringDup(nombre);
            datos[1]=stringDup(direccion);
            datos[2]=stringDup(telefono);
            gtk_grab_remove(conector->window);
            gtk_widget_destroy (conector->window); 
            if (0 == aux) {
                /* Mostrar datos*/
                mostrarConsultaWindow(datos);
            } else {
                dialogoAviso("El nombre buscado no esta en el libro de direcciones");
            }        
        } else {
            dialogoAviso("Debe introducir un nombre");
        }
        break;
    }
}

/*
 * Función AceptarDireccionDialogo()
 *
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico a una estructura de tipo 
 *          struct datosDir
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Manejados de la opcion de cancelar para las ventanas de
 *      inserción consulta y borrado de direcciones
 */
void cancelarDireccionDialogo(GtkWidget *widget, gpointer data)
{
    DatosDir *conector;
  
    conector=(DatosDir*)data;
    gtk_grab_remove(conector->window);
    gtk_widget_destroy (conector->window); 
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función listarDireccionWindow()
 */
void listarDireccionWindow (void)
{
    int i, num, ret, indice;
    char *nombre, *direccion, *telefono;
    GtkWidget *datos[NUM_LETRAS];
    GtkWidget *window;
    GtkWidget *libro;
    GtkWidget *label;
    GtkWidget *scroll;
    char* dir[3];
    char letras[NUM_LETRAS][2]={"#","A","B","C","D","E","F","G","H","I","J","K","L","M","N","Ñ","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    char inicial;

    /* 
     * Dialog
     */  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 585, 300);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), "Libro de direcciones");
    gtk_container_border_width (GTK_CONTAINER (window), 10);    
    gtk_widget_set_uposition( window, 300, 300 );   
  
    libro=gtk_notebook_new(); 
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(libro),GTK_POS_TOP);      
    for (indice=0;indice<NUM_LETRAS;indice++) {    
        scroll = gtk_scrolled_window_new (NULL, NULL);
        gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll),
                                        GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
        datos[indice]=gtk_clist_new(3);
        gtk_container_add(GTK_CONTAINER(scroll), datos[indice]);
        gtk_clist_set_column_title(GTK_CLIST(datos[indice]),0,"Nombre");    
        gtk_clist_set_column_title(GTK_CLIST(datos[indice]),1,"Direccion");
        gtk_clist_set_column_title(GTK_CLIST(datos[indice]),2,"Telefono");
        gtk_clist_column_titles_show(GTK_CLIST(datos[indice]));
        gtk_clist_set_column_width(GTK_CLIST(datos[indice]),0,175);
        gtk_clist_set_column_width(GTK_CLIST(datos[indice]),1,250);
        gtk_clist_set_column_width(GTK_CLIST(datos[indice]),2,75);          
        label=gtk_label_new(letras[indice]); 
        gtk_widget_set_usize(label,10,10);
        gtk_notebook_append_page((GtkNotebook*)libro,scroll,label);     
    }  
    num=numeroDir((&datosAgenda.direcciones));    
    gtk_container_add (GTK_CONTAINER (window),libro);
    for (i=0; i<num; i++) {
        ret = consultarDir((&datosAgenda.direcciones),i,&nombre, 
                           &direccion, &telefono);        
        if (0 == ret) { 
            dir[0]=stringDup(nombre);
            dir[1]=stringDup(direccion);
            dir[2]=stringDup(telefono);

            /*
             * Buscamos en el array de letras, la inicial del nombre. 
             * Insertaremos sus datos en la lista correspondiente.
             */    
            inicial=toupper(nombre[0]);
            indice=NUM_LETRAS-1;
            while ( (letras[indice][0]!=inicial) && (0 < indice) ) {    
                indice--;
            }
            gtk_clist_append(GTK_CLIST(datos[indice]),dir);
        }
    }
    gtk_grab_add(window);
    gtk_widget_show_all(window);
}

/*
 * Función insertarDireccionDialogo()
 */
void insertarDireccionDialogo (void)
{
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *nombre;
    GtkWidget *direccion;
    GtkWidget *telefono;
    GtkWidget *box;
    GtkWidget *botonAceptar;
    GtkWidget *botonCancelar;
    GtkWidget *hbox1;
    DatosDir *conector;

    conector=malloc(sizeof(DatosDir));
    if (NULL == conector) {
        perror("malloc:");
        return;
    }
  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 300, 200);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), "Insertar dirección");
    gtk_container_border_width (GTK_CONTAINER (window), 10);   
    gtk_widget_set_uposition( window, 300, 300 );     

    box=gtk_vbox_new(FALSE,5);
  
    label=gtk_label_new("Introduzca el nombre:");
    gtk_misc_set_alignment (GTK_MISC(label), 0, .5);
    gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,0);
 
    nombre=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box),nombre,FALSE,FALSE,0);
  
    label=gtk_label_new("Introduzca la direccion:");
    gtk_misc_set_alignment (GTK_MISC(label), 0, .5);
    gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,0);
   
    direccion=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box),direccion,FALSE,FALSE,0);

    label=gtk_label_new("Introduzca el telefono:");
    gtk_misc_set_alignment (GTK_MISC(label), 0, .5);
    gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,0);

    telefono=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box),telefono,FALSE,FALSE,0);

    hbox1=gtk_hbox_new(FALSE,40);

    /* 
     * OK y Cancel
     */
    botonAceptar = gtk_button_new_with_label ("Aceptar");
    botonCancelar = gtk_button_new_with_label ("Cancelar"); 
  
    conector->window=window;
    conector->nombre=nombre;
    conector->operacion=INSERTAR;
    conector->direccion=direccion;
    conector->telefono=telefono;
    gtk_container_add (GTK_CONTAINER (hbox1), botonAceptar); 
    gtk_container_add (GTK_CONTAINER (hbox1), botonCancelar); 
    gtk_signal_connect(GTK_OBJECT(botonAceptar), "clicked",
                       GTK_SIGNAL_FUNC(AceptarDireccionDialogo), 
                       (gpointer)conector);
    gtk_signal_connect(GTK_OBJECT(botonCancelar), "clicked",
                       GTK_SIGNAL_FUNC(cancelarDireccionDialogo),
                       (gpointer)conector);    
                       
    gtk_widget_show (botonAceptar);
    gtk_widget_show (botonCancelar);
  
    gtk_box_pack_start(GTK_BOX(box),hbox1,FALSE,FALSE,15);
  
    gtk_container_add (GTK_CONTAINER (window), box);  
    gtk_grab_add(window);
    gtk_widget_show_all(window);
}

/*
 * Función consultarNombreDialogo()
 */
void consultarNombreDialogo(void)
{
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *nombre;
    GtkWidget *box;
    GtkWidget *botonAceptar;
    GtkWidget *botonCancelar;
    GtkWidget *hbox1;
    DatosDir *conector;

    conector=malloc(sizeof(DatosDir));
    if (NULL == conector) {
        perror("malloc:");
        return;
    }
  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 300, 125);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), "Consultar dirección");
    gtk_container_border_width (GTK_CONTAINER (window), 10);   
    gtk_widget_set_uposition( window, 300, 300 );     
  
    box=gtk_vbox_new(FALSE,5);
  
    label=gtk_label_new("Introduzca el nombre a consultar: ");
    gtk_misc_set_alignment (GTK_MISC(label), 0, .5);
    gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,0);
  
    nombre=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box),nombre,FALSE,FALSE,0);
  
    hbox1=gtk_hbox_new(FALSE,40);

    /* 
     * OK y Cancel
     */
    botonAceptar = gtk_button_new_with_label ("Aceptar");
    botonCancelar = gtk_button_new_with_label ("Cancelar");
    
    conector->window=window;
    conector->nombre=nombre;
    conector->operacion=CONSULTAR;
    conector->direccion=NULL;
    conector->telefono=NULL;
    gtk_container_add (GTK_CONTAINER (hbox1), botonAceptar); 
    gtk_container_add (GTK_CONTAINER (hbox1), botonCancelar); 
    gtk_signal_connect(GTK_OBJECT(botonAceptar), "clicked",
                       GTK_SIGNAL_FUNC(AceptarDireccionDialogo), 
                       (gpointer)conector);
    gtk_signal_connect(GTK_OBJECT(botonCancelar), "clicked",
                       GTK_SIGNAL_FUNC(cancelarDireccionDialogo),
                       (gpointer)conector);    
    gtk_widget_show (botonAceptar);
    gtk_widget_show (botonCancelar);
  
    gtk_box_pack_start(GTK_BOX(box),hbox1,FALSE,FALSE,15);
  
    gtk_container_add (GTK_CONTAINER (window), box);  
    gtk_grab_add(window);
    gtk_widget_show_all(window);
}

/*
 * Función borrarDireccionDialogo()
 */
void borrarDireccionDialogo (void)
{ 
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *nombre;
    GtkWidget *box;
    GtkWidget *botonAceptar;
    GtkWidget *botonCancelar;
    GtkWidget *hbox1;
    DatosDir *conector;

    conector=malloc(sizeof(DatosDir));
    if (NULL == conector) {
        perror("malloc:");
        return;
    }
  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 300, 125);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), "Eliminar dirección");
    gtk_container_border_width (GTK_CONTAINER (window), 10);   
    gtk_widget_set_uposition( window, 300, 300 );     
  
    box=gtk_vbox_new(FALSE,5);
  
    label=gtk_label_new("Introduzca el nombre a borrar");
    gtk_misc_set_alignment (GTK_MISC(label), 0, .5);
    gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,0);

    nombre=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box),nombre,FALSE,FALSE,0);
  
    hbox1=gtk_hbox_new(FALSE,40);

    /* 
     * OK y Cancel
     */
    botonAceptar = gtk_button_new_with_label ("Aceptar");
    botonCancelar = gtk_button_new_with_label ("Cancelar");
  
    conector->window=window;
    conector->nombre=nombre;
    conector->operacion=BORRAR;
    conector->direccion=NULL;
    conector->telefono=NULL;
    gtk_container_add (GTK_CONTAINER (hbox1), botonAceptar); 
    gtk_container_add (GTK_CONTAINER (hbox1), botonCancelar); 
    gtk_signal_connect(GTK_OBJECT(botonAceptar), "clicked",
                       GTK_SIGNAL_FUNC(AceptarDireccionDialogo), 
                       (gpointer)conector);
    gtk_signal_connect(GTK_OBJECT(botonCancelar), "clicked",
                       GTK_SIGNAL_FUNC(cancelarDireccionDialogo),
                       (gpointer)conector);    
    gtk_widget_show (botonAceptar);
    gtk_widget_show (botonCancelar);

    gtk_box_pack_start(GTK_BOX(box),hbox1,FALSE,FALSE,15);
  
    gtk_container_add (GTK_CONTAINER (window), box);  
    gtk_grab_add(window);
    gtk_widget_show_all(window);
}


