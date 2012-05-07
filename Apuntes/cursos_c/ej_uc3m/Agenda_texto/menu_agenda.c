/*
 * Programa: agenda
 * Modulo  : menu_agenda
 * Fichero : menu_agenda.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_agenda.h"

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función menuAgenda()
 */
void  menuAgenda (ListaNotas *notas, ListaCitas *citas, ListaDir *datos)
{
    int opcion;
    int final = 0;

    do {

        /* Mostrar el menu de opciones */
        opcion = -1;
        printf("\n");
        printf("\n");
        printf("Menu de la Agenda\n");
        printf("-----------------\n");
        printf("\n");
        printf(" 1.- Ver libro de direcciones\n");
        printf(" 2.- Ver notas diarias\n");
        printf(" 3.- Ver calendario\n");
        printf(" 4.- Ver citas y reuniones\n");
        printf(" 0.- Salir del programa\n\n");  
        printf("\n");
        printf("\n");
        printf(" Introduzca su opción: ");
        scanf ("%i",&opcion);

        switch(opcion){
        case 1:
            /* aqui iria la gestión del libro de direcciones */
            menuDir(datos);
        break;
        case 2:
            menuNotas(notas);
            /* aqui iria la gestión de las notas */
        break;
        case 3:
            /* aqui va el calendario */
            menuCalendario();
        break;
        case 4:     
            /* aqui iria la gestión del las citas y reuniones */
            menuCitas(citas);
        break;
        case 0:                 
            /* Salir del menu */
            final=1;       
        break;
        default:
            /* la opción elegida no esta dentro de las indicadas */
            printf("La opcion elegida es incorrecta\n\n");
        }  
   }while (0 == final);  
}

