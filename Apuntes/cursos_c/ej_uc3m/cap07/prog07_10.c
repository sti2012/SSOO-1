/*
 * Programa:    prog_07_10
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Menu principal de la agenda electronica
 */

#include <stdio.h>

/*
 * Se incluyen los archivos de cabecera de los m�dulos
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
        /* Mostrar el men� de opciones */
        printf("\n\nMen� de la Agenda:\n");
        printf("1.- Ver libro de direcciones\n");
        printf("2.- Ver notas diarias\n");
        printf("3.- Ver calendario\n");
        printf("4.- Ver citas y reuniones\n");
        printf("0.- Salir del programa\n\n");  
        printf ("Introduzca su opci�n: ");

        leidos = 0;
        while (leidos == 0) {
            leidos = scanf ("%i",&opcion);
            if (leidos == 0)
                printf("Opci�n incorrecta\n");
        }

        switch(opcion){
            case 1:
                /* aqu� ir� la gesti�n de libro de direcciones */
                   break;
            case 2:
                /* aqu� ir� la gesti�n de las notas */
                  break;
            case 3:
                /* aqu� ira el calendario */
                    break;
            case 4:      
                /* aqu� ir� la gesti�n del las citas y reuniones */
                  break;
            case 0:                      
                /* Salir del men� */
                  salir = 1;    
                  break;
            default:
                /* la opci�n elegida no esta dentro de las indicadas */
                  printf("La opci�n elegida es incorrecta\n\n");
        }  
   }while (salir != 1);  

   return;
}

/*
 * Funci�n Main 
 */
int main (void)
{
    int opcion = 0;
    int salir = 0;
    int leidos = 0;

    printf("Bienvenido a su agenda electr�nica\n");
    do {
        /* Men� inicial de la agenda */
        printf("\n");
        printf("1.- Entrar en la agenda\n");
        printf("0.- Salir del programa\n");

        /* leer la opci�n con comprobaci�n de errores */
        leidos = 0;
        while (leidos == 0) {
       leidos = scanf("%d", &opcion);
             if (leidos == 0) 
                 printf("Opci�n incorrecta\n");
        }

        switch(opcion) {
            case 0:
                salir = 1;
                break;
            case 1: 
                entrar();
                break;
            default:
                printf("La opci�n elegida es incorrecta\n");
        }
    } while(salir != 1);
    /* el programa acaba la ejecuci�n */
    return(0);
}   

