/*
 * Programa: agenda
 * Modulo  : menu_agenda
 * Fichero : menu_agenda_menus.h
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_agenda_menus.h"

/*
 * PROTOTIPOS DE FUNCIONES PRIVADAS
 */

/* 
 * Función: salir()
 */ 
static void salir();

/*
 * VARIABLES GLOBALES LOCALES AL MODULO
 */

/* 
 * Variable que crea un menu a partir de una coleccion de elementos. 
 * Hay dos formas de definir menus, una es esta, que es simple, pero poco 
 * flexible, de hay que sea util solo en casos de menus globales a toda la 
 * aplicacion. La otra forma es definir manualmente todos los elementos del 
 * menu (ramas, subramas, hojas... ), que si bien permite adaptarse mejor a 
 * variaciones, presenta una mayor complejidad y dificultad de realizacion 
 */
static GtkItemFactoryEntry elementosmenu[]={
/* 
 * Cada elemento consta, por este orden, de la ruta, tecla aceleradora, 
 * funcion de retrollamada al activarse la opcion, parametro para la 
 * retrollamada y un indicador, que puede ser (titulo, elemento, elemento 
 * marcado, elemento conmutador, opcion de menu, separador, subrama o ultima 
 * rama ) 
 */
    {"/_Archivo",NULL,0,0,"<Branch>"},
    {"/Archivo/sep11",NULL,NULL,0,"<Separator>"},
    {"/Archivo/_Salir","<control>Q",salir,0},
    {"/Libro _Direcciones",NULL,0,0,"<Branch>"},
    {"/Libro Direcciones/_Insertar Direccion",NULL,
                            GTK_SIGNAL_FUNC(insertarDireccionDialogo),0,0},
    {"/Libro Direcciones/_Eliminar Direccion",NULL,
                            GTK_SIGNAL_FUNC(borrarDireccionDialogo),0,0},
    {"/Libro Direcciones/sep21",NULL,NULL,0,"<Separator>"},
    {"/Libro Direcciones/Consultar _Nombre",NULL,
                            GTK_SIGNAL_FUNC(consultarNombreDialogo),0,0},
    {"/Libro Direcciones/sep22",NULL,NULL,0,"<Separator>"},
    {"/Libro Direcciones/_Visualizar Libro",NULL,
                            GTK_SIGNAL_FUNC(listarDireccionWindow),0,0},
    {"/_Notas Diarias",NULL,0,0,"<Branch>"}, 
    {"/Notas Diarias/_Insertar Nota",NULL,
                            GTK_SIGNAL_FUNC(insertarNotasWidget),0,0},
    {"/Notas Diarias/_Eliminar Nota",NULL,
                            GTK_SIGNAL_FUNC(borrarNotasWidget),0,0},
    {"/Notas Diarias/sep32",NULL,NULL,0,"<Separator>"},
    {"/Notas Diarias/_Actualizar Notas",NULL,
                            GTK_SIGNAL_FUNC(listarNotasWidget),0,0},
    {"/_Calendario",NULL,0,0,"<Branch>"},
    {"/Calendario/_Ocultar Calendario",NULL,
                            GTK_SIGNAL_FUNC(ocultarCalendarioWidget),0,0},
    {"/Calendario/_Visualizar Calendario",NULL,
                            GTK_SIGNAL_FUNC(mostrarCalendarioWidget),0,0},
    {"/Calendario/sep41",NULL,NULL,0,"<Separator>"},
    {"/Calendario/Mes _Anterior",NULL,
                            GTK_SIGNAL_FUNC(mesAnteriorCalendarioWidget),0,0},
    {"/Calendario/Mes _Siguiente",NULL,
                            GTK_SIGNAL_FUNC(mesSiguienteCalendarioWidget),0,0},
    {"/Calendario/sep42",NULL,NULL,0,"<Separator>"},
    {"/Calendario/Año A_nterior",NULL,
                            GTK_SIGNAL_FUNC(anyoAnteriorCalendarioWidget),0,0},
    {"/Calendario/Año S_iguiente",NULL,
                            GTK_SIGNAL_FUNC(anyoSiguienteCalendarioWidget),0,0},
    {"/Ci_tas",NULL,0,0,"<Branch>"},
    {"/Citas/_Visualizar Citas",NULL,
                            GTK_SIGNAL_FUNC(actualizarCitasWidget),0,0},
    {"/Citas/sep51",NULL,NULL,0,"<Separator>"},
    {"/Citas/_Insertar Cita",NULL,GTK_SIGNAL_FUNC(insertarCitasWidget),0,0},
    {"/Citas/_Eliminar Cita",NULL,GTK_SIGNAL_FUNC(eliminarCitasWidget),0,0}
};
  
/* variable que devuelve el numero de elementos del menu */
static int numelementosmenu = sizeof(elementosmenu)/sizeof(elementosmenu[0]);

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Función salir()
 *  
 * Parámetros de entrada:
 *      Ninguno 
 *      
 * Parámetros de salida:
 *      Ninguno 
 *
 * Descripción: 
 *      Manejador de evento . Finaliza el bucle gtk_main()
 */
static void salir()
{
    g_message("Salimos del programa");
    gtk_main_quit();
}


/*
 * FUNCIONES PÚBLICAS
 */

/* 
 * Función crearMenu
 */
GtkWidget* crearMenu(GtkWidget *window)
{
    GtkWidget *caja;
    GtkAccelGroup *atajos; /* Conjunto de las teclas de aceleracion */
    GtkItemFactory *elementos; /* Coleccion o factoria de elementos que forman 
                                  el menu */

    /* Se crea un nuevo grupo de teclas de aceleracion */
    atajos=gtk_accel_group_new(); 

    /* Se crea una nueva coleccion o factoria de elementos */
    elementos=gtk_item_factory_new(GTK_TYPE_MENU_BAR,"<blah>",atajos);

    /* Se crean los elementos de la factoria o coleccion */
    gtk_item_factory_create_items(elementos,numelementosmenu,
                                  elementosmenu,NULL);
    /* 
     * Se asocia el grupo de teclas de aceleracion a la ventana principal 
     * de la aplicacion 
     */
    gtk_accel_group_attach(atajos,GTK_OBJECT(window));
  
    /* 
     * Se crea una nueva caja de empaquetado vertical, no homogenea con una 
     * separacion entre elementos de 30 
     */
    caja=gtk_vbox_new(FALSE,30);
  
    /* Se añade el menu a la caja de empaquetado */  
    gtk_box_pack_start(GTK_BOX(caja),
                       gtk_item_factory_get_widget(elementos,"<blah>"),
                       FALSE,FALSE,0);
    return(caja);
}


