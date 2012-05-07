/*
 * Programa: agenda
 * Modulo  : menu_notas
 * Fichero : menu_notas.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_notas.h"

/*
 * FUNCIONES PRIVADAS
 */


/*
 * Función introducirIndice()
 *
 * Parámetros de entrada:
 *      void * data:  puntero generico 
 *      char * valor: texto que indica el indice
 *      
 * Parámetros de salida:
 *      Ninguno 
 *
 * Descripción: 
 *      Callback para borrarNotasWidget. borra la nota de la lista global
 */
void introducirIndice ( void *data, char *valor )
{
    int indice,error;

    if ('\0' == valor[0]) {
        dialogoAviso("Debe introducir un indice");
        return;
     }
    indice=atoi(valor);
    error=borrarNotas(&(datosAgenda.notas),indice);
    if (0 == error) {
        listarNotasWidget();
        dialogoAviso("Nota eliminada");
    } else {
        dialogoAviso("No se pudo eliminar la nota");
    }
}

/*
 * Función introducirNota()
 *
 * Parámetros de entrada:
 *      void * data:  puntero generico 
 *      char * valor: texto que indica el texto de la nota
 *      
 * Parámetros de salida:
 *      Ninguno 
 *
 * Descripción: 
 *      Callback para insertarNotasWidget. inserta la nota en la lista global
 */
void introducirNota ( void *data, char *valor )
{
    int retorno;
    if ('\0' == valor[0]) {
        dialogoAviso("Debe introducir una nota");
        return;
    }
 
    retorno=insertarNotas(&(datosAgenda.notas),valor);
    if (0 == retorno) {
        listarNotasWidget();
        dialogoAviso("Nota insertada");
    } else {
        dialogoAviso("No se pudo insertar la nota");
    }
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función insertarNotasWidget()
 */
void insertarNotasWidget (void)
{
    dialogoDatos ("Nota",
                  "Introduzca la nota a insertar",
                  introducirNota,&(datosAgenda.notas));
}

/*
 * Función borrarNotasWidget()
 */
void borrarNotasWidget (void)
{
    dialogoDatos ("Nota",
                  "Introduzca el indice de la nota a borrar",
                  introducirIndice,&(datosAgenda.notas));       
}

/*
 * Función destruirNotasWidget()
 */
void destruirNotasWidget (void)
{
    destruirNotas(&(datosAgenda.notas));
    gtk_exit(0);
}

/*
 * Función listarNotasWidget()
 */
void listarNotasWidget (void)
{
    int i, num;
    gchar *linea[2];
    char   posicion[32];

    /*
     * Lista vacía
     */
    num=numeroNotas(&(datosAgenda.notas));
    if (0 == num) {
        gtk_clist_clear( (GtkCList *) datosAgenda.gtk_notas);
        return;
    }

    /*
     * Imprimir lista 
     */
    gtk_clist_clear( (GtkCList *) datosAgenda.gtk_notas);
    for (i=1; i<=num; i++) {     
            sprintf(posicion,"%d",i);
        linea[0]=posicion;
        linea[1]=consultarNotas(&(datosAgenda.notas),i);
        gtk_clist_append( (GtkCList *) datosAgenda.gtk_notas, 
                         linea);
    }
}

/*
 * Función notasWidget()
 */
GtkWidget *notasWidget(void) 
{
    GtkWidget *scroll;
    GtkWidget *notas;
    gchar     *notas_titulo[2] = {"índice", "contenido"};

    /* 
     * Se crea los componentes asociados a notas:
     * una ventana con barra de desplazamiento y una lista 
     */
    scroll = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll),
                                    GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    gtk_widget_set_usize(scroll,150,200);
    
    notas=gtk_clist_new_with_titles (2,notas_titulo);
    datosAgenda.gtk_notas=notas;
    gtk_clist_set_shadow_type (GTK_CLIST(notas), GTK_SHADOW_OUT);
    gtk_container_add(GTK_CONTAINER(scroll), notas);

    return (scroll);
}

