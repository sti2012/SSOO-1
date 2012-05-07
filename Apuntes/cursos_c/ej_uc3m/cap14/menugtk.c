/* 
 * Programa:    prog14_03, prog14_04
 * Fichero:     menugtk.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              Modulo que crea los menus de la agenda
 */

#include <gtk/gtk.h>

gint eliminarventana(GtkWidget *widget, gpointer gdata);
static GtkWidget* crearMenu(GtkWidget *window);

/* Funcion que permite salir de gtk */
static void salir()
{
  g_message("Salimos del programa");
  gtk_main_quit();
}


/* Funcion que crea un menu a partir de una coleccion de elementos. 
Hay dos formas de definir menus, una es esta, que es simple, pero poco flexible
, de hay que sea util solo en casos de menus globales a toda la aplicacion. La
 otra forma es definir manualmente todos los elementos del menu (ramas, 
subramas, hojas... ), que si bien permite adaptarse mejor a variaciones, 
presenta una mayor complejidad y dificultad de realizacion */
static GtkItemFactoryEntry elementosmenu[]={

/* Cada elemento consta, por este orden, de la ruta, tecla aceleradora, funcion
de retrollamada al activarse la opcion, parametro para la retrollamada y un 
indicador, que puede ser (titulo, elemento, elemento marcado, elemento 
conmutador, opcion de menu, separador, subrama o ultima rama ) */
  {"/_Archivo",NULL,0,0,"<Branch>"},
  {"/Archivo/sep1",NULL,NULL,0,"<Separator>"},
  {"/Archivo/_Salir","<control>Q",salir,0},
  {"/_Usuarios",NULL,0,0,"<Branch>"},
  {"/Usuarios/_Entrar",NULL,0,0,0},
  {"/Usuarios/_Crear Usuario",NULL,0,0,0},
  {"/Usuarios/_Borrar Usuario",NULL,0,0,0},
  {"/_Listin Telefonico",NULL,0,0,"<Branch>"},
  {"/Listin Telefonico/_Insertar Telefono",NULL,0,0,0},
  {"/Listin Telefonico/_Eliminar Telefono",NULL,0,0,0},
  {"/Listin Telefonico/_Modificar Telefono",NULL,0,0,0},
  {"/Listin Telefonico/sep2",NULL,NULL,0,"<Separator>"},
  {"/Listin Telefonico/_Consultar Telefono",NULL,0,0,0},
  {"/Listin Telefonico/Consultar _Nombre",NULL,0,0,0},
  {"/Listin Telefonico/sep3",NULL,NULL,0,"<Separator>"},
  {"/Listin Telefonico/_Visualizar Listin",NULL,0,0,0},
  {"/_Notas Diarias",NULL,0,0,"<Branch>"},
  {"/Notas Diarias/_Insertar Nota",NULL,0,0,0},
  {"/Notas Diarias/_Eliminar Nota",NULL,0,0,0},
  {"/Notas Diarias/_Modificar Nota",NULL,0,0,0},
  {"/Notas Diarias/sep4",NULL,NULL,0,"<Separator>"},
  {"/Notas Diarias/_Visualizar Notas",NULL,0,0,0},
  {"/Notas Diarias/sep5",NULL,NULL,0,"<Separator>"},
  {"/Notas Diarias/Nota _Anterior",NULL,0,0,0},
  {"/Notas Diarias/Nota _Siguiente",NULL,0,0,0},
  {"/Notas Diarias/_Primera Nota",NULL,0,0,0},
  {"/Notas Diarias/_Ultima Nota",NULL,0,0,0},
  {"/Notas Diarias/sep6",NULL,NULL,0,"<Separator>"},
  {"/Notas Diarias/Imp_rimir Nota",NULL,0,0,0},
  {"/_Calendario",NULL,0,0,"<Branch>"},
  {"/Calendario/_Recuperar Calendario",NULL,0,0,0},
  {"/Calendario/_Visualizar Calendario",NULL,0,0,0},
  {"/Calendario/Mes _Anterior",NULL,0,0,0},
  {"/Calendario/Mes _Siguiente",NULL,0,0,0},
  {"/Calendario/sep7",NULL,NULL,0,"<Separator>"},
  {"/Calendario/_Calcular Dia",NULL,0,0,0},
  {"/Libro _Direcciones",NULL,0,0,"<Branch>"},
  {"/Libro Direcciones/_Insertar Direccion",NULL,0,0,0},
  {"/Libro Direcciones/_Eliminar Direccion",NULL,0,0,0},
  {"/Libro Direcciones/_Modificar Direccion",NULL,0,0,0},
  {"/Libro Direcciones/sep8",NULL,NULL,0,"<Separator>"},
  {"/Libro Direcciones/_Consultar Direccion",NULL,0,0,0},
  {"/Libro Direcciones/Consultar _Nombre",NULL,0,0,0},
  {"/Libro Direcciones/sep9",NULL,NULL,0,"<Separator>"},
  {"/Libro Direcciones/_Enviar Mail",NULL,0,0,0},
  {"/Libro Direcciones/sep10",NULL,NULL,0,"<Separator>"},
  {"/Libro Direcciones/_Visualizar Libro",NULL,0,0,0},
  {"/Ci_tas",NULL,0,0,"<Branch>"},
  {"/Citas/_Insertar Cita",NULL,0,0,0},
  {"/Citas/_Eliminar Cita",NULL,0,0,0},
  {"/Citas/_Modificar Cita",NULL,0,0,0},
  {"/Citas/sep11",NULL,NULL,0,"<Separator>"},
  {"/Citas/_Consultar Cita",NULL,0,0,0},
  {"/Citas/_Avisar",NULL,0,0,0},
  {"/Citas/sep12",NULL,NULL,0,"<Separator>"},
  {"/Citas/_Visualizar Citas",NULL,0,0,0},
};

static int numelementosmenu = sizeof(elementosmenu)/sizeof(elementosmenu[0]);
/* Funcion que devuelve el numero de elementos del menu */


/* Funcion que devuelve el menu creado */
static GtkWidget* crearMenu(GtkWidget *window)
{
  GtkWidget *caja;
  GtkAccelGroup *atajos; /* Conjunto de las teclas de aceleracion */
  GtkItemFactory *elementos; /* Coleccion o factoria de elementos quw forman el
				menu */

  /* Se crea un nuevo grupo de teclas de aceleracion */
  atajos=gtk_accel_group_new(); 

  /* Se crea una nueva coleccion o factoria de elementos */
  elementos=gtk_item_factory_new(GTK_TYPE_MENU_BAR,"<blah>",atajos);

  /* Se crean los elementos de la factoria o coleccion */
  gtk_item_factory_create_items(elementos,numelementosmenu,elementosmenu,NULL);

  /* Se asocia el grupo de teclas de aceleracion a la ventana principal de la
     aplicacion */
  gtk_accel_group_attach(atajos,GTK_OBJECT(window));
  
  /* Se crea una nueva caja de empaquetado vertical, no homogenea con una 
     separacion entre elementos de 30 */
  caja=gtk_vbox_new(FALSE,30);
  
  /* Se añade el menu a la caja de empaquetado */  
  gtk_box_pack_start(GTK_BOX(caja),gtk_item_factory_get_widget(elementos,"<blah>"),FALSE,FALSE,0);
   return(caja);
}


