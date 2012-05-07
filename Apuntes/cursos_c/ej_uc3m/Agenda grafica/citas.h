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
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/* 
 * Función: nuevaCita()
 * 
 * Parámetros de entrada:
 *      char * motivo: Motivo de la cita
 *      int dia:       dia de la cita
 *      int mes:       mes de la cita
 *      int anyo:      año de la cita
 *      int hora:      hora de la cita
 *      int minuto:    minuto de la cita
 *      int segundo:   segundo de la cita
 *      
 * Parámetros de salida:
 *      Devuelve un puntero a la cita creada (Cita *)
 *
 * Descripción: 
 *      Crea una nueva cita
 */
Cita *  nuevaCita (char *motivo,
                   int dia, int mes, int anyo,
		   int hora, int minuto, int segundo);

/* 
 * Función: destruirCita()
 * 
 * Parámetros de entrada:
 *      Cita * cita:   Cita a destruir
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Destruye una cita
 */
void destruirCita       (Cita *cita);

/* 
 * Función: datosCita()
 * 
 * Parámetros de entrada:
 *      Cita cita: La cita de la cual se extraeran los datos
 *      
 * Parámetros de salida:
 *      int * dia:       dia de la cita
 *      int * mes:       mes de la cita
 *      int * anyo:      año de la cita
 *      int * hora:      hora de la cita
 *      int * minuto:    minuto de la cita
 *      int * segundo:   segundo de la cita
 *      int * cumplido:  1 si la cita ya paso, 0 si no
 *      char ** motivo:  Motivo de la cita
 *
 * Descripción: 
 *      Extrae los datos que componen una cita
 */
void datosCita (Cita cita, int *dia, int *mes, int *anyo, 
                int *hora, int *minuto, int *segundo,
                int *cumplido, char** motivo);

/* 
 * Función: iniciarListaCitas()
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      listaCitas * citas: Lista de citas iniciada
 *
 * Descripción: 
 *      Inicia la lista de citas
 */
void iniciarListaCitas  (ListaCitas *citas);

/* 
 * Función: destruirListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista de citas a destruir
 *      
 * Parámetros de salida:
 *      listaCitas * citas: Lista de citas destruida
 *
 * Descripción: 
 *      Destruye la lista de citas
 */
void destruirListaCitas (ListaCitas *citas);

/* 
 * Función: primeraListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      
 * Parámetros de salida:
 *      Devuelve un puntero a la primera cita (Cita *)
 *
 * Descripción: 
 *      Devuelve la primera cita
 */
Cita * primeraListaCitas    (ListaCitas  citas);

/* 
 * Función: restoListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      
 * Parámetros de salida:
 *      Devuelve una lista con el resto de citas (ListaCitas)
 *
 * Descripción: 
 *      Devuelve el resto de citas
 */
ListaCitas  restoListaCitas     (ListaCitas  citas);

/* 
 * Función: insertarListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      Cita * cita: Cita a insertar
 *      
 * Parámetros de salida:
 *      listaCitas * citas: Lista final con la cita insertada
 *
 * Descripción: 
 *      Inserta una nueva cita
 */
void insertarListaCitas  (ListaCitas *citas, Cita *cita);

/* 
 * Función: borrarListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      Cita * cita: Cita a borrar
 *      
 * Parámetros de salida:
 *      listaCitas * citas: Lista final con la cita borrada
 *
 * Descripción: 
 *      Borra una cita de la lista
 */
void borrarListaCitas    (ListaCitas *citas, Cita *cita);

/* 
 * Función: numeroListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      
 * Parámetros de salida:
 *      Devuelve el numero de citas de la lista
 *
 * Descripción: 
 *      Calcula el número de citas
 */
int numeroListaCitas (ListaCitas citas);

/* 
 * Función: escribirArchivoListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      char * archivo: Nombre del archivo donde escribir
 *      
 * Parámetros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Vuelca las citas en un fichero 
 */
int escribirArchivoListaCitas (const ListaCitas *citas, char *archivo);


/* 
 * Función: leerArchivoListaCitas()
 * 
 * Parámetros de entrada:
 *      listaCitas * citas: Lista con las citas
 *      char * archivo: Nombre del archivo donde leer
 *      
 * Parámetros de salida:
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Recoge las citas de un fichero
 */
int leerArchivoListaCitas(ListaCitas *citas, char *archivo);

#endif /* _CITAS_H_ */

