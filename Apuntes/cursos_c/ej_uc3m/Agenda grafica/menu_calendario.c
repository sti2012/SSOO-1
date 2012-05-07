/*
 * Programa: agenda
 * Modulo  : menu_calendario
 * Fichero : menu_calendario.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_calendario.h"

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función calendarioWidget
 */
GtkWidget *calendarioWidget(void) 
{
    GtkWidget *calendario;
    TipoFecha fechaHoy;

    /* Se crea un nuevo calendario */
    calendario=gtk_calendar_new();  

    /* Se asigna la fecha del dia actual */

    fechaHoy=obtenerFechaActual();   
    gtk_calendar_select_month(GTK_CALENDAR(calendario),fechaHoy.mes-1,
                              fechaHoy.anyo);
    gtk_calendar_select_day(GTK_CALENDAR(calendario),fechaHoy.dia);

    /* 
     * Controlamos todas las señales asociadas con el calendario, ya que nos
     * interesa visualizar las citas pertenecientes al dia seleccionado en dicho
     * calendario
     */
    gtk_signal_connect (GTK_OBJECT (calendario), "month_changed", 
                        GTK_SIGNAL_FUNC (actualizarCitasWidget),
                        NULL);
    gtk_signal_connect (GTK_OBJECT (calendario), "day_selected", 
                        GTK_SIGNAL_FUNC (actualizarCitasWidget),
                        NULL);
    gtk_signal_connect (GTK_OBJECT (calendario), "day_selected_double_click", 
                        GTK_SIGNAL_FUNC (actualizarCitasWidget),
                        NULL);
    gtk_signal_connect (GTK_OBJECT (calendario), "prev_month", 
                        GTK_SIGNAL_FUNC (actualizarCitasWidget),
                        NULL);
    gtk_signal_connect (GTK_OBJECT (calendario), "next_month", 
                        GTK_SIGNAL_FUNC (actualizarCitasWidget),
                        NULL);
    gtk_signal_connect (GTK_OBJECT (calendario), "prev_year", 
                        GTK_SIGNAL_FUNC (actualizarCitasWidget),
                        NULL);
    gtk_signal_connect (GTK_OBJECT (calendario), "next_year", 
                        GTK_SIGNAL_FUNC (actualizarCitasWidget),
                        NULL);
         
    datosAgenda.gtk_calendario=calendario;

  return (calendario);

}

/*
 * Función mostrarCalendarioWidget
 */
void mostrarCalendarioWidget(void)
{
    gtk_widget_show(datosAgenda.gtk_calendario);
}

/*
 * Función ocultarCalendarioWidget
 */
void ocultarCalendarioWidget (void)
{
    gtk_widget_hide(datosAgenda.gtk_calendario);
}

/*
 * Función mesAnteriorCalendarioWidget
 */
void mesAnteriorCalendarioWidget (void)
{
    int mes, anyo, dia;
    
    gtk_calendar_get_date(GTK_CALENDAR(datosAgenda.gtk_calendario),
                          &anyo,&mes,&dia);
    gtk_calendar_select_month(GTK_CALENDAR(datosAgenda.gtk_calendario),
                              mes-1,anyo);
}

/*
 * Función mesSiguienteCalendarioWidget
 */
void mesSiguienteCalendarioWidget (void)
{
    int mes, anyo, dia;
    
    gtk_calendar_get_date(GTK_CALENDAR(datosAgenda.gtk_calendario),
                          &anyo,&mes,&dia);
    gtk_calendar_select_month(GTK_CALENDAR(datosAgenda.gtk_calendario),
                              mes+1,anyo);
}

/*
 * Función anyoAnteriorCalendarioWidget
 */
void anyoAnteriorCalendarioWidget (void)
{
    int mes, anyo, dia;
    
    gtk_calendar_get_date(GTK_CALENDAR(datosAgenda.gtk_calendario),
                          &anyo,&mes,&dia);
    gtk_calendar_select_month(GTK_CALENDAR(datosAgenda.gtk_calendario),
                              mes,anyo-1);
}

/*
 * Función anyoSiguienteCalendarioWidget 
 */
void anyoSiguienteCalendarioWidget (void)
{
    int mes, anyo, dia;
    
    gtk_calendar_get_date(GTK_CALENDAR(datosAgenda.gtk_calendario),
                          &anyo,&mes,&dia);
    gtk_calendar_select_month(GTK_CALENDAR(datosAgenda.gtk_calendario),
                              mes,anyo+1);
}

