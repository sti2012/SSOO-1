/*
 * Programa: agenda
 * Modulo  : dialogos_con_fechas
 * Fichero : dialogos_con_fechas.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "dialogos_con_fechas.h"

/*
 * TIPOS DE DATOS
 */
enum OperacionFecha {INSERTAR, BORRAR};

struct datosDialogoFecha
{
    enum OperacionFecha operacion;
    GtkWidget *window;   
    GtkWidget *valor;
    GtkWidget *dia;
    GtkWidget *mes;
    GtkWidget *anho;
    GtkWidget *hora;
    GtkWidget *minuto;
    void (*funcionInsertar)(void *,char *,int,int,int,int,int);
    void (*funcionBorrar)(void *,int,int,int,int,int);
    void *datos;
};

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Función mes2Entero()
 * 
 * Parámetros de entrada:
 *      char * nombre: Nombre del mes
 *      
 * Parámetros de salida:
 *      Devuelve el numero del mes
 *
 * Descripción: 
 *      Devuelve el numero de un mes a partir de su nombre
 */
int mes2Entero(char* nombre)
{ 
    int comparacion;

    comparacion=strcmp(nombre,"Enero");
    if (0 == comparacion) return 1;
  
    comparacion=strcmp(nombre,"Febrero");
    if (0 == comparacion) return 2;
  
    comparacion=strcmp(nombre,"Marzo");
    if (0 == comparacion) return 3;
  
    comparacion=strcmp(nombre,"Abril");
    if (0 == comparacion) return 4;
  
    comparacion=strcmp(nombre,"Mayo");
    if (0 == comparacion) return 5;
  
    comparacion=strcmp(nombre,"Junio");
    if (0 == comparacion) return 6;
  
    comparacion=strcmp(nombre,"Julio");
    if (0 == comparacion) return 7;
  
    comparacion=strcmp(nombre,"Agosto");
    if (0 == comparacion) return 8;
  
    comparacion=strcmp(nombre,"Septiembre");
    if (0 == comparacion) return 9;
  
    comparacion=strcmp(nombre,"Octubre");
    if (0 == comparacion) return 10;
  
    comparacion=strcmp(nombre,"Noviembre");
    if (0 == comparacion) return 11;
  
    comparacion=strcmp(nombre,"Diciembre");
    if (0 == comparacion) return 12;

    return -1;
}


/*
 * Función cargarLista()
 * 
 * Parámetros de entrada:
 *      GList * lista: Lista de nombres para gtk
 *      char * texto: nuevo nombre
 *      
 * Parámetros de salida:
 *      Devuelve Lista de nombres modificada
 *
 * Descripción: 
 *      Se añade el texto pasado como parámetro a la lista tambien pasada
 *      como parámetro. Se devuelve la lista actualizada
 */
GList* cargarLista(GList *lista,char* texto)
{
    lista=g_list_append(lista,texto);
    return(lista);
}


/*
 * Función aceptarDialogoFecha()
 * 
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico a una estructura de tipo 
 *          struct datosDialogoFecha
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
void aceptarDialogoFecha (GtkWidget *widget, gpointer data)
{
    struct datosDialogoFecha *conector;
    gchar *texto, *strdia, *strmes, *stranho, *strhora, *strminuto;
    int dia, mes, anho, hora, minuto;   

    conector=(struct datosDialogoFecha *)data;

    if (NULL != conector->valor){      
        texto=gtk_entry_get_text(GTK_ENTRY(conector->valor));   
    }
    
    if (0 != strcmp(texto,"")) {
        strdia=gtk_entry_get_text(GTK_ENTRY(conector->dia));   
        strmes=gtk_entry_get_text(GTK_ENTRY((GTK_COMBO(conector->mes))->entry));
        stranho=gtk_entry_get_text(GTK_ENTRY(conector->anho));   
        strhora=gtk_entry_get_text(GTK_ENTRY(conector->hora));   
        strminuto=gtk_entry_get_text(GTK_ENTRY(conector->minuto));
        
        dia=atoi(strdia); 
        mes=mes2Entero(strmes);
        if (0 != strcmp(stranho,"")) {
            anho=atoi(stranho);
            if ( (0 < dia) && (dia <= obtenerDiasMes(mes,anho)) ) {
                if ( (0 != strcmp(strhora,"")) && (0 != strcmp(strminuto,"")) ){
                    hora=atoi(strhora);
                    minuto=atoi(strminuto);
                    if ( (0<=hora) && (24>hora) && (0<=minuto) && (60>minuto) ){
                        if (INSERTAR == conector->operacion) {
                            conector->funcionInsertar(conector->datos,texto,
                                                      dia,mes,anho,hora,minuto);
                        } else {
                            conector->funcionBorrar(conector->datos,dia,mes,
                                                    anho,hora,minuto);
                        }
                        gtk_grab_remove(conector->window); 
                        gtk_widget_destroy (conector->window); 
                    } else {
                        dialogoAviso("Hora incorrecta");
                    }
                } else {
                  dialogoAviso("Debe introducir una hora");
                }
            } else {
              dialogoAviso("Fecha incorrecta");
            }
        } else {
          dialogoAviso("Debe introducir una fecha");
        }
    } else {
      dialogoAviso("Introduzca un texto para la cita");
    }
}

/*
 * Función cancelarDialogoFecha()
 * 
 * Parámetros de entrada:
 *      GtkWidget *widget: Widget que realiza la llamada
 *      gpointer data:     puntero generico a una estructura de tipo 
 *          struct datosDialogoFecha
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Callback que se ejecuta al activar el boton de cancelación. Su función
 *      eliminar la ventana de dialogo
 */
