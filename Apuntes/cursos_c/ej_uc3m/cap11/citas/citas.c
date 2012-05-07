/* 
 * Programa:    citas
 * Fichero:     citas.c
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 11:
 *              Implementaci�n del m�dulo citas utilizando 
 *              una estructura autoreferenciada
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <unistd.h>
#include "citas.h"

/*
 * Variables globales
 */

/* puntero a la lista de citas para poder utilizarlo desde el manejador */
ListaCitas *citasParaAvisar;


/* 
 * Funci�n citaAvisar
 * manejador a ejecutar para avisar de una cita inminente 
 */
void citaAvisar (int senyal)
{
	char   *pAhora;
	time_t  ahora;
        Cita *  citaJ;

	time(&ahora);
	pAhora=ctime(&ahora);

	printf("\n\n");
	printf(" *** CITAS ********************************************\n");
	printf(" *                                                    *\n");
	printf(" * Tiene una cita pendiente.                          *\n");
	printf(" * Consulte su agenda.                                *\n");
	printf(" ->  %-25.25s",pAhora);
	printf(" *                                                    *\n");
	printf(" ******************************************************\n");
	printf("\n\n");

        /*
	 *  Instalar alarma.
	 */
        citaJ = (*citasParaAvisar);
	while ( (NULL != citaJ) && (0 != citaJ->cumplida) ) {
	    citaJ=citaJ->resto;
	}
        if (NULL != citaJ) {
            citaJ->cumplida = 1;
            if (NULL != citaJ->resto) {
                activarAlarma(citaJ->resto);
            }
        }
}

/* 
 * Funci�n activarAlarma
 * activa una alarma asociada a la momento de producirse la cita 
 */
int activarAlarma (Cita *cita)
{
	time_t  ahora;
	double  faltan;
	int     alarma;
	int     err;

	/*
	 *  Instalar alarma.
	 */
	time(&ahora);
	faltan=difftime(cita->cuando,ahora);
	alarma=(int)(fabs(faltan));

	signal(SIGALRM,citaAvisar);
	err=alarm(alarma);

	/*
	 *  Fin.
	 */
	return err;
}

/* 
 * Funci�n nuevaCita
 * Crea una nueva cita 
 */
Cita   *nuevaCita (char *motivo, 
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
	if (NULL==pCitaTmp) {
		perror("malloc:");
		return NULL;
	}
	copiaMotivo=malloc(strlen(motivo)+1);
	if (NULL==copiaMotivo) {
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
	instanteTm.tm_isdst=0;

	/*
	 * Almacena los valores.
	 */
	pCitaTmp->motivo=copiaMotivo;
	pCitaTmp->cuando=mktime(&instanteTm);
	pCitaTmp->resto=NULL;

	return (pCitaTmp);
}

/* 
 * Funci�n destruirCita
 * Destruye una cita 
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
 * Funci�n iniciarListaCitas
 * Inicia la lista de citas 
 */
void    iniciarListaCitas (ListaCitas *citas)
{
	(*citas)=NULL;
}

/* 
 * destruirListaCitas
 * Destruye la lista de citas 
 */
void    destruirListaCitas (ListaCitas *citas)
{
	Cita   *citaI, *citaFin;

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
 * primeraCita
 * Devuelve la primera cita 
 */
Cita *      primeraCita    (ListaCitas  citas)
{
	return (citas);
}

/* 
 * restoCitas
 * Devuelve el resto de citas 
 */
ListaCitas  restoCitas     (ListaCitas  citas)
{
	return (citas->resto);
}

/* 
 * insertarCitas
 * Inserta una nueva cita 
 */
void        insertarCitas  (ListaCitas *citas, Cita *cita)
{
	Cita   *citaI, *citaJ;

        /* 
         * Ver si est� cumplida
         */
        if (difftime(cita->cuando,time(NULL)) > 0.0) {
            cita->cumplida = 0;
        } else {
            cita->cumplida = 1;
        }
	/*
	 *  Buscar punto de insercci�n.
	 */
	if (NULL == (*citas)) {
		(*citas)=cita;
	} 
	else {
		citaI=(*citas);
		citaJ=citaI->resto;
		while ( (NULL != citaJ) && (difftime(cita->cuando,citaJ->cuando)>0.0) ) {
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
 * borrarCitas
 * Borra una cita de la lista 
 * */
void        borrarCitas    (ListaCitas *citas, Cita *cita)
{
	Cita   *citaI, *citaJ;

	/* lista vac�a */
	if (NULL == (*citas)) {
		return;
	} 

	/* primero en la lista */
	if (cita == (*citas)) {
		citaI=(*citas);
		citaJ=citaI->resto;
		(*citas)=citaJ;
		if (NULL!=citaJ) {
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
 * Funci�n numeroCitas
 */
int numeroCitas (ListaCitas citas)
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
