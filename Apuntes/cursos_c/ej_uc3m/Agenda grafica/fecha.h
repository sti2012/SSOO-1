/*
 * Programa: agenda
 * Modulo  : fecha
 * Fichero : fecha.h
 */
#ifndef _FECHA_H_
#define _FECHA_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"


/*
 *  CONSTANTES
 */
#define ANYO_BASE 1800
#define DIAS_SEMANA 7
#define DIAS_ANYO 365


/*
 * TIPOS DE DATOS 
 */
enum DiasSemana { lunes, martes, miercoles, jueves, viernes, sabado, domingo};
enum MesesAnyo { enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre };


struct Fecha
{
    int anyo; 
    int mes;  
    int dia;
};

typedef enum DiasSemana TipoDia;
typedef enum MesesAnyo TipoMes;
typedef struct Fecha TipoFecha;


/*
 * PROTOTIPOS DE FUNCIONES PÚBLICAS
 */

/* 
 * Función: obtenerFechaActual()
 * 
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      Devuelve la fecha actual (TipoFecha)
 *
 * Descripción: 
 *      Devuelve la fecha actual
 */
TipoFecha obtenerFechaActual();

/* 
 * Función: componerFecha()
 * 
 * Parámetros de entrada:
 *      int dia:       dia de la fecha
 *      int mes:       mes de la fecha
 *      int anyo:      año de la fecha
 *      
 * Parámetros de salida:
 *      TipoFecha * fecha: Fecha compuesta
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Compone una nueva fecha a partir del dia, mes y año
 */
int componerFecha (int dia, int mes, int anyo, TipoFecha *fecha);

/* 
 * Función: obtenerDia()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha compuesta
 *      
 * Parámetros de salida:
 *      Devuelve el dia correspondiente a la Fecha (int)
 *
 * Descripción: 
 *      Devuelve el dia correspondiente a la fecha 
 */
int obtenerDia (TipoFecha fecha);

/* 
 * Función: obtenerMes()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha compuesta
 *      
 * Parámetros de salida:
 *      Devuelve el mes correspondiente a la Fecha (int)
 *
 * Descripción: 
 *      Devuelve el mes correspondiente a la fecha 
 */
int obtenerMes (TipoFecha fecha);

/* 
 * Función: obtenerAnyo()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha compuesta
 *      
 * Parámetros de salida:
 *      Devuelve el año correspondiente a la Fecha (int)
 *
 * Descripción: 
 *      Devuelve el año correspondiente a la fecha 
 */
int obtenerAnyo (TipoFecha fecha);

/* 
 * Función: decrementarMes()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int meses: numero de meses a decrementar
 *      
 * Parámetros de salida:
 *      TipoFecha * fecha: Fecha decrementada
 *
 * Descripción: 
 *      Devuelve la fecha con los meses decrementados
 */
void decrementarMes (TipoFecha *fecha, int meses);

/* 
 * Función: incrementarMes()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int meses: numero de meses a incrementar
 *      
 * Parámetros de salida:
 *      TipoFecha * fecha: Fecha incrementada
 *
 * Descripción: 
 *      Devuelve la fecha con los meses incrementados
 */
void incrementarMes (TipoFecha *fecha, int meses);

/* 
 * Función: decrementarAnyo()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int anyos: numero de años a decrementar
 *      
 * Parámetros de salida:
 *      TipoFecha * fecha: Fecha decrementada
 *
 * Descripción: 
 *      Devuelve la fecha con los años decrementados
 */
void decrementarAnyo (TipoFecha *fecha, int anyos);

/* 
 * Función: incrementarAnyo()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int anyos: numero de años a incrementar
 *      
 * Parámetros de salida:
 *      TipoFecha * fecha: Fecha incrementada
 *
 * Descripción: 
 *      Devuelve la fecha con los años incrementados
 */
void incrementarAnyo (TipoFecha *fecha, int anyos);

/* 
 * Función: obtenerDiasMes()
 * 
 * Parámetros de entrada:
 *      int mes: mes correspondiente
 *      int anyo: año correspondiente
 *      
 * Parámetros de salida:
 *      Devuelve el numero de dias de un mes en un año correspondiente (int)
 *
 * Descripción: 
 *      Calcula el numero de dias de un mes en un año correspondiente
 */
int obtenerDiasMes (int mes, int anyo);

/* 
 * Función: obtenerNombreMes()
 * 
 * Parámetros de entrada:
 *      int mes: mes correspondiente
 *      
 * Parámetros de salida:
 *      char nombreMes[]: nombre del mes
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripción: 
 *      Devuelve el nombre de un mes
 */
int obtenerNombreMes (int mes, char nombreMes[]);

/* 
 * Función: obtenerDiaSemana()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      
 * Parámetros de salida:
 *      Devuelve el numero de dia de la semana que corresponde (int)
 *          (1=lunes; 7=Domingo)
 *
 * Descripción: 
 *      Devuelve el numero de dia de la semana que corresponde con esa fecha
 */
int obtenerDiaSemana (TipoFecha fecha);

/* 
 * Función: obtenerDiaSemanaPrimerodeMes()
 * 
 * Parámetros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      
 * Parámetros de salida:
 *      Devuelve el numero de dia de la semana que corresponde (int)
 *          (1=lunes; 7=Domingo)
 *
 * Descripción: 
 *      Devuelve el numero de dia de la semana que corresponde con el 1º de mes
 *      de la fecha que se suministra
 */
int obtenerDiaSemanaPrimerodeMes(TipoFecha fecha);

/* 
 * Función: obtenerDiaSemanaPrimerodeEnero()
 * 
 * Parámetros de entrada:
 *      int anyo: año correspondiente
 *      
 * Parámetros de salida:
 *      Devuelve el numero de dia de la semana que corresponde (int)
 *          (1=lunes; 7=Domingo)
 *
 * Descripción: 
 *      Devuelve el numero de dia de la semana que corresponde con el 1º de
 *      Enero del año suministrado
 */
int obtenerDiaSemanaPrimerodeEnero(int anyo);

/* 
 * Función: bisiesto()
 * 
 * Parámetros de entrada:
 *      int anyo: año correspondiente
 *      
 * Parámetros de salida:
 *      Devuelve 1 si año bisiesto, 0 si no
 *
 * Descripción: 
 *      Calcula si un año es bisiesto
 */
int bisiestos(int anyo);

/* 
 * Función: totalBisiestos()
 * 
 * Parámetros de entrada:
 *      int anyo: año correspondiente
 *      
 * Parámetros de salida:
 *      Devuelve el numero de años bisiestos
 *
 * Descripción: 
 *      Devuelve el numero de años bisiestos que hay entre ANYO_BASE (1800) 
 *      y el año suministrado
 */
int totalBisiestos(int anyo);




#endif /* _FECHA_H_ */
