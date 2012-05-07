/*
 * Programa: agenda
 * Modulo  : menu_citas
 * Fichero : menu_citas.c
 */

/*
 * FICHEROS INCLUDES
 */

#include "menu_citas.h"
#include "dialogos_con_fechas.h"

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Función introducirCitaWidget()
 *
 * Parámetros de entrada:
 *      void * citas:  puntero generico a la lista de citas 
 *      char * motivo: texto de la cita.
 *      int dia:       dia correspondiente
 *      int mes:       mes correspondiente
 *      int anyo:      año correspondiente
 *      int hora:      hora correspondiente
 *      int minuto:    minuto correspondiente
 *      
 * Parámetros de salida:
 *      Ninguno 
 *
 * Descripción: 
 *      Callback para insertarCitaWidget. inserta la cita en la lista global
 */
void introducirCitaWidget(void* citas, char *motivo,int dia, int mes, int anyo,
                          int hora, int minuto) 
{     
    Cita *cita;

    /*
     * insertar nueva cita
     */          
    cita=nuevaCita(motivo,dia,mes,anyo,hora,minuto,0);
    insertarListaCitas((ListaCitas *)citas,cita);
    actualizarCitasWidget();
    dialogoAviso("Cita insertada");
}

/*
 * Función borrarCitaWidget()
 *
 * Parámetros de entrada:
 *      void * citas:  puntero generico a la lista de citas 
 *      int dia:       dia correspondiente
 *      int mes:       mes correspondiente
 *      int anyo:      año correspondiente
 *      int hora:      hora correspondiente
 *      int minuto:    minuto correspondiente
 *      
 * Parámetros de salida:
 *      Ninguno 
 *
 * Descripción: 
 *      Callback para eliminarCitaWidget. Elimina la cita de la lista global
 */
void borrarCitaWidget (void *citas, int dia, int mes, int anyo,
                       int hora, int minuto)
{
    int num;
    int citaCumplida;
    int  diaCita,mesCita,anyoCita,horaCita,minutoCita,segundoCita;  
    char *motivo;
    Cita *cita;
    ListaCitas auxCitas =  *((ListaCitas *)(citas));

    
    /*
     * buscar cita
     */
    num=numeroListaCitas(auxCitas);
    if (0 == num) {
        return;
    }
    cita=primeraListaCitas(auxCitas);
    while  (NULL != cita) { 
        datosCita(*cita, &diaCita, &mesCita, &anyoCita,
                  &horaCita, &minutoCita, &segundoCita,
                  &citaCumplida, &motivo);
        if ( (dia != diaCita) || (mes != mesCita) || (anyo != anyoCita) || 
                            (hora != horaCita) || (minuto != minutoCita) ) {
            break;
        }
        auxCitas=restoListaCitas(auxCitas);
        cita=primeraListaCitas(auxCitas);
    };
  
    /*
     * si est'a, borrar
     */
    if (NULL != cita) {
        borrarListaCitas((ListaCitas *) citas,cita);
        actualizarCitasWidget();
        dialogoAviso("Cita eliminada");
    } else {
        dialogoAviso("Cita no existente");
    }
}

/*
 * Función insertarTablaCitasWidget()
 *
 * Parámetros de entrada:
 *      GtkWidget *tabla: tabla donde introducir el elemento
 *      GtkWidget *elemento: elemento a introducir en la tabla
 *      int fila: fila donde introducir el elemento
 *      int col: columna donde introducir el elemento
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      introduce el widget elemento en el widget tabla en la posición indicada
 */
void insertarTablaCitasWidget(GtkWidget *tabla, GtkWidget *elemento,
                              int fila, int col)
{
    gtk_table_attach(GTK_TABLE(tabla),elemento,col,col+1,fila,fila+1,0,0,0,0);
    gtk_widget_show(elemento); 
}

/*
 * Función incluirHoraCitasWidget()
 *
 * Parámetros de entrada:
 *      GtkWidget *tabla: tabla donde introducir el elemento
 *      char *hora: texto que indica la zona del dia de dicha fila
 *      int fila: fila donde introducir el elemento
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Incluye en la fila correspondiente de la tabla de citas el nombre de la
 *      zona del dia y un cuadro de texto.
 */
