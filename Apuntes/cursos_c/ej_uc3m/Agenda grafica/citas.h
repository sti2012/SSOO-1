/*
 * Programa: agenda
 * Modulo  : citas
 * Fichero : citas.h
 */
#ifndef _CITAS_H_
#define _CITAS_H_

/*
 * FICHEROS INCLUDES
 */
#include <time.h>
#include <string.h>


/*
 * CONSTANTES
 */

#define CITA_MAX    1024


/*
 * TIPOS DE DATOS
 */

typedef struct InfoCita * ListaCitas;
typedef struct InfoCita   Cita;

struct InfoCita
{
    char *     motivo;
    time_t     cuando;
    int        cumplida;
    ListaCitas resto;
};


/*
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/* 
 * Funci�n: nuevaCita()
 * 
 * Par�metros de entrada:
 *      char * motivo: Motivo de la cita
 *      int dia:       dia de la cita
 *      int mes:       mes de la cita
 *      int anyo:      a�o de la cita
 *      int hora:      hora de la cita
 *      int minuto:    minuto de la cita
 *      int segundo:   segundo de la cita
 *      
 * Par�metros de salida:
 *      Devuelve un puntero a la cita creada (Cita *)
 *
 * Descripci�n: 
 *      Crea una nueva cita
 */
Cita *  nuevaCita (char *motivo,
                   int dia, int mes, int anyo,
		   int hora, int minuto, int segundo);

/* 
 * Funci�n: destruirCita()
 * 
 * Par�metros de entrada:
 *      Cita * cita:   Cita a destruir
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Destruye una cita
 */
void destruirCita       (Cita *cita);

/* 
 * Funci�n: datosCita()
 * 
 * Par�metros de entrada:
 *      Cita cita: La cita de la cual se extraeran los datos
 *      
 * Par�metros de salida:
 *      int * dia:       dia de la cita
 *      int * mes:       mes de la cita
 *      int * anyo:      a�o de la cita
 *      int * hora:      hora de la cita
 *      int * minuto:    minuto de la cita
 *      int * segundo:   segundo de la cita
 *      int * cumplido:  1 si la cita ya paso, 0 si no
 *      char ** motivo:  Motivo de la cita
 *
 * Descripci�n: 
 *      Extrae los datos que componen una cita
 */
void datosCita (Cita cita, int *dia, int *mes, int *anyo, 
                int *hora, int *minuto, int *segundo,
                int *cumplido, char** motivo);

/* 
 * Funci�n: iniciarListaCitas()
 * 
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      listaCitas * citas: Lista de citas iniciada
 *
 * Descripci�n: 
 *      Inicia la lista de citas
 */
void iniciarListaCitas  (ListaCitas *citas);

/* 
 * Funci�n: destruirListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista de citas a destruir
 *      
 * Par�metros de salida:
 *      listaCitas * citas: Lista de citas destruida
 *
 * Descripci�n: 
 *      Destruye la lista de citas
 */
void destruirListaCitas (ListaCitas *citas);

/* 
 * Funci�n: primeraListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      
 * Par�metros de salida:
 *      Devuelve un puntero a la primera cita (Cita *)
 *
 * Descripci�n: 
 *      Devuelve la primera cita
 */
Cita * primeraListaCitas    (ListaCitas  citas);

/* 
 * Funci�n: restoListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      
 * Par�metros de salida:
 *      Devuelve una lista con el resto de citas (ListaCitas)
 *
 * Descripci�n: 
 *      Devuelve el resto de citas
 */
ListaCitas  restoListaCitas     (ListaCitas  citas);

/* 
 * Funci�n: insertarListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      Cita * cita: Cita a insertar
 *      
 * Par�metros de salida:
 *      listaCitas * citas: Lista final con la cita insertada
 *
 * Descripci�n: 
 *      Inserta una nueva cita
 */
void insertarListaCitas  (ListaCitas *citas, Cita *cita);

/* 
 * Funci�n: borrarListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      Cita * cita: Cita a borrar
 *      
 * Par�metros de salida:
 *      listaCitas * citas: Lista final con la cita borrada
 *
 * Descripci�n: 
 *      Borra una cita de la lista
 */
void borrarListaCitas    (ListaCitas *citas, Cita *cita);

/* 
 * Funci�n: numeroListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      
 * Par�metros de salida:
 *      Devuelve el numero de citas de la lista
 *
 * Descripci�n: 
 *      Calcula el n�mero de citas
 */
int numeroListaCitas (ListaCitas citas);

/* 
 * Funci�n: escribirArchivoListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      char * archivo: Nombre del archivo donde escribir
 *      
 * Par�metros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      Vuelca las citas en un fichero 
 */
int escribirArchivoListaCitas (const ListaCitas *citas, char *archivo);


/* 
 * Funci�n: leerArchivoListaCitas()
 * 
 * Par�metros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      char * archivo: Nombre del archivo donde leer
 *      
 * Par�metros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      Recoge las citas de un fichero
 */
int leerArchivoListaCitas(ListaCitas *citas, char *archivo);

#endif /* _CITAS_H_ */

