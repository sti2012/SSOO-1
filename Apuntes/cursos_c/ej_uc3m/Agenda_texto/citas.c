/*
 * Programa: agenda
 * Modulo  : citas
 * Fichero : citas.c
 */

/*
 * FICHEROS INCLUDES
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include "citas.h"
#include "menu_citas.h"

/*
 * VARIABLES GLOBALES
 */

/* puntero a la lista de citas para poder utilizarlo desde el manejador */
ListaCitas *citasParaAvisar;

/*
 * PROTOTIPOS DE FUNCIONES PRIVADAS
 */

/* 
 * Funci�n: citaAvisar()
 */ 
void citaAvisar (int senyal);

/*
 * FUNCIONES PRIVADAS
 */

/* 
 * Funci�n: activarAlarma()
 * 
 * Par�metros de entrada:
 *      Cita * cita: Contiene la cita que va a activarse en el temporizador
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Activa una alarma asociada al momento de producirse la cita
 */
void activarAlarma (Cita *cita)
{
    time_t  ahora;
    double  faltan;
    int     alarma;

    /*
     *  Instalar alarma.
     */
    time(&ahora);
    faltan=difftime(cita->cuando,ahora);
    alarma=(int)(fabs(faltan));

    signal(SIGALRM,citaAvisar);
    alarm(alarma);
}

/* 
 * Funci�n: citaAvisar()
 * 
 * Par�metros de entrada:
 *      int senyal: Contiene el numero de se�al que desperto al manejador 
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Manejador a ejecutar para avisar de una cita inminente 
 */
void citaAvisar (int senyal)
{
    Cita *  cita;

    /* Mostrar aviso */
    avisarMenuCita();
    /* Instalar siguiente alarma */
    cita = (*citasParaAvisar);
    while ( (NULL != cita) && (0 != cita->cumplida) ) {
        cita=cita->resto;
    }
    if (NULL != cita) {
        cita->cumplida = 1;
        if (NULL != cita->resto) {
            activarAlarma(cita->resto);
        }
    }
}

/*
 * FUNCIONES PUBLICAS
 */


/* 
 * Funci�n: nuevaCita
 */
Cita * nuevaCita (char *motivo, 
                  int dia, int mes, int anyo, 
                  int hora, int minuto, int segundo)
{
    Cita      *pCitaTmp;
    char      *copiaMotivo;
    struct tm  instanteTm;

    /* 
     * Reserva memoria din�mica
     * para la estructura de gesti�n de cita
     * y para una copia del motivo
     */
    pCitaTmp=malloc(sizeof(Cita));
    if (NULL == pCitaTmp) {
        perror("malloc:");
        return NULL;
    }
    copiaMotivo=malloc(strlen(motivo)+1);
    if (NULL == copiaMotivo) {
        perror("malloc:");
        return NULL;
    }
    strcpy(copiaMotivo,motivo);

    /* 
     * Conversi�n a 'struct tm'
     */
    instanteTm.tm_hour=hora;
    instanteTm.tm_min=minuto;
    instanteTm.tm_sec=segundo;
    instanteTm.tm_mday=dia;
    instanteTm.tm_mon=mes-1;
    instanteTm.tm_year=anyo-1900;
    instanteTm.tm_wday=0;
    instanteTm.tm_yday=0;
    instanteTm.tm_isdst=-1;

    /*
     * Almacena los valores.
     */
    pCitaTmp->motivo=copiaMotivo;
    pCitaTmp->cuando=mktime(&instanteTm);
    pCitaTmp->resto=NULL;

    return (pCitaTmp);
}

/* 
 * Funci�n: destruirCita
 */
void destruirCita (Cita *cita)
{
    /*
     *  Libera la memoria asociada
     *  al motivo
     */
    free(cita->motivo);

    /*
     * Libera la memoria para
     * la estructura de gesti�n de cita
     */
    free(cita);
}

/* 
 * Funci�n: datosCita
 */
void datosCita (Cita cita, int *dia, int *mes, int *anyo, 
                int *hora, int *minuto, int *segundo,
                int *cumplido, char** motivo)
{
    struct tm  *instanteTm;

    /* 
     * Conversi�n de time_t a struct tm
     */
    instanteTm = localtime(&(cita.cuando));

    (*hora) = instanteTm->tm_hour;
    (*minuto) = instanteTm->tm_min;
    (*segundo) = instanteTm->tm_sec;
    (*dia) = instanteTm->tm_mday;
    (*mes) = instanteTm->tm_mon + 1;
    (*anyo) = instanteTm->tm_year + 1900;

    (*cumplido) = cita.cumplida;
    (*motivo) = cita.motivo;
}

/* 
 * Funci�n: iniciarListaCitas
 */
void    iniciarListaCitas (ListaCitas *citas)
{
    (*citas)=NULL;
}

/* 
 * Funci�n: destruirListaCitas
 */
void destruirListaCitas (ListaCitas *citas)
{
    Cita  *citaI, *citaFin;

    /*
     *  Libera la memoria de cada cita
     */
    citaI = (*citas);
    while (NULL != citaI) {
        citaFin=citaI;
        citaI=citaI->resto;
        destruirCita(citaFin);
    }

    (*citas)=NULL;
}

