/* 
 *  Programa: Agenda Electronica
 *  Modulo: agenda.c
 *  Autor: Alberto Miedes
 *  Fecha: 20-06-2001
 *  Descripción- Módulo que contiene la función de inicio del programa.
 */

#include <stdio.h>

/* ...................... */

/* 
 *  Función: main 
 *  Módulo: agenda.c
 *  Autor: Alberto Miedes
 *  Parámetros entrada: no tiene
 *  Parámetros salida: no tiene
 *  Descripción: Muestra el menú de inicio de la agenda.
 */
int main()
{
    char tecla;
    int opcion;

    printf("Hola, soy su agenda electrónica\n");
    printf("Pulsa una tecla para ver un ejemplo\n");
    scanf("%c",&tecla);

    /*
     * Bucle principal con estructura do-while
     */
    do {
        printf("\nElija una opción:\n");
        printf("1.- Agenda individual\n");
        printf("2.- Agenda de grupo\n");
        printf("0.- Salir\n");
        scanf("%d",&opcion);

    /*
     * Sentencia if-else para seleccionar la opción dada
     */
        if (1 == opcion) {
            printf("Agenda individual\n");
        } else if (2 == opcion) { 
            printf("Agenda de grupos\n"); 	  
        }      
    } while (opcion!=0);         
         
    return(0);
}