void incluirHoraCitasWidget(GtkWidget* tabla, char* hora,int fila)
{
    GtkWidget *h; 
    GtkWidget *t;
    GtkWidget *cita_scroll;

    /* Label creado con el texto pasado como parametro */
    h=gtk_label_new(hora);  

    insertarTablaCitasWidget(tabla,h,fila,0); 
    cita_scroll = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (cita_scroll),
                                    GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    /* 
     * Nueva variable de entrada de texto, sirve tanto para mostrar 
     * como para recibir datos 
     */                            
    t=gtk_text_new(NULL,NULL); 
    
    gtk_container_add(GTK_CONTAINER(cita_scroll), t);
    gtk_widget_set_usize (GTK_WIDGET (t), 200, 80);
    datosAgenda.gtk_citas[fila]=t;
    gtk_text_set_editable(GTK_TEXT(t),FALSE);  /* Se define como no editable */
    insertarTablaCitasWidget(tabla,cita_scroll,fila,1);
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función citasWidget()
 */
GtkWidget *citasWidget(void) 
{
    GtkWidget *citas;
  
    /* 
     * Se crea una nueva tabla de empaquetado de 13 filas y 2 columnas no 
     * homogenea en la que se almacenaran la hora y texto de las citas 
     */  
    citas=gtk_table_new(4,2,FALSE);      

    /* 
     * Se llama al procedimiento que incluye la opcion de mostrar el texto 
     * y la hora de la cita para cada una de las horas indicadas 
     */
    incluirHoraCitasWidget(citas,"Madrugada",0);
    incluirHoraCitasWidget(citas,"Mañana",1);
    incluirHoraCitasWidget(citas,"Tarde",2);
    incluirHoraCitasWidget(citas,"Noche",3); 

    return(citas);
}


/*
 * Función insertarCitasWidget()
 */
void insertarCitasWidget (void)
{
    /*
     * leer valores
     */
    dialogoCita("Cita","Introduzca la fecha y motivo de la cita:\n",
                introducirCitaWidget,(&datosAgenda.citas));
}

/*
 * Función eliminarCitasWidget()
 */
void eliminarCitasWidget(void) 
{          
    /*
     * eliminar una cita existente
     */              
    dialogoFecha("Cita","Introduzca la fecha de la cita:\n",borrarCitaWidget,
                 (&datosAgenda.citas));
}

/*
 * Función actualizarCitasWidget()
 */
void actualizarCitasWidget(void)
{
    ListaCitas citas = datosAgenda.citas;
    gint diaCalendar,mesCalendar,anyoCalendar;  
    int  diaCita,mesCita,anyoCita,horaCita,minutoCita,segundoCita;  
    Cita *citaAux;
    int citaCumplida;
    char* motivo;
    int i,totalCitas;
    int longTxt;  
    char textoHora[256], cumplida[256];
    GdkColor colorRojo,colorNegro;  
  
    /* 
     * Inicializacion de las cajas de texto destinadas a la visalizacion de las 
     * citas
     */
    for (i=0;i<4;i++) { 
        longTxt=gtk_text_get_length(GTK_TEXT(datosAgenda.gtk_citas[i]));
        gtk_text_set_point(GTK_TEXT(datosAgenda.gtk_citas[i]),0);
        gtk_text_forward_delete(GTK_TEXT(datosAgenda.gtk_citas[i]),
                                longTxt);     
    }
    /* cargando los colores para el texto */
    gdk_color_parse("Black", &colorNegro);
    gdk_color_parse("Red", &colorRojo);

    /* Capturamos el dia seleccionado en el calendario */
    gtk_calendar_get_date(GTK_CALENDAR(datosAgenda.gtk_calendario),
                          &anyoCalendar, &mesCalendar, &diaCalendar);
    mesCalendar=mesCalendar + 1;
    totalCitas=numeroListaCitas(citas);
    /* 
     * Para cada cita existente en la lista comprobamos si pertenece al dia 
     * indicado. Si es asi comprobamos a que hora corresponde dicha cita
     */
    for (i=0;i<totalCitas;i++) {
        /* Extraer la cita y sus datos */
        citaAux=primeraListaCitas(citas);   
        datosCita(*citaAux, &diaCita, &mesCita, &anyoCita,
                  &horaCita, &minutoCita, &segundoCita,
                  &citaCumplida, &motivo);

        /* Si el dia coincide, mostrarla */          
        if ( (diaCalendar == diaCita) && (mesCalendar == mesCita) && 
                                         (anyoCalendar == anyoCita) ) {   
            sprintf(textoHora,"%02d:%02d ",horaCita,minutoCita);
            if (1 == citaAux->cumplida) {
                strcpy(cumplida,"X ");
            } else {
                strcpy(cumplida,"   ");
            } 
            if ((0 <= horaCita) && (6 > horaCita)) {     
                /* de 0 a 6 */      
                longTxt=gtk_text_get_length(GTK_TEXT(datosAgenda.gtk_citas[0]));
                gtk_text_set_point(GTK_TEXT(datosAgenda.gtk_citas[0]),longTxt);
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[0]),NULL,
                                &colorNegro,NULL,textoHora,strlen(textoHora));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[0]),NULL,
                                &colorRojo,NULL,cumplida,strlen(cumplida));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[0]),NULL,
                                &colorNegro,NULL,motivo,strlen(motivo));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[0]),NULL,
                                &colorNegro,NULL,"\n",1);         

            } else if ((6 <= horaCita) && (12 > horaCita)) {
                /* de 6 a 12 */
                longTxt=gtk_text_get_length(GTK_TEXT(datosAgenda.gtk_citas[1]));
                gtk_text_set_point(GTK_TEXT(datosAgenda.gtk_citas[1]),longTxt);
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[1]),NULL,
                                &colorNegro,NULL,textoHora,strlen(textoHora));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[1]),NULL,
                                &colorRojo,NULL,cumplida,strlen(cumplida));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[1]),NULL,
                                &colorNegro,NULL,motivo,strlen(motivo)); 
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[1]),NULL,
                                &colorNegro,NULL,"\n",1);         
         
            } else if ((12 <= horaCita) && (19 > horaCita)) {
                /* de 12 a 19 */
                longTxt=gtk_text_get_length(GTK_TEXT(datosAgenda.gtk_citas[2]));
                gtk_text_set_point(GTK_TEXT(datosAgenda.gtk_citas[2]),longTxt);
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[2]),NULL,
                                &colorNegro,NULL,textoHora,strlen(textoHora));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[2]),NULL,
                                &colorRojo,NULL,cumplida,strlen(cumplida));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[2]),NULL,
                                &colorNegro,NULL,motivo,strlen(motivo));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[2]),NULL,
                                &colorNegro,NULL,"\n",1);         
   
            } else {
                /* de 19 a 0 */
                longTxt=gtk_text_get_length(GTK_TEXT(datosAgenda.gtk_citas[3]));
                gtk_text_set_point(GTK_TEXT(datosAgenda.gtk_citas[3]),longTxt);
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[3]),NULL,
                                &colorNegro,NULL,textoHora,strlen(textoHora));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[3]),NULL,
                                &colorRojo,NULL,cumplida,strlen(cumplida));     
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[3]),NULL,
                                &colorNegro,NULL,motivo,strlen(motivo));
                gtk_text_insert (GTK_TEXT(datosAgenda.gtk_citas[3]),NULL,
                                &colorNegro,NULL,"\n",1);         
        
            }
        }          
        citas=restoListaCitas(citas);
    }
}

/*
 * Función avisarCitaWidget()
 */
void avisarCitaWidget(void)
{
    char texto[2000];

    actualizarCitasWidget();
    sprintf(texto," ______________________________________________________\n");
    strcat (texto,"                                                       \n");
    strcat (texto,"               Tiene una cita pendiente.               \n");
    strcat (texto,"                  Consulte su agenda.                  \n");
    strcat (texto," ______________________________________________________\n");

    dialogoAviso(texto);
}