void cancelarDialogoFecha (GtkWidget *widget, gpointer data)
{
    struct datosDialogoFecha *conector;

    conector=(struct datosDialogoFecha *)data;
    gtk_grab_remove(conector->window);
    gtk_widget_destroy (conector->window); 
}                             

/*
 * Función dialogoFechaSimple()
 * 
 * Parámetros de entrada:
 *      char * mensaje: 
 *      
 * Parámetros de salida:
 *      Devuelve una estructura de tipo struct datosDialogoFecha 
 *
 * Descripción: 
 *      Esta función genera el widget que muestra el mensaje y solicita la
 *      fecha. Esta función se usa en las dos ventanas de dialogo. En dicha
 *      estructura se pasa el widget creao para ser incluido en cada ventana.
 */
struct datosDialogoFecha dialogoFechaSimple(char * mensaje)
                          
{   
  struct datosDialogoFecha conector;
  
    /* GtkWidget is the storage type for widgets */  
 
    GtkWidget *dia;
    GtkWidget *mes;
    GtkWidget *anho;
    GtkWidget *hora;
    GtkWidget *minuto;  
    GtkWidget *hboxfecha;
    GtkWidget *hboxhora;
    GtkWidget *label1; 
    GtkWidget *vbox;
    GList *listameses=NULL;
    GtkWidget *textocombo;

    /* contenedor para todo */
    vbox = gtk_vbox_new(FALSE, 5);

    /* 
     * muestra el mensaje 
     */       
    label1 = gtk_label_new (mensaje);
    gtk_misc_set_alignment (GTK_MISC(label1), 0, .5);
    gtk_box_pack_start (GTK_BOX(vbox), label1, FALSE, FALSE, 5);
    gtk_widget_show (label1);
     
    /*
     * crea un contenedor para la fecha
     */
    hboxfecha=gtk_hbox_new(FALSE,0);
    label1=gtk_label_new("Fecha");
    gtk_misc_set_alignment (GTK_MISC(label1), 0, .5);
    gtk_box_pack_start (GTK_BOX(vbox), label1, FALSE, FALSE, 0);
    gtk_widget_show(label1);

    /* crea la caja del dia */
    dia = gtk_entry_new_with_max_length(2);
    gtk_widget_set_usize (GTK_WIDGET (dia), 30, 30);
    gtk_entry_set_text (GTK_ENTRY (dia), "");
    gtk_box_pack_start(GTK_BOX(hboxfecha),dia,FALSE,FALSE,0);
    gtk_widget_show(dia);
    label1=gtk_label_new(" de ");
    gtk_misc_set_alignment (GTK_MISC(label1), 0, .5);
    gtk_box_pack_start (GTK_BOX(hboxfecha), label1, FALSE, FALSE, 3);
    gtk_widget_show(label1);
    
    /* crea la caja del mes */
    listameses=cargarLista(listameses,"Enero");
    listameses=cargarLista(listameses,"Febrero");
    listameses=cargarLista(listameses,"Marzo");
    listameses=cargarLista(listameses,"Abril");
    listameses=cargarLista(listameses,"Mayo");
    listameses=cargarLista(listameses,"Junio");
    listameses=cargarLista(listameses,"Julio");
    listameses=cargarLista(listameses,"Agosto");
    listameses=cargarLista(listameses,"Septiembre");
    listameses=cargarLista(listameses,"Octubre");
    listameses=cargarLista(listameses,"Noviembre");
    listameses=cargarLista(listameses,"Diciembre");
    mes=gtk_combo_new();
    textocombo=(GTK_COMBO(mes)->entry);  
    gtk_widget_set_usize (GTK_WIDGET (mes), 80, 35);
    gtk_entry_set_editable(GTK_ENTRY(textocombo),FALSE);
    gtk_combo_set_popdown_strings(GTK_COMBO(mes),listameses);
    gtk_box_pack_start(GTK_BOX(hboxfecha),mes,FALSE,FALSE,0);
    gtk_widget_show(mes);
    label1=gtk_label_new(" de ");
    gtk_misc_set_alignment (GTK_MISC(label1), 0, .5);
    gtk_box_pack_start (GTK_BOX(hboxfecha), label1, FALSE, FALSE, 3);
    gtk_widget_show(label1);