/* 
 * Funci�n: primeraListaCitas
 */
Cita * primeraListaCitas (ListaCitas  citas)
{
    return (citas);
}

/* 
 * Funci�n: restoListaCitas
 */
ListaCitas  restoListaCitas (ListaCitas  citas)
{
    return (citas->resto);
}

/* 
 * Funci�n: insertarListaCitas
 */
void insertarListaCitas (ListaCitas *citas, Cita *cita)
{
    Cita   *citaI, *citaJ;

    /* 
     * Ver si est� cumplida
     */
    if (0.0 < difftime(cita->cuando,time(NULL))) {
        cita->cumplida = 0;
    } else {
        cita->cumplida = 1;
    }
    /*
     *  Buscar punto de insercci�n.
     */
    if (NULL == (*citas)) {
        (*citas)=cita;
    } else {
        citaI=(*citas);
        citaJ=citaI->resto;
        while ( (NULL != citaJ) && (difftime(cita->cuando,citaJ->cuando)>0.0) ){
            citaI=citaJ;
            citaJ=citaJ->resto;
        }
        cita->resto=citaJ;
        citaI->resto=cita;
    }

    /*
     *  Instalar alarma.
     */
    citaJ = (*citas);
    while ( (NULL != citaJ) && (0 != citaJ->cumplida) ) {
        citaJ=citaJ->resto;
    }
    if (NULL != citaJ) {
        activarAlarma(citaJ);
    }
    citasParaAvisar = citas;
}

/* 
 * Funci�n: borrarListaCitas
 */
void borrarListaCitas (ListaCitas *citas, Cita *cita)
{
    Cita *citaI, *citaJ;

    /* lista vac�a */
    if (NULL == (*citas)) {
        return;
    } 

    /* primero en la lista */
    if (cita == (*citas)) {
        citaI=(*citas);
        citaJ=citaI->resto;
        (*citas)=citaJ;
        if (NULL != citaJ) {
            activarAlarma(citaJ);
        }
        destruirCita(cita);
        return;
    }

    /*
     *  Buscar cita.
     */
    citaI=(*citas);
    citaJ=citaI->resto;
    while (NULL != citaJ) {
        /* sacar de la lista y destruir cita */
        if (cita == citaJ) {
                citaI->resto=citaJ->resto;
                destruirCita(cita);
            return;
        }
        /* continuar la b�squeda */
        citaI=citaJ;
        citaJ=citaJ->resto;
    }
}

/*
 * Funci�n: numeroListaCitas
 */
int numeroListaCitas (ListaCitas citas)
{
    int cont = 0;
    ListaCitas auxCitas = citas;
    
    /*
     * Calcular el n�mero de posiciones
     */
    while (NULL != auxCitas) {  
        auxCitas = auxCitas->resto;
        cont = cont + 1;
    }
    return (cont);

}

/*
 * Funci�n: escribirArchivoListaCitas
 */
int escribirArchivoListaCitas (const ListaCitas *citas, char *archivo)
{

    FILE *desc;
    struct tm  *instanteTm;
    ListaCitas auxCitas = (*citas);
    Cita *cita;

    desc = fopen(archivo, "w");
    if (NULL == desc) {
        perror("fopen: ");
        return (-1);
    }

    while (NULL != auxCitas) {
        cita = primeraListaCitas(auxCitas);
        auxCitas = restoListaCitas(auxCitas);
        instanteTm = localtime(&(cita->cuando));
        fprintf(desc," Dia: %i Mes: %i, A�o: %i Hora: %i Minuto: %i Segundo: %i Motivo: %s\n",instanteTm->tm_mday,instanteTm->tm_mon+1,                                       instanteTm->tm_year+1900,instanteTm->tm_hour,
              instanteTm->tm_min,instanteTm->tm_sec,  
              cita->motivo);
    }
    fclose(desc);
    return (0);
}

/*
 * Funci�n: leerArchivoListaCitas
 */
int leerArchivoListaCitas(ListaCitas *citas, char *archivo)
{

    FILE *desc;
    char motivo[CITA_MAX] = "";
    struct tm  instanteTm;
    Cita *cita;
    desc = fopen(archivo, "r");
    if (NULL == desc) {
        perror("fopen: ");
        return (-1);
    }
    while (0 == feof(desc)) {
        fscanf(desc," Dia: %i Mes: %i, A�o: %i Hora: %i Minuto: %i Segundo: %i",
                                &(instanteTm.tm_mday),&(instanteTm.tm_mon),
                                &(instanteTm.tm_year),&(instanteTm.tm_hour),
                                &(instanteTm.tm_min),&(instanteTm.tm_sec));
        fscanf(desc," Motivo: ");
        fgets(motivo,CITA_MAX,desc);
        if ('\n' == motivo[strlen(motivo)-1]) {
            motivo[strlen(motivo)-1]='\0';
        }
        if (0 == feof(desc)) {
            cita=nuevaCita(motivo,instanteTm.tm_mday,instanteTm.tm_mon,
                              instanteTm.tm_year,instanteTm.tm_hour,
                              instanteTm.tm_min,instanteTm.tm_sec);
            insertarListaCitas(citas,cita);
        }
        fscanf(desc,"\n");
    }
    fclose(desc);
    return (0);
}

