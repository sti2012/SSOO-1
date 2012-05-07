/*
 * Programa: agenda
 * Modulo  : dialogo_fecha
 * Fichero : dialogo_fecha.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "dialogo_fecha.h"


/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función dialogo_fecha()
 */
time_t dialogo_fecha (void)
{
    char       cuando[1024];
    time_t     instante;
    struct tm  instanteTm;
    char      *ret;

    /*
     * cita->cuando
     */
    printf("El formato es:\n");
    printf("\n");
    printf("  hora minuto segundo Dia  Mes  Año\n");
    printf("  ---- ------ ------- ---  ---  ---\n");
    printf("  0-23 0-59   0-59    1-31 1-12 1900-\n");
    printf("\n");
    printf("Introduzca cuando será la cita:\n");
    fflush(stdout);
    do {
        ret=fgets(cuando,1024,stdin);
    } while ( (!strcmp(cuando,"\n")) || (!strcmp(cuando,"")) ) ;
    printf("\n");

    /*
     * Insercción...
     */
    sscanf(cuando,"%d %d %d %d %d %d",
           &(instanteTm.tm_hour),
           &(instanteTm.tm_min),
           &(instanteTm.tm_sec),
           &(instanteTm.tm_mday),
           &(instanteTm.tm_mon),
           &(instanteTm.tm_year));
    instanteTm.tm_wday=0;
    instanteTm.tm_yday=0;
    instanteTm.tm_isdst=-1;
    instanteTm.tm_mon=instanteTm.tm_mon-1;
    instanteTm.tm_year=instanteTm.tm_year-1900;

    instante=mktime(&instanteTm);
    return (instante);
}


