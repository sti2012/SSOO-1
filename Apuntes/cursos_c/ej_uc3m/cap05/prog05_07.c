/* 
 *  Programa: Agenda Electronica
 *  Modulo: agenda.c
 *  Autor: Alberto Miedes
 *  Fecha: 20-06-2001
 *  Descripci�n- M�dulo que contiene la funci�n de inicio del programa.
 */

#include <stdio.h>

/* ...................... */

/* 
 *  Funci�n: main 
 *  M�dulo: agenda.c
 *  Autor: Alberto Miedes
 *  Par�metros entrada: no tiene
 *  Par�metros salida: no tiene
 *  Descripci�n: Muestra el men� de inicio de la agenda.
 */
int main()
{
    char tecla;
    int opcion;

    printf("Hola, soy su agenda electr�nica\n");
    printf("Pulsa una tecla para ver un ejemplo\n");
    scanf("%c",&tecla);

    /*
     * Bucle principal con estructura do-while
     */
    do {
        printf("\nElija una opci�n:\n");
        printf("1.- Agenda individual\n");
        printf("2.- Agenda de grupo\n");
        printf("0.- Salir\n");
        scanf("%d",&opcion);

    /*
     * Sentencia if-else para seleccionar la opci�n dada
     */
        if (1 == opcion) {
            printf("Agenda individual\n");
        } else if (2 == opcion) { 
            printf("Agenda de grupos\n"); 	  
        }      
    } while (opcion!=0);         
         
    return(0);
}
