/*
 * Programa:    prog_07_10
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
 *              Menu principal de la agenda electronica
 */

#include <stdio.h>

/*
 * Se incluyen los archivos de cabecera de los módulos
 * que utiliza agenda.
 */

/*
#include "agendausuario.h"
#include "calendario.h"
#include "citas.h"
#include "notas.h"
#include "librodirecciones.h
*/

void entrar(void)
{
    int opcion;
    int salir = 0;
    int leidos = 0;
    
    do{    
        /* Mostrar el menú de opciones */
        printf("\n\nMenú de la Agenda:\n");
        printf("1.- Ver libro de direcciones\n");
        printf("2.- Ver notas diarias\n");
        printf("3.- Ver calendario\n");
        printf("4.- Ver citas y reuniones\n");
        printf("0.- Salir del programa\n\n");  
        printf ("Introduzca su opción: ");

        leidos = 0;
        while (leidos == 0) {
            leidos = scanf ("%i",&opcion);
            if (leidos == 0)
                printf("Opción incorrecta\n");
        }

        switch(opcion){
            case 1:
                /* aquí irá la gestión de libro de direcciones */
                   break;
            case 2:
                /* aquí irá la gestión de las notas */
                  break;
            case 3:
                /* aquí ira el calendario */
                    break;
            case 4:      
                /* aquí irá la gestión del las citas y reuniones */
                  break;
            case 0:                      
                /* Salir del menú */
                  salir = 1;    
                  break;
            default:
                /* la opción elegida no esta dentro de las indicadas */
                  printf("La opción elegida es incorrecta\n\n");
        }  
   }while (salir != 1);  

   return;
}

/*
 * Función Main 
 */
int main (void)
{
    int opcion = 0;
    int salir = 0;
    int leidos = 0;

    printf("Bienvenido a su agenda electrónica\n");
    do {
        /* Menú inicial de la agenda */
        printf("\n");
        printf("1.- Entrar en la agenda\n");
        printf("0.- Salir del programa\n");

        /* leer la opción con comprobación de errores */
        leidos = 0;
        while (leidos == 0) {
       leidos = scanf("%d", &opcion);
             if (leidos == 0) 
                 printf("Opción incorrecta\n");
        }

        switch(opcion) {
            case 0:
                salir = 1;
                break;
            case 1: 
                entrar();
                break;
            default:
                printf("La opción elegida es incorrecta\n");
        }
    } while(salir != 1);
    /* el programa acaba la ejecución */
    return(0);
}   

