/*
 * Programa: agenda
 * Modulo  : menu_citas
 * Fichero : menu_citas.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_citas.h"


/*
 * FUNCIONES PRIVADAS
 */

/*
 * Funci�n listarMenuCitas()
 *
 * Par�metros de entrada:
 *      ListaCitas * citas: Lista de citas global de la agenda
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Lista las citas de la lista     
 */
void listarMenuCitas (ListaCitas *citas)
{
    int n;
    char  *pAhora;
    Cita  *cita;
    ListaCitas auxCitas = *(citas);
        

    n=numeroListaCitas(auxCitas);
    if (0==n) {
        printf("<vac�a>\n");
        return;
    }

    cita=primeraListaCitas(auxCitas);
    while (NULL != cita) {
        pAhora=cTime(&(cita->cuando));
        printf("[%s] ", pAhora);
        if (cita->cumplida) {
            printf("[X] ");
        } else {
            printf("[ ] ");
        }
        printf("%s\n", cita->motivo);
        auxCitas=restoListaCitas(auxCitas);
        cita=primeraListaCitas(auxCitas);
    };

    printf("\n");
}

/*
 * Funci�n insertarMenuCitas()
 *
 * Par�metros de entrada:
 *      ListaCitas * citas: Lista de citas global de la agenda
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      inserta una cita en la lista de citas
 */
void insertarMenuCitas (ListaCitas *citas)
{
    Cita *cita;
    char    motivo[1024];
    time_t  instante;
    struct tm  *instanteTm;

    /*
     * leer valores
     */
    dialogo_valor("Introduzca el motivo de la cita:\n",motivo);
    instante=dialogo_fecha();
    instanteTm = localtime(&instante);

    /*
     * insertar nueva cita
     */
    cita=nuevaCita(motivo,instanteTm->tm_mday,instanteTm->tm_mon+1,
                              instanteTm->tm_year+1900,instanteTm->tm_hour,
                              instanteTm->tm_min,instanteTm->tm_sec);
    insertarListaCitas(citas,cita);
}

/*
 * Funci�n borrarMenuCitas()
 *
 * Par�metros de entrada:
 *      ListaCitas * citas: Lista de citas global de la agenda
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      borra una cita de la lista de citas
 */
void borrarMenuCitas (ListaCitas *citas)
{
    time_t  instante;
    int n;
    Cita *cita;
    ListaCitas auxCitas = *(citas);

    /*
     * leer valores
     */
    instante=dialogo_fecha();

    /*
     * buscar cita
     */
    n=numeroListaCitas(auxCitas);
    if (0==n) {
        return;
    }
    cita=primeraListaCitas(auxCitas);
    while ( (NULL != cita) && (instante != cita->cuando) ) {
        auxCitas=restoListaCitas(auxCitas);
        cita=primeraListaCitas(auxCitas);
    };

    /*
     * si est'a, borrar
     */
    if (NULL!=cita) {
        borrarListaCitas(citas,cita);
    }
}

/*
 * FUNCIONES P�BLICAS
 */

/*
 * Funci�n avisarMenuCita
 */
void avisarMenuCita (void)
{
    char   *pAhora;
    time_t  ahora;

    time(&ahora);
    pAhora=cTime(&ahora);

    printf("\n\n");
    printf(" *** CITAS ********************************************\n");
    printf(" *                                                    *\n");
    printf(" * Tiene una cita pendiente.                          *\n");
    printf(" * Consulte su agenda.                                *\n");
    printf(" * %-50.50s *\n",pAhora);
    printf(" *                                                    *\n");
    printf(" ******************************************************\n");
    printf("\n\n");
}

/*
 * Funci�n menuCitas
 */
void menuCitas (ListaCitas *citas)
{
    int opcion;
    int final = 0;

    do{         
        /* Mostrar el menu de opciones */
        opcion = -1;
        printf("\n");
        printf("Citas\n");
        printf("-----\n");
        printf("\n");
        printf(" 1.- Listar las citas\n");
        printf(" 2.- Insertar una cita\n");
        printf(" 3.- Borrar una cita\n");
        printf(" 0.- Volver al men� anterior\n\n");
        printf("\n");
        printf("\n");
        printf(" Introduzca su opci�n: ");
        fflush(stdout);
        scanf ("%d",&opcion);

        switch(opcion){
        case 1:
            /* Listar las citas */
            listarMenuCitas(citas);
            break;
        case 2: 
            /* Insertar una nota */
            insertarMenuCitas(citas);
            break;
        case 3:
            /* Borrar una nota */
            borrarMenuCitas(citas);
            break;
        case 0:
            /* Salir del menu */
            final=1;
            break;
        default:
            /* la opci�n elegida no esta dentro de las indicadas */
            printf("La opcion elegida es incorrecta\n\n");
        }  
   }while (0 == final);  
}

