/* 
 * Programa:    prog14_03
 * Fichero:     prog14_03.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              Programa principal y funciones de apoyo e integración 
 *              para las citas.
 */


#include "menugtk.c"

/* Procedimiento que inserta un elemento en una tabla, en la fila y columna
   indicada. Se supone que cada elemento solo ocupará 1 celda de la tabla */
void insertarTabla(GtkWidget *tabla, GtkWidget *elemento,int fila, int col)
{
  gtk_table_attach(GTK_TABLE(tabla),elemento,col,col+1,fila,fila+1,0,0,0,0);
  gtk_widget_show(elemento); 
}

void incluirHoraCita(GtkWidget* tabla, char* hora,int fila)
{
  GtkWidget *h; 
  GtkWidget *t;

  h=gtk_label_new(hora);  /* Label creado con el texto pasado como parametro */
  insertarTabla(tabla,h,fila,0); 
  t=gtk_entry_new(); /* Nueva variable de entrada de texto, sirve tanto para
			mostrar como para recibir datos */
  gtk_entry_set_editable(GTK_ENTRY(t),FALSE);  /* Se define como no editable */
  insertarTabla(tabla,t,fila,1);
}
int main(int argc, char *argv[])
{
  GtkWidget *ventana = NULL;
  GtkWidget *calendario;
  GtkWidget *menu;
  GtkWidget *citas;   
  GtkWidget *global;  
  GtkWidget *cuerpo;

  /* Inicialización de gtk y trato de parámetros de comando*/
  gtk_init (&argc,&argv);
  
  /* Crear ventana principal de la aplicacion*/
  ventana=gtk_window_new (GTK_WINDOW_TOPLEVEL);
  
  /* Definir el tamaño */
  gtk_widget_set_usize(ventana,600,400);
  
  /* Se asocian las funciones a los eventos. En este caso se cubren los
     eventos de destrucción y cierre de la ventana principal */
  gtk_signal_connect (GTK_OBJECT (ventana), "destroy", GTK_SIGNAL_FUNC(gtk_widget_destroyed),&ventana); 
  gtk_signal_connect (GTK_OBJECT (ventana), "delete_event", GTK_SIGNAL_FUNC(salir), NULL);
  
  /* Titulo de la ventana */
  gtk_window_set_title (GTK_WINDOW (ventana), "Ventana de citas"); 
  
  /* Borde de la ventana */
  gtk_container_border_width(GTK_CONTAINER(ventana),2);
 
  menu=crearMenu(ventana);

  /* Se crea una nueva tabla de empaquetado de 2 filas y 2 columnas no 
     homogenea */
  global=gtk_table_new(2,2,FALSE);

 /* Se crea una nueva caja horizontal de empaquetado no 
    homogenea en la que se almacenara el cuerpo de la ventana*/
  cuerpo=gtk_hbox_new(FALSE,1);  

  /* Se crea una nueva tabla de empaquetado de 13 filas y 2 columnas no 
     homogenea en la que se almacenaran la hora y texto de las citas */  
  citas=gtk_table_new(13,2,FALSE);      

  /* Se llama al procedimiento que incluye la opcion de mostrar el texto y la 
     hora de la cita para cada una de las horas indicadas */
  incluirHoraCita(citas,"9:00",0);
  incluirHoraCita(citas,"10:00",1);
  incluirHoraCita(citas,"11:00",2);
  incluirHoraCita(citas,"12:00",3);
  incluirHoraCita(citas,"13:00",4);
  incluirHoraCita(citas,"14:00",5);
  incluirHoraCita(citas,"15:00",6);
  incluirHoraCita(citas,"16:00",7);
  incluirHoraCita(citas,"17:00",8);
  incluirHoraCita(citas,"18:00",9);
  incluirHoraCita(citas,"19:00",10);
  incluirHoraCita(citas,"20:00",11);
  incluirHoraCita(citas,"21:00",12); 

  /* Se crea un nuevo calendario */
  calendario=gtk_calendar_new();
    
  /* Se almacena la variable de calendario en la caja de almacenamiento cuerpo
   */
  gtk_box_pack_start(GTK_BOX(cuerpo),calendario,FALSE,FALSE,25);
  gtk_widget_show(calendario);
  /* Se almacena la caja de almacenamiento de las cias previamente creada en la
     caja de almacenamiento cuerpo */
  gtk_box_pack_start(GTK_BOX(cuerpo),citas,FALSE,FALSE,10);
  gtk_widget_show(citas);
  
  /* En la tabla de almacenamiento se guarda en la primera fila, el menu 
     devuelto al llamar a la funcion crearmenu */
  gtk_table_attach(GTK_TABLE(global),menu,0,2,0,1,GTK_FILL|GTK_EXPAND,GTK_FILL,0,0);
  gtk_widget_show(menu); 
  
  /* Se inserta en la tabla de almacenamiento global, el cuerpo de la pantalla
     (fila 1) */
  insertarTabla(global,cuerpo,1,0);
  
  /* El contenedor de la ventana principal almacena ahora la tabla global */
  gtk_container_add(GTK_CONTAINER(ventana),global);  
  
  /* Se muestra todo dentro de la ventana*/
  gtk_widget_show_all(ventana); 

  gtk_main();
  
  /* Salimos devolviendo código de estado */
  return(0);
}