    /* crea la caja del año */
    anho = gtk_entry_new_with_max_length(4);
    gtk_widget_set_usize (GTK_WIDGET (anho), 40, 30);
    gtk_entry_set_text (GTK_ENTRY (anho), "");
    gtk_box_pack_start(GTK_BOX(hboxfecha),anho,FALSE,FALSE,0);
    gtk_widget_show(anho);

    gtk_box_pack_start(GTK_BOX(vbox), hboxfecha,FALSE,FALSE,0);
    gtk_widget_show(hboxfecha);

    /*
     * crea un contenedor para la hora
     */
    label1=gtk_label_new("Hora");
    gtk_misc_set_alignment (GTK_MISC(label1), 0, .5);
    gtk_box_pack_start (GTK_BOX(vbox), label1, FALSE, FALSE, 0);
    hboxhora=gtk_hbox_new(FALSE,0);
    gtk_widget_show(label1);

    /* crea la caja de la hora */
    hora = gtk_entry_new_with_max_length(2);
    gtk_widget_set_usize (GTK_WIDGET (hora), 30, 30);
    gtk_entry_set_text (GTK_ENTRY (hora), "");
    gtk_box_pack_start(GTK_BOX(hboxhora),hora,FALSE,FALSE,0);
    gtk_widget_show(hora);
    label1=gtk_label_new(" : ");
    gtk_misc_set_alignment (GTK_MISC(label1), 0, .5);
    gtk_box_pack_start (GTK_BOX(hboxhora), label1, FALSE, FALSE, 3);
    gtk_widget_show(label1);

    /* crea la caja de los minutos */
    minuto=gtk_entry_new_with_max_length(2);  
    gtk_widget_set_usize (GTK_WIDGET (minuto), 30, 30);
    gtk_entry_set_text (GTK_ENTRY (minuto), "");
    gtk_box_pack_start(GTK_BOX(hboxhora),minuto,FALSE,FALSE,0);
    gtk_widget_show(minuto);
  
    gtk_box_pack_start(GTK_BOX(vbox), hboxhora,FALSE,FALSE,5);
    gtk_widget_show(hboxhora);
    
    /* rellena la estructura de salida */
    conector.window=vbox;
    conector.dia=dia;
    conector.mes=mes;
    conector.anho=anho;
    conector.hora=hora;
    conector.minuto=minuto;    
    
    return(conector);
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función dialogoFecha()
 */
GtkWidget* dialogoFecha( char *titulo, char *mensaje,
                         void (*fAceptar)(void *,int, int, int, int, int), 
                         void *fAceptarPtr )
{
    /* valor y fAceptar */
    struct datosDialogoFecha *conector;

    GtkWidget *window;
    GtkWidget *button1;
    GtkWidget *button2; 
    GtkWidget *hbox1;
    GtkWidget *vbox;
  
  
    /* 
     * Par´ametro a evento
     */  
    conector=malloc(sizeof(struct datosDialogoFecha));
    if (NULL == conector) {
        perror("malloc:");
        return NULL;
    }

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 250, 250);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), titulo);
    gtk_container_border_width (GTK_CONTAINER (window), 10);
  
    /*
     * Dieposici´on de Label y Entry.
     */
    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
  
    /*
     * Llamada a la funcion que presenta la fecha
     */

    (*conector)=dialogoFechaSimple(mensaje);
    gtk_box_pack_start(GTK_BOX(vbox),conector->window,FALSE,FALSE,5);
    gtk_widget_show(conector->window);
   
    /* 
     * Disposición de OK y Cancel
     */
    hbox1 = gtk_hbox_new(FALSE, 40);
    gtk_box_pack_start(GTK_BOX(vbox), hbox1,FALSE,FALSE,10);

    /* 
     * OK y Cancel
     */
    button1 = gtk_button_new_with_label ("Aceptar");
    button2 = gtk_button_new_with_label ("Cancelar");
    gtk_box_pack_start(GTK_BOX(hbox1),button1,FALSE,FALSE,20); 
    gtk_box_pack_start(GTK_BOX(hbox1),button2,FALSE,FALSE,20);   
    gtk_widget_show (button1);
    gtk_widget_show (button2);
            
    /* 
     * Mostrar
     */
    gtk_widget_show (hbox1);
    gtk_widget_show (vbox);
    gtk_widget_set_uposition( window, 400,250 );   
    gtk_grab_add(window);
    gtk_widget_show (window);
   
    /* 
     * Eventos
     */
    conector->operacion=BORRAR;
    conector->valor=NULL;
    conector->funcionBorrar=fAceptar;
    conector->funcionInsertar=NULL;
    conector->datos=fAceptarPtr;
    conector->window=window;
    gtk_signal_connect(GTK_OBJECT(button1), "clicked",
                       GTK_SIGNAL_FUNC(aceptarDialogoFecha),
                       (gpointer)conector);
    gtk_signal_connect(GTK_OBJECT(button2), "clicked",
                       GTK_SIGNAL_FUNC(cancelarDialogoFecha),
                       (gpointer)conector);       

    
    return window;
  
}

