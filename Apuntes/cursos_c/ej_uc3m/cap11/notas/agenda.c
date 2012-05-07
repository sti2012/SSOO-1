/*
 * Programa:    notas
 * Fichero:     agenda.c
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              Implementación del módulo notas utilizando 
 *              una estructura autoreferenciada
 */

#include <stdio.h>
#include <stdlib.h>
#include "notas.h"


int  main (void)
{
        ListaNotas l;
        char nota[1024];
        int posicion;
        int opcion;
        int final = 0;


        iniciarListaNotas(&l);
        do {         

            /* Mostrar el menu de opciones */
            printf("\n");
            printf("Notas\n");
            printf("-----\n");
            printf("\n");
            printf(" 1.- Listar las notas\n");
            printf(" 2.- Insertar una nota\n");
            printf(" 3.- Borrar una nota\n");
            printf(" 0.- Salir\n");
            printf("\n");
            printf("\n");
            printf(" Introduzca su opción: ");
    	    fflush(stdout);
            scanf ("%d",&opcion);
    
            switch(opcion){
    	    case 1:
                    /* Listar las notas */
                    printf("\n");
                    printf("... Notas .......................................\n");
                    mostrarNotas(&l);
                    printf(".................................................\n");
        	    break;
    	    case 2: 
                    /* Insertar una nota */
                    printf("Introduzca el contenido de la nota:\n");
                    fflush(stdout);
                    do {
                            fgets(nota,NOTA_MAX,stdin);
                    } while ( (!strcmp(nota,"\n")) || (!strcmp(nota,"")) ) ;

                    insertarNota(&l, nota);
    	            break;
    	    case 3:
                    /* Borrar una nota */
                    printf("Introduzca la posición de la nota a borrar: ");
                    fflush(stdout);
                    scanf("%d",&posicion);

                    borrarNota(&l,posicion);
                    break;
    	    case 0:
                    /* Salir del menu */
                    final=1;
                    break;
    	    default:
                    /* la opción elegida no esta dentro de las indicadas */
    	            printf("La opcion elegida es incorrecta\n\n");
            }  
       } while (0 == final);  

       destruirListaNotas(&l);
       return (0);
}

