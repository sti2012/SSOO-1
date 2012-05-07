/*
 * Programa: agenda
 * Modulo  : dialogo_valor
 * Fichero : dialogo_valor.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "dialogo_valor.h"

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función dialogo_valor()
 */
void  dialogo_valor (char *mensaje, char *valor)
{
    char   *ret;

    /*
     * valor
     */
    printf(mensaje);
    fflush(stdout);
    do {
        ret=fgets(valor,1024,stdin);
        if ('\n' == valor[strlen(valor)-1]) {
            valor[strlen(valor)-1]='\0';
        }
    } while ( (!strcmp(valor,"\n")) || (!strcmp(valor,"")) ) ;
    printf("\n");
}


