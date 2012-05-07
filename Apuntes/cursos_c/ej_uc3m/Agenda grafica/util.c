/*
 * Programa: agenda
 * Modulo  : util
 * Fichero : util.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "util.h"

/*
 * FUNCIONES PúBLICAS
 */

/*
 * Función stringDup
 */
char *stringDup ( char *mensaje )
{
    char *copia;
 
    /*
     *  Reserva memoria.
     */
    copia=malloc(strlen(mensaje) + 1);
    if (NULL == copia) {
        perror("malloc");
        return NULL;
    }
 
    /*
     *  Devuelve la copia.
     */
    strcpy(copia,mensaje);
    return copia;
}

/*
 * Función cTime
 */
char *cTime (time_t *ahora)
{
    char   *pAhora, *pch;

    pAhora=ctime(ahora);
    pch=strrchr(pAhora,'\n');
    if (NULL != pch) {
        *pch='\0';
    }
    return pAhora;
}