/*
 * Función dialogoCita()
 */
GtkWidget* dialogoCita (char *titulo, char * mensaje,
                        void (*fAceptar)(void *,char *,int,int,int,int,int),
                        void *fAceptarPtr )
{
    /* valor y fAceptar */
    struct datosDialogoFecha *conector;

    /* GtkWidget is the storage type for widgets */  
    GtkWidget *window;   
    GtkWidget *valor;    
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *vbox;
    GtkWidget *hbox1;
    GtkWidget *label;

    /* 
     * Par´ametro a evento
     */  
    conector=malloc(sizeof(struct datosDialogoFecha));
    if (NULL == conector) {
        perror("malloc:");
        return NULL;
    }
    
    /* 
     * Dialog
     */  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize (GTK_WIDGET (window), 250, 300);
    gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, FALSE);      
    gtk_window_set_title (GTK_WINDOW (window), titulo);
    gtk_container_border_width (GTK_CONTAINER (window), 10);

    /*
     * Dieposici´on de Label y Entry.
     */
    vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    
   /*
    * Llamada a la funcion que presenta la fecha
    */
    (*conector)=dialogoFechaSimple(mensaje);
    gtk_box_pack_start(GTK_BOX(vbox),conector->window,FALSE,FALSE,5);
    gtk_widget_show(conector->window);

    label=gtk_label_new("Proposito de la cita");
    gtk_misc_set_alignment (GTK_MISC(label), 0, .5);   
    gtk_box_pack_start (GTK_BOX(vbox), label, FALSE, FALSE, 0);
    gtk_widget_show(label);
    valor = gtk_entry_new();
    gtk_widget_set_usize (GTK_WIDGET (valor),100, 30);
    gtk_entry_set_text (GTK_ENTRY (valor), "");

    gtk_box_pack_start (GTK_BOX(vbox), valor, FALSE, FALSE, 0);
    gtk_widget_show (valor);
    
    /* 
     * Dieposici´on de OK y Cancel

     */
    hbox1 = gtk_hbox_new(FALSE, 40);
    gtk_box_pack_start(GTK_BOX(vbox), hbox1,FALSE,FALSE,5);
    
    /* 
     * OK y Cancel
     */
    button1 = gtk_button_new_with_label ("Aceptar");
    button2 = gtk_button_new_with_label ("Cancelar");
    gtk_box_pack_start(GTK_BOX (hbox1), button1,FALSE,FALSE,20); 
    gtk_box_pack_start(GTK_BOX (hbox1), button2,FALSE,FALSE,0); 
    gtk_widget_show (button1);
    gtk_widget_show (button2);
    
    /* 
     * Eventos
     */
    conector->operacion=INSERTAR;
    conector->valor=valor;
    conector->funcionInsertar=fAceptar;
    conector->funcionBorrar=NULL;
    conector->datos=fAceptarPtr;
    conector->window=window;
    gtk_signal_connect(GTK_OBJECT(button1), "clicked",
                       GTK_SIGNAL_FUNC(aceptarDialogoFecha), conector);
    gtk_signal_connect(GTK_OBJECT(button2), "clicked",
                       GTK_SIGNAL_FUNC(cancelarDialogoFecha), conector);       
    
    /* 
     * Mostrar
     */
    gtk_widget_show (hbox1);
    gtk_widget_show (vbox);
    gtk_widget_set_uposition( window, 400, 250 );   
    gtk_grab_add(window);
    gtk_widget_show (window);

    return window;
} 
